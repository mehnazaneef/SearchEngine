# Search Engine

A simple C++ search engine implementation built from scratch to understand information retrieval concepts and modern C++ design.

## Features

- Multi-file document indexing
- Automatic discovery of `.txt` files using `std::filesystem`
- Custom text tokenizer
- Inverted index for efficient document retrieval
- Multi-keyword implicit AND search
- Document metadata management
- Term frequency tracking for each indexed token
- Modular architecture following separation of concerns
- CMake-based build system with automated resource deployment

## Current Workflow

1. Scan data directory for text files.
2. Read file contents.
3. Tokenize the content.
4. Retrieve Posting Lists.
5. Perform AND intersection.
6. Lookup document metadata.
1. Return matching documents.

## Build Instructions

### Requirements

- C++20 compiler
- CMake 3.20+
- Visual Studio 2022

### Build

```bash
cmake -S . -B build
cmake --build build