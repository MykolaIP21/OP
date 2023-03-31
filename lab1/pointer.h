#ifndef LAB1_POINTER_H
#define LAB1_POINTER_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

namespace fp {
    void cycle();
    char* get_filename();
    void create_file(char* filename);
    void append_to_file(char* filename);
    char* get_substring();
    void print_file(char* filename, const char* text);
    void change_file(char* filename, char* substring, int& total);
    void replace_substring(char* filename, char* substring, int total);
}

#endif //LAB1_POINTER_H
