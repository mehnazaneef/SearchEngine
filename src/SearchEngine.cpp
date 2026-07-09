#include "SearchEngine.h"

void SearchEngine::addDocument(const std::filesystem::path& path, const std::string& text) {

	int id = m_nextDocumentId++;

	Document doc{ id, path };
	m_documents.emplace(id, doc);

	auto tokens = m_tokenizer.tokenize(text);

	m_index.addDocument(id, tokens);
}

std::vector<std::string> SearchEngine::search(const std::string& query) {

	auto words = m_tokenizer.tokenize(query);

	if (words.empty())
		return {};

	std::vector<std::string> temp;

	auto resultIds = m_index.search(words);

	for (const auto& id : resultIds) {
		auto it = m_documents.find(id);

		if (it != m_documents.end())
		{
			temp.push_back(it->second.path.filename().string());
		}
	}

	return temp;
}
