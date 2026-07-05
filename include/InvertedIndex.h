#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class InvertedIndex {
public:
	void addDocument(int docId, const std::string& text);

	std::vector<int> search(const std::string& query);

private:
	std::unordered_map<std::string, std::unordered_set<int>> index;
};