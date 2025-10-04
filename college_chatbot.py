import os
import argparse
from dotenv import load_dotenv
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain.chains import RetrievalQA
from langchain_huggingface import HuggingFaceEmbeddings, HuggingFaceEndpoint
from langchain_chroma import Chroma

# Notes:
# - We use Chroma persistent directory so embeddings are cached between runs
# - Token must be provided via env HUGGINGFACEHUB_API_TOKEN (.env supported)

PERSIST_DIR = os.path.join(os.path.dirname(__file__), ".chroma_college")
DATA_FILE = os.path.join(os.path.dirname(__file__), "college_info.txt")


def build_or_load_vectorstore(documents: list[str]) -> Chroma:
    embeddings = HuggingFaceEmbeddings(model_name="sentence-transformers/all-MiniLM-L6-v2")
    if os.path.exists(PERSIST_DIR) and os.listdir(PERSIST_DIR):
        return Chroma(persist_directory=PERSIST_DIR, embedding_function=embeddings)
    vectorstore = Chroma.from_texts(documents, embeddings, persist_directory=PERSIST_DIR)
    try:
        vectorstore.persist()
    except Exception:
        pass
    return vectorstore


def create_qa_chain():
    # Load environment variables
    load_dotenv()
    api_key = os.getenv("HUGGINGFACEHUB_API_TOKEN")
    if not api_key:
        raise ValueError("Hugging Face API key not found. Set HUGGINGFACEHUB_API_TOKEN in .env or environment.")

    # Step 1: Read college info
    if not os.path.exists(DATA_FILE):
        raise FileNotFoundError(f"Missing data file: {DATA_FILE}")
    with open(DATA_FILE, "r", encoding="utf-8") as f:
        data = f.read()

    # Step 2: Split text
    text_splitter = RecursiveCharacterTextSplitter(chunk_size=500, chunk_overlap=100)
    docs = text_splitter.split_text(data)

    # Step 3-4: Vector store
    vectorstore = build_or_load_vectorstore(docs)

    # Step 5: LLM from Hugging Face (uses env token implicitly)
    llm = HuggingFaceEndpoint(
        endpoint_url="https://api-inference.huggingface.co/models/google/flan-t5-base",
        huggingfacehub_api_token=api_key,
        task="text2text-generation",
        model_kwargs={"temperature": 0.0, "max_new_tokens": 256},
    )

    # Step 6: RetrievalQA chain
    qa = RetrievalQA.from_chain_type(
        llm=llm,
        retriever=vectorstore.as_retriever(),
        return_source_documents=False,
    )
    return qa


def interactive_chat(qa):
    print("Chatbot ready! Ask about your college. Type 'exit' to quit.")
    while True:
        try:
            query = input("\nYou: ")
        except (EOFError, KeyboardInterrupt):
            print("\nGoodbye!")
            break
        if query.strip().lower() == "exit":
            print("Goodbye!")
            break
        result = qa.invoke({"query": query})
        print("Answer:", result.get("result") or result)


def main():
    parser = argparse.ArgumentParser(description="College info RAG chatbot")
    parser.add_argument("--question", "-q", help="Ask a single question and exit", default=None)
    args = parser.parse_args()

    qa = create_qa_chain()

    if args.question:
        result = qa.invoke({"query": args.question})
        print(result.get("result") or result)
    else:
        interactive_chat(qa)


if __name__ == "__main__":
    main()
