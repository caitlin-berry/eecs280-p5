# Project 5 - Text Editor (List Editor)

## Overview
This project implements a terminal-based text editor in C++ using a custom doubly linked list data structure.

The editor supports interactive text manipulation, including inserting and deleting characters, moving a cursor, and tracking row and column positions. The project emphasizes low-level memory management, iterators, and efficient data structure design.

## Features
- Custom implementation of a **doubly linked list**
- Iterator support for traversal and editing
- Dynamic memory management using new and delete
- Text editing operations:
  - insert characters
  - delete characters
  - move cursor (left, right, up, down)
  - jump to start/end of lines
- Tracks:
  - cursor position
  - row and column numbers
  - index within the buffer
- Interactive terminal-based editor interface
- Supports visual editors for testing (E0 and FEMTO)

## How to Run

Compile the program using the provided Makefile:
```bash
make
```
Run the basic visual editor:
```bash
./e0.exe
```
Run the full editor:
```bash
./femto.exe
```

## Program Structure
- `List.hpp` – implementation of a templated doubly linked list
- `List_tests.cpp` – unit tests for the List class
- `TextBuffer.hpp` / TextBuffer.cpp – text editor buffer logic
- `TextBuffer_tests.cpp` – unit tests for text buffer behavior
- `e0.cpp` – minimal visual editor
- `femto.cpp` – full-featured terminal editor
- `line.cpp` – command-line tool for debugging text buffer operations

## Concepts Used
- Doubly linked lists
- Iterators and traversal
- Dynamic memory management (The Big Three)
- Pointer manipulation
- Class design and abstraction
- Efficient text editing algorithms
- Unit testing and debugging
- Terminal-based interfaces

## How It Works
1. Doubly Linked List
   - Stores characters as nodes
   - Each node has pointers to previous and next nodes
   - Supports insertion and deletion in constant time

2. Text Buffer
   - Maintains a linked list of characters
   - Uses an iterator to track the cursor position
   - Tracks row, column, and index for efficient navigation

3. Editing Operations
   - Insertions occur to the left of the cursor
   - Deletions remove the character at the cursor
   - Cursor movement updates position and coordinates

4. Visual Interface
   - E0 provides a simple editing interface
   - FEMTO provides a more complete terminal editor experience similar to nano or pico 

## Example Controls
- Arrow keys → move cursor
- Backspace/Delete → remove characters
- Ctrl-X → exit editor
- Additional shortcuts available in FEMTO interface

## Notes
- The cursor can move to the end of the buffer (past the last character)
- Row and column tracking is optimized to avoid recomputation
- Efficient memory handling ensures no leaks
- The linked list implementation does not use STL containers
- Designed for performance and correctness under frequent edits

## Testing
- Unit tests validate the List and TextBuffer implementations
- Interactive testing available via line.cpp
- Visual editors provide real-time debugging of behavior
