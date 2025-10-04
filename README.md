# College Information Chatbot

A conversational AI chatbot that answers questions about college information using LangChain, Hugging Face models, and Chroma vector database.

## Features

- 🤖 Interactive chatbot interface
- 📚 College information retrieval using RAG (Retrieval-Augmented Generation)
- 🔍 Semantic search through college documents
- 💬 Natural language question answering
- 🚀 Powered by Hugging Face's FLAN-T5 model

## Setup Instructions

### 1. Install Dependencies

```bash
pip install -r requirements.txt
```

### 2. Configure API Key

1. Get your Hugging Face API token from [https://huggingface.co/settings/tokens](https://huggingface.co/settings/tokens)
2. Open the `.env` file and replace `your_huggingface_api_token_here` with your actual API token:

```
HUGGINGFACEHUB_API_TOKEN=your_actual_token_here
```

### 3. Customize College Information

Edit `college_info.txt` to include your specific college's information. The current file contains sample data for "University of Technology".

## Usage

Run the chatbot:

```bash
python college_chatbot.py
```

### Example Questions

- "What are the admission requirements?"
- "How much does tuition cost?"
- "What programs do you offer?"
- "When is the application deadline?"
- "What student services are available?"

Type `exit` to quit the chatbot.

## How It Works

1. **Text Processing**: The college information is split into chunks for better processing
2. **Embeddings**: Text chunks are converted to vector embeddings using Hugging Face's sentence transformer
3. **Vector Store**: Embeddings are stored in Chroma for efficient similarity search
4. **Retrieval**: When you ask a question, the system finds relevant text chunks
5. **Generation**: The FLAN-T5 model generates answers based on the retrieved information

## File Structure

```
├── college_chatbot.py      # Main chatbot script
├── college_info.txt        # College information data
├── .env                    # Environment variables (API keys)
├── requirements.txt        # Python dependencies
└── README.md              # This file
```

## Troubleshooting

### Common Issues

1. **API Key Error**: Make sure your Hugging Face API token is correctly set in the `.env` file
2. **Missing Dependencies**: Run `pip install -r requirements.txt` to install all required packages
3. **File Not Found**: Ensure `college_info.txt` exists in the same directory as the script

### Performance Notes

- First run may take longer as models are downloaded
- Chroma database is created locally for faster subsequent runs
- Consider using GPU for better performance with larger documents

## Customization

- **Model**: Change the LLM model in the script (line with `HuggingFaceEndpoint`)
- **Embeddings**: Modify the embedding model (line with `HuggingFaceEmbeddings`)
- **Chunk Size**: Adjust `chunk_size` and `chunk_overlap` parameters for different text processing
- **Data**: Replace `college_info.txt` with your own college's information

## License

This project is for educational purposes. Please ensure you comply with Hugging Face's terms of service when using their models.