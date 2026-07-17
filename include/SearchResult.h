#pragma once

#include <filesystem>

class SearchResult
{
public:
    SearchResult(int documentId,
        const std::filesystem::path& path,
        int score);

    int getDocumentId() const;

    const std::filesystem::path& getPath() const;

    int getScore() const;

private:
    int m_documentId;
    std::filesystem::path m_path;
    int m_score;
};