#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include "text.h"

void add_texts(Text texts[]);
int get_length();
int find_max_index(Text texts[], int targetLength);
void display_result(Text texts[], int maxIndex, int targetLength);

#endif
