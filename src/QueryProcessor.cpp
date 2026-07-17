#include "QueryProcessor.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace
{
    std::string toLower(std::string word)
    {
        std::transform(word.begin(),
            word.end(),
            word.begin(),
            [](unsigned char c)
            {
                return static_cast<char>(std::tolower(c));
            });

        return word;
    }
}

ParsedQuery QueryProcessor::parse(const std::string& query) const
{
    ParsedQuery parsedQuery;

    std::istringstream stream(query);

    std::string token;

    SearchOperator currentOperator = SearchOperator::And;

    while (stream >> token)
    {
        std::string lowerToken = toLower(token);

        if (lowerToken == "and")
        {
            currentOperator = SearchOperator::And;
            continue;
        }

        if (lowerToken == "or")
        {
            currentOperator = SearchOperator::Or;
            continue;
        }

        if (lowerToken == "not")
        {
            currentOperator = SearchOperator::Not;
            continue;
        }

        QueryTerm term;
        term.term = lowerToken;
        term.op = currentOperator;

        parsedQuery.terms.push_back(std::move(term));

        // Reset to implicit AND
        currentOperator = SearchOperator::And;
    }

    return parsedQuery;
}