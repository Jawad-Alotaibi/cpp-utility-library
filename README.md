# C++ Utility Library

A modular C++ utility library built for learning and practice.  
It contains reusable namespaces for common programming tasks such as string manipulation, file handling, matrix operations, and bank client management.

## Overview

This repository includes a collection of C++ libraries/namespaces that help organize reusable code into separate modules.  
Each namespace focuses on a specific area, making the code easier to reuse, maintain, and extend.

## Libraries / Namespaces

### String Library

Contains helper functions for working with strings, such as:

- Splitting strings
- Joining strings
- Trimming spaces
- Replacing words
- Changing letter cases
- Counting words or characters

### File Library

Contains helper functions for working with files, such as:

- Reading data from files
- Writing data to files
- Appending new records
- Loading file content into vectors
- Saving vectors back to files

### Matrix Library

Contains reusable functions for dealing with matrices, such as:

- Printing matrices
- Filling matrices
- Summing matrix values
- Comparing matrices
- Working with rows and columns

### Bank Library

Contains functions for managing bank clients, such as:

- Listing clients
- Finding a client
- Adding new clients
- Updating client information
- Deleting clients
- Saving and loading client data from files

## Purpose

The purpose of this repository is to practice building clean and reusable C++ code while improving my understanding of:

- Functions
- Namespaces
- Structs
- Vectors
- File handling
- Modular programming
- Problem-solving
- Basic data management

## Technologies Used

- C++
- Standard Template Library (STL)
- File handling using `fstream`

## Project Structure

```txt
My-CPP-Library/
│
├── StringLibrary.h
├── FileLibrary.h
├── MatrixLibrary.h
├── BankLibrary.h
├── MyInputLibrary.h
├── MyOutputLibrary.h
└── README.md
```
Example Usage
#include <iostream>
#include "StringLibrary.h"
#include "FileLibrary.h"
#include "MatrixLibrary.h"
#include "BankLibrary.h"

using namespace std;

int main()
{
    // Example usage of the libraries
    // Call your reusable functions here

    return 0;
}
Notes

This repository is part of my C++ learning journey.
The code will be improved over time as I learn more about algorithms, data structures, and software design.

Author

Jawad Alotaibi

Fresh Software Engineering graduate interested in backend development, software fundamentals, and building clean, reusable code.
