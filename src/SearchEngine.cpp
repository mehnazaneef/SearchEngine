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

	const PostingList* firstPostingList = m_index.getPostingList(words[0]);

	if (firstPostingList == nullptr)
		return {};

	PostingList currentList = *firstPostingList;

	for (size_t i = 1;i < words.size();i++) {
		const PostingList* postingList = m_index.getPostingList(words[i]);

		if (postingList == nullptr)
			return {};

		PostingList tempResult;

		for (const auto& [docId, score] : currentList) {
			auto it = postingList->find(docId);
			
			if (it != postingList->end()) {
				tempResult[docId] = score + it->second;
			}
		}
		currentList = std::move(tempResult);
	}
	// Convert document IDs into filenames.
	std::vector<std::string> results;

	for (const auto& [docId, score] : currentList)
	{
		auto it = m_documents.find(docId);

		if (it != m_documents.end())
		{
			results.push_back(it->second.path.filename().string());
		}
	}

	return results;

}
