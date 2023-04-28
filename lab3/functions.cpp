#include "functions.h"

using namespace std;

void add_texts(Text texts[]) {
    texts[0].add_line("12345678");
    texts[0].add_line("12345678");
    texts[1].add_line("екрекрк");
    texts[1].add_line("кеплокеокер");
    texts[2].add_line("11111111");
    texts[2].add_line("33333333");
    texts[2].add_line("12341234");
}

int find_max_index(Text texts[], int targetLength) {
    int maxCount = 0;
    int maxIndex = -1;

    for (int i = 0; i < MAX_TEXTS; ++i) {
        int count = texts[i].count_lines(targetLength);
        if (count > maxCount) {
            maxCount = count;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int get_length() {
    int targetLength;
    cout << "Введіть довжину рядка: ";
    cin >> targetLength;
    return targetLength;
}

void display_result(Text texts[], int maxIndex, int targetLength) {
    if (maxIndex >= 0) {
        cout << "Текст з найбільшою кількістю рядків довжини " << targetLength << " з індексом " << maxIndex << endl;
        cout << "Текст:" << endl;
        texts[maxIndex].print_text();
    } else {
        cout << "Немає текстів з рядками заданої довжини" << endl;
    }
}
