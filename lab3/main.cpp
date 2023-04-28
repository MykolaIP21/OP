#include "functions.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Text texts[MAX_TEXTS];

    add_texts(texts);
    int targetLength = get_length();
    int maxIndex = find_max_index(texts, targetLength);

    display_result(texts, maxIndex, targetLength);

    return 0;
}
