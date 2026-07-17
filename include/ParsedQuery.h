#pragma once

#include <vector>

#include "QueryTerm.h"

struct ParsedQuery {
	std::vector<QueryTerm> terms;
};