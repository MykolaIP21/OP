#ifndef LAB1_STREAM_H
#define LAB1_STREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

namespace fs {
    void cycle();
    string get_filename();
    void create_file(const string& filename);
    void append_to_file(const string& filename);
    string get_substring();
    void print_file(const string& filename, const string& text);
    void change_file(const string& filename, const string& substring, int &total);
    void replace_substring(const string& filename, int total);
}

#endif
