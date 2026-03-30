#include "TextBuffer.hpp"
using namespace std;
#include <iostream>


// ctor
TextBuffer::TextBuffer() : data(), cursor(data.end()), row(1), column(0), index(0) {}

// move the cursor one position forward
bool TextBuffer::forward() {
    // if the cursor is already past the end...
    if (cursor == data.end()){
        // ... no movement
        return false;
    }
    // if moving past a newline...
    if (*cursor == '\n'){
        // ... increase row & reset column
        ++row;
        column = 0;
    } else {
        // increase the column
        ++column;
    }
    // move the cursor forward
    ++cursor;
    // increase the index
    ++index;
    return true;
}

// move the cursor one position back
bool TextBuffer::backward(){
    // if the cursor is at the beginning...
    if(cursor == data.begin()){
        // ... no movement
        return false;
    }
    // move the cursor backward
    --cursor;
    --index;
    // decrease the index
    // if moving past a newline...
    if (*cursor == '\n'){
        // ...decrememnt row & compute column
        --row;
        column = compute_column();
    } else {
        // decrement column
        --column;
    }
    return true;
}

// insert a char before the cursor
void TextBuffer::insert(char c){
    // insert the char at the cursor
    cursor = data.insert(cursor, c);
    forward();
}

// remove the char at the cursor
bool TextBuffer::remove(){
    if (cursor == data.end()) {
        return false;
    }
    // adjust the row and column based on the removed character
    if (*cursor == '\n') {
        --row;
        column = compute_column();
    } else if (column > 0) {
        // --column;
    }
    cursor = data.erase(cursor);
    // make sure the index is updated 
    if (index > 0) {
        --index;
    }
    return true;
}

// move the cursor to the start of the curr row
void TextBuffer::move_to_row_start() {
    // until you reach the beggining of the column...
    while(column != 0) {
        // ... move back
        backward();
    }
    // set column to the start of the row
    column = 0;
}

// move the cursor to the end of the current row
void TextBuffer::move_to_row_end() {
    // until you reach a newline or the end of the buffer...
    while (cursor != data.end() && *cursor != '\n') {
        // ... move forward
        forward();
    }
}

// move the cursor to the specific column in row
void TextBuffer::move_to_column(int new_column) {
    // start at the beginning of the row
    move_to_row_start();
    for (int i = 0; i < new_column && cursor != data.end() && *cursor != '\n'; ++i) {  
        forward();
    }
}

// move the cursor to the prev row
bool TextBuffer::up(){
    // if already at first row...
    if (row == 1){
        // ... no movement
        return false;
    }
    // save the current column
    int target_column = column;
    // move to the start of current row
    move_to_row_start();
    // move to the end of the prev row
    backward();
    move_to_row_start();
    move_to_column(target_column);
    return true;
}

// move the cursor to next row
bool TextBuffer::down(){
    Iterator temp = cursor;
    int target_column = column;
    move_to_row_end();
    if (cursor == data.end()){
        cursor = temp;
        return false;
    }
    forward();
    for (int i = 0; i < target_column && cursor != data.end() && *cursor != '\n'; i++){
        forward();
    }
    return true;
}

// check if the cursor is past the ed
bool TextBuffer::is_at_end() const {
    return cursor == data.end();
}

// return the char at the cursor
char TextBuffer::data_at_cursor() const {
    return *cursor;
}

// return the row of the char at cursor
int TextBuffer::get_row() const {
    return row;
}

// return the column of the char at cursor
int TextBuffer::get_column() const {
    return column;
}

// return the index of the char at cursor
int TextBuffer::get_index() const {
    return index;
}

// return the num of chars in the buffer
int TextBuffer::size() const {
    return data.size();
}

// return the contents of the text
string TextBuffer::stringify() const{
    if (data.empty()){
        return "";
    }
    // make a str from iterators
    return string(data.begin(), data.end());
}

// compute the column of the cursor 
int TextBuffer::compute_column() const {
    if (cursor == data.end() || data.empty()) {
        return 0; // If at the end or the buffer is empty
    }
    int col = 0;
    auto it = cursor;
    // until a newline f the start of the buffer...
    while (it != data.begin() && *prev(it) != '\n') {
        // ... count the chars backward
        --it;
        ++col;
    }
    return col;
}