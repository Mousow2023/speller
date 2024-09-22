# CS50 Speller

The Speller project is a part of Harvard's CS50 course, designed to demonstrate understanding of data structures and algorithms by implementing a spell checker. This program checks the spelling of words from a text file against a dictionary.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Data Structures](#data-structures)
- [Algorithm](#algorithm)
- [Testing](#testing)
- [Credits](#credits)

## Description

The Speller project involves creating a spell checker that reads a dictionary from a file, stores the words in an efficient data structure, and then checks the spelling of words from a text file provided by the user. The project emphasizes the use of hash tables for quick word lookups and memory management.

## Features

- Loads a dictionary of words from a specified text file.
- Checks the spelling of words in a given input text file.
- Outputs the number of misspelled words.
- Provides suggestions for misspelled words (if implemented).

## Installation

To compile and run the program, you need to have `clang` and `make` installed. Follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/Mousow2023/speller.git
   cd speller
