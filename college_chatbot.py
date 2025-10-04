import os
from dotenv import load_dotenv
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain.chains import RetrievalQA
from langchain_huggingface import HuggingFaceEmbeddings, HuggingFaceEndpoint
from langchain_chroma import Chroma  # Updated import for newer LangChain

# Load environment variables
load_dotenv()
api_key = os.getenv("HUGGINGFACEHUB_API_TOKEN")
if not api_key:
    raise ValueError("⚠️ Hugging Face API key not found. Please set it in your .env file.")

# Step 1: Read college info
with open("college_info.txt", "r", encoding="utf-8") as f:
    data = f.read()

# Step 2: Split text
text_splitter = RecursiveCharacterTextSplitter(chunk_size=500, chunk_overlap=100)
docs = text_splitter.split_text(data)

# Step 3: Create embeddings
embeddings = HuggingFaceEmbeddings(model_name="sentence-transformers/all-MiniLM-L6-v2")

# Step 4: Create vector store (Chroma)
vectorstore = Chroma.from_texts(docs, embeddings)

# Step 5: LLM from Hugging Face
llm = HuggingFaceEndpoint(
    endpoint_url="https://api-inference.huggingface.co/models/google/flan-t5-base",
    huggingfacehub_api_token=api_key
)

# Step 6: RetrievalQA chain
qa = RetrievalQA.from_chain_type(
    llm=llm,
    retriever=vectorstore.as_retriever(),
    return_source_documents=False
)

# Step 7: Chatbot
print("🤖 Chatbot ready! Ask about your college. Type 'exit' to quit.")
while True:
    query = input("\nYou: ")
    if query.strip().lower() == "exit":
        print("👋 Goodbye!")
        break
    result = qa.invoke({"query": query})
    print("🤖 Answer:", result["result"])