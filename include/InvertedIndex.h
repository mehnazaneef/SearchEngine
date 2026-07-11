#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using PostingList = std::unordered_map<int, int>;
using Index = std::unordered_map<std::string, PostingList>;

class InvertedIndex {
public:
	void addDocument(int docId, const std::vector<std::string> tokens);

	const PostingList* getPostingList(const std::string& token) const;

private:
	Index m_index;
};