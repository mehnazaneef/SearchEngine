#include "SearchEngine.h"

void SearchEngine::addDocument(const std::filesystem::path& path, const std::string& text) {

	int id = m_nextDocumentId++;

	Document doc{ id, path };
	m_documents.emplace(id, doc);

	auto tokens = m_tokenizer.tokenize(text);

	m_index.addDocument(id, tokens);
}

std::vector<SearchResult> SearchEngine::search(const std::string& query) {

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
	// Build search results.
	std::vector<SearchResult> results;

	for (const auto& [docId, score] : currentList)
	{
		auto it = m_documents.find(docId);

		if (it == m_documents.end())
			continue;

		results.emplace_back(
			it->second.id,
			it->second.path,
			score
		);
	}

	// Sort results in descending order of score.
	std::sort(results.begin(),
		results.end(),
		[](const SearchResult& lhs, const SearchResult& rhs)
		{
			return lhs.getScore() > rhs.getScore();
		});

	return results;

}
