#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class InvertedIndex {
public:
	void addDocument(int docId, const std::vector<std::string> tokens);

	std::vector<int> search(const std::vector<std::string> words);

private:
	std::unordered_map<std::string, std::unordered_set<int>> index;
};