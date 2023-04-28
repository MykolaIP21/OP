#ifndef LAB3_TEXT_H
#define LAB3_TEXT_H

#include "global.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

class Text {
private:
    string lines[MAX_LINES];
    int lines_count = 0;

public:
    void add_line(const string &line);
    int count_lines(int length);
    void print_text();
};


#endif
