# Search Engine

A simple C++ search engine implementation built from scratch to understand information retrieval concepts and modern C++ design.

## Features Implemented

- C++20 based implementation
- Multi-file text loading
- Directory traversal using std::filesystem
- Text tokenization
- Inverted index based searching
- Multi-word AND search
- Document metadata management
- Automatic data folder deployment using CMake

## Current Workflow

1. Scan data directory for text files.
2. Read file contents.
3. Tokenize the content.
4. Build inverted index.
5. Execute queries.
6. Return matching document names.

## Build Instructions

### Requirements

- C++20 compiler
- CMake 3.20+
- Visual Studio 2022

### Build

```bash
cmake -S . -B build
cmake --build build