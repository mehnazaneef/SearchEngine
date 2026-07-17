#include "SearchResult.h"

SearchResult::SearchResult(int documentId,
    const std::filesystem::path& path,
    int score)
    : m_documentId(documentId),
    m_path(path),
    m_score(score)
{
}

int SearchResult::getDocumentId() const
{
    return m_documentId;
}

const std::filesystem::path& SearchResult::getPath() const
{
    return m_path;
}

int SearchResult::getScore() const
{
    return m_score;
}