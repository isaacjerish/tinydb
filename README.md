# TinyDB (Work in Progress)

This is a basic in-memory database shell written in C. It supports minimal SQL-like operations: `insert` and `select`. Currently, the operations are only recognized as commands, and the actual data manipulation logic is still under development.

## Status: Work in Progress
This project is a learning implementation of a lightweight database. Current functionality is limited to:
- Parsing `.exit`, `.help`, `insert`, and `select` commands
- Maintaining a static table of rows in memory (structure defined, but not yet used)

Future improvements will include:
- Parsing insert arguments
- Appending rows to the in-memory table
- Implementing full `select` behavior
- File-based persistence (eventually)

## Build Instructions

```bash
gcc -o tinydb tinydb.c