# College Information Chatbot

A conversational AI chatbot that answers questions about college information using LangChain, Hugging Face models, and Chroma vector database.

## Features

- 🤖 Interactive chatbot interface
- 📚 College information retrieval using RAG (Retrieval-Augmented Generation)
- 🔍 Semantic search using Hugging Face embeddings
- 💬 Natural language question answering

## Setup Instructions

### 1. Install Dependencies

```bash
pip install -r requirements.txt
```

### 2. Get Hugging Face API Token

1. Go to [Hugging Face Settings](https://huggingface.co/settings/tokens)
2. Create a new token with read access
3. Copy the token

### 3. Configure Environment

1. Open the `.env` file
2. Replace `your_huggingface_api_token_here` with your actual Hugging Face API token:

```
HUGGINGFACEHUB_API_TOKEN=your_actual_token_here
```

### 4. Run the Chatbot

```bash
python college_chatbot.py
```

## Usage

Once the chatbot is running, you can ask questions like:

- "What programs does the university offer?"
- "What are the admission requirements?"
- "How much does tuition cost?"
- "What student organizations are available?"
- "Tell me about campus life"

Type `exit` to quit the chatbot.

## Files

- `college_chatbot.py` - Main chatbot script
- `college_info.txt` - College information data
- `requirements.txt` - Python dependencies
- `.env` - Environment variables (API keys)
- `README.md` - This file

## How It Works

1. **Text Processing**: The college information is split into chunks for better processing
2. **Embeddings**: Text chunks are converted to vector embeddings using Hugging Face's sentence transformer
3. **Vector Store**: Embeddings are stored in Chroma vector database for fast retrieval
4. **RAG Pipeline**: When you ask a question, the system retrieves relevant chunks and uses them as context for the LLM
5. **Response Generation**: The Hugging Face Flan-T5 model generates answers based on the retrieved context

## Troubleshooting

- **API Key Error**: Make sure your Hugging Face API token is correctly set in the `.env` file
- **Import Errors**: Ensure all dependencies are installed with `pip install -r requirements.txt`
- **Model Loading**: The first run may take longer as models are downloaded and cached