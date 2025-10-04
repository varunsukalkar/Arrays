import os
from typing import List

from dotenv import load_dotenv

# Prefer new splitters package; gracefully fall back if unavailable
try:
    from langchain_text_splitters import RecursiveCharacterTextSplitter
except Exception:  # pragma: no cover - fallback for environments without splitters package
    from langchain.text_splitter import RecursiveCharacterTextSplitter  # type: ignore

from langchain.chains import RetrievalQA
from langchain_huggingface import (
    HuggingFaceEmbeddings,
    HuggingFaceEndpoint,
)
from langchain_chroma import Chroma


def require_env(var_name: str) -> str:
    value = os.getenv(var_name)
    if not value:
        raise ValueError(
            f"Environment variable {var_name} is required. Set it in your .env file."
        )
    return value


def read_college_info(file_path: str) -> str:
    if not os.path.exists(file_path):
        raise FileNotFoundError(
            f"Data file '{file_path}' not found. Create it or adjust the path."
        )
    with open(file_path, "r", encoding="utf-8") as f:
        return f.read()


def split_text(text: str, chunk_size: int = 500, chunk_overlap: int = 100) -> List[str]:
    splitter = RecursiveCharacterTextSplitter(
        chunk_size=chunk_size,
        chunk_overlap=chunk_overlap,
    )
    return splitter.split_text(text)


def get_embeddings() -> HuggingFaceEmbeddings:
    # Small, fast sentence-transformer for local embeddings
    return HuggingFaceEmbeddings(model_name="sentence-transformers/all-MiniLM-L6-v2")


def get_or_create_vectorstore(
    texts: List[str],
    embeddings: HuggingFaceEmbeddings,
    persist_directory: str,
    collection_name: str,
) -> Chroma:
    os.makedirs(persist_directory, exist_ok=True)

    # If a persisted DB exists, load it; otherwise, create and persist
    if any(os.scandir(persist_directory)):
        return Chroma(
            collection_name=collection_name,
            persist_directory=persist_directory,
            embedding_function=embeddings,
        )

    vectorstore = Chroma.from_texts(
        texts=texts,
        embedding=embeddings,
        collection_name=collection_name,
        persist_directory=persist_directory,
    )
    # Ensure it hits disk for faster subsequent runs
    try:
        vectorstore.persist()
    except Exception:
        # Some versions auto-persist; ignore if not needed
        pass
    return vectorstore


def build_llm(api_token: str) -> HuggingFaceEndpoint:
    # Using Flan-T5 for text2text generation via HF Inference API
    return HuggingFaceEndpoint(
        repo_id="google/flan-t5-base",
        task="text2text-generation",
        huggingfacehub_api_token=api_token,
        temperature=0.1,
        max_new_tokens=256,
    )


def main() -> None:
    load_dotenv()

    # Required env var (do not hardcode tokens)
    hf_token = require_env("HUGGINGFACEHUB_API_TOKEN")

    # Optional env vars with sensible defaults
    persist_dir = os.getenv("CHROMA_DB_DIR", "chroma_db")
    collection_name = os.getenv("CHROMA_COLLECTION_NAME", "college_info")
    data_path = os.getenv("COLLEGE_DATA_PATH", "college_info.txt")

    # Prepare data and vector store
    raw_text = read_college_info(data_path)
    docs = split_text(raw_text)
    embeddings = get_embeddings()
    vectorstore = get_or_create_vectorstore(docs, embeddings, persist_dir, collection_name)

    # LLM and RetrievalQA chain
    llm = build_llm(hf_token)
    qa = RetrievalQA.from_chain_type(
        llm=llm,
        retriever=vectorstore.as_retriever(search_kwargs={"k": 4}),
        return_source_documents=False,
    )

    print("🤖 Chatbot ready! Ask about your college. Type 'exit' to quit.")
    while True:
        try:
            query = input("\nYou: ")
        except (EOFError, KeyboardInterrupt):
            print("\n👋 Goodbye!")
            break
        if query.strip().lower() == "exit":
            print("👋 Goodbye!")
            break
        if not query.strip():
            print("(Please enter a question.)")
            continue
        try:
            result = qa.invoke({"query": query})
            print("🤖 Answer:", result.get("result") or result)
        except Exception as exc:
            print(f"⚠️ Error while generating answer: {exc}")


if __name__ == "__main__":
    main()
