# SearchEngine

A beginner C++ search engine project built using:

- C++20
- CMake
- Git

## Features

- Read text from file
- Splits the text into lower case words using a tokenizer
- Indexing the documents using InvertedIndex to reduce the lookup time
- Modular project structure

## Build Instructions

```bash
mkdir build
cd build

cmake ..
cmake --build .