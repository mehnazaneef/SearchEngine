#pragma once

#include "InvertedIndex.h"

class SearchEngine
{
public:
	void addDocument(int id, const std::string& text);
	std::vector<int> search(const std::string& query);

private:
	InvertedIndex index;
};