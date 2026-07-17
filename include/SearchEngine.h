#pragma once

#include "InvertedIndex.h"
#include "Tokenizer.h"
#include "Document.h"
#include "SearchResult.h"

class SearchEngine
{
public:
	void addDocument(const std::filesystem::path &path, const std::string& text);
	std::vector<SearchResult> search(const std::string& query);

private:
	InvertedIndex m_index;
	Tokenizer m_tokenizer;
	std::unordered_map<int, Document> m_documents;
	int m_nextDocumentId = 1;
};