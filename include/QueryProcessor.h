#pragma once

#include "ParsedQuery.h"

class QueryProcessor {
public:
	ParsedQuery parse(const std::string& query) const;
};