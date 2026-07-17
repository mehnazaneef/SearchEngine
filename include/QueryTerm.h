#pragma once

#include <string>
#include "SearchOperator.h"

struct QueryTerm {
	std::string term;
	SearchOperator op = SearchOperator::And;
};
