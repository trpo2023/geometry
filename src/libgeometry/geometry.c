#include <stdbool.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846
#include "geometry.h"

void circle(float R)
{
    float C, S;

    C = 2.0 * M_PI * R;
    S = M_PI * R * R;

    printf("perimeter = %.2f\n", C);
    printf("area = %.2f\n", S);
}

int degree(int x, int y)
{
    int result = 1;

    for (int n = 1; n <= y; n++) {
        result *= x;
    }

    return result;
}

bool test(char* arr, int size)
{
    int counter = 0, counter_2 = 0;
    int test = 0, test_3 = 0;

    for (int n = 0; n < size / 2; n++) {
        if (arr[n] == ')') {
            counter++;
            test = n + 1;
        }
    }

    for (int n = size / 2; n < size; n++) {
        if (arr[n] == '(') {
            counter_2++;
            test_3 = n + 1;
        }
    }

    if (arr[0] != 'c' || arr[1] != 'i' || arr[2] != 'r' || arr[3] != 'c'
        || arr[4] != 'l' || arr[5] != 'e'
        || (arr[6] == ' ' && ((int)arr[7] > 41 || (int)arr[7] < 40))
        || ((int)arr[6] > 41 || (int)arr[6] < 40)) {
        printf("Error at column 0: expected 'circle'\n");
        return false;
    } else if (counter > 0) {
        printf("Error at column %d: expected ')'\n", test);
        return false;
    } else if (counter_2 > 0) {
        printf("Error at column %d: expected '('\n", test_3);
        return false;
    } else if (
            arr[size - 1] != ')'
            || (arr[size - 2] == ')' && arr[size - 1] != ' ')) {
        printf("Error at column %d: unexpected token\n", size);
        return false;
    }
    return true;
}

float reading_elements(float elements, char* arr, int count_digits, int size)
{
    int counter = 0;

    for (int n = size - count_digits; n < size; n++) {
        int x = arr[n];
        if (x > 47 && x < 58) {
            counter++;
            int y = arr[size + 1];
            elements += (x - 48) * degree(10, count_digits - 1)
                    + (y - 48) / 10.0;
            count_digits--;

            if (counter > 1)
                elements -= (y - 48) / 10.0;
        }
    }
    return elements;
}