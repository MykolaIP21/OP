#include "text.h"

void Text::add_line(const string &line) {
    if (lines_count < MAX_LINES) {
        lines[lines_count] = line;
        lines_count++;
    }
}

int Text::count_lines(int length){
    int count = 0;
    for (int i = 0; i < lines_count; i++) {
        if (lines[i].length() == length) {
            count++;
        }
    }
    return count;
}

void Text::print_text() {
    for (int i = 0; i < lines_count; i++) {
        cout << lines[i] << endl;
    }
}
