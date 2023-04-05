#include <stdbool.h>

struct geometry {
    float x;
    float y;
    float number;
};

void circle(float R);

int degree(int x, int y);

bool test(char* arr, int size);

float reading_elements(float elements, char* arr, int count_digits, int size);