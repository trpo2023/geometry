#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include <libgeometry/geometry.h>
 
float circle_perimeter(float R)
{
    float C;

    C = 2.0 * M_PI * R;

    printf("perimeter = %f\n", C);
    return C;
}

float circle_area(float R)
{
    float S;

    S = M_PI * R * R;
    printf("area = %f\n", S);
    return S;
}

int degree(int x, int y)
{
    if(y == 0){
        return 1;
    }else if(y < 0){
        return -1;
    }   

    int result = 1;

    for (int n = 1; n <= y; n++) {
        result *= x;
    }

    return result;
}

bool check_read_circle(char* arr)
{
    if (arr[0] != 'c' || arr[1] != 'i' || arr[2] != 'r' || arr[3] != 'c'
        || arr[4] != 'l' || arr[5] != 'e' || (int)arr[6] > 41 || (int)arr[6] < 40) {
        printf("Error at column 0: expected 'circle'\n");
        return false;
    } 
    return true;
}

bool check_syntax_bracket(char* arr,int size)
{
    if(check_read_circle(arr) == true){
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

        if (counter > 0) {
            printf("Error at column %d: expected ')'\n", test);
            return false;
        } else if (counter_2 > 0) {
            printf("Error at column %d: expected '('\n", test_3);
            return false;
        }
    }else{
        return false;
    }

    return true;
}

bool check_syntax_extra_character(char *arr, int size)
{
    if(check_syntax_bracket(arr,size) == true){
        if(arr[size - 1] == ' '){
            if(arr[size - 2] == ')'){
                printf("Error at column %d: unexpected token\n", size);
                return false;
            }
        }else{
            if(arr[size - 1] != ')'){
                printf("Error at column %d: unexpected token\n", size);
                return false;
            }
        }
    }else{
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
            elements += (x - 48) * degree(10, count_digits - 1) + (y - 48) / 10.0;
            count_digits--;

            if (counter > 1)
                elements -= (y - 48) / 10.0;
        }
    }
    return elements;
}

int search_index_point(char *arr,int index_arr)
{
    while (arr[index_arr] != '.') {
            index_arr++;
        }
    return index_arr;
}

int search_elements(char *arr,int index_arr)
{
    int search_point = 0;

    while (arr[index_arr] != '.') {
            int x = arr[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                search_point++;

            index_arr++;
        }
    return search_point;
}

bool intersects_figure_2(struct geometry figure,struct geometry figure_2)
{
    float figure2_figureX, figure2_figureY;

        if (figure_2.x > figure.x) {
            figure2_figureX = figure_2.x - figure.x;
        } else {
            figure2_figureX = figure.x - figure_2.x;
        }

        if (figure_2.y > figure.y) {
            figure2_figureY = figure_2.y - figure.y;
        } else {
            figure2_figureY = figure.y - figure_2.y;
        }

        printf("intersects:\n");

        if (figure.number + figure_2.number > figure2_figureX
            && figure.number + figure_2.number > figure2_figureY){
            printf("1. circle\n\n");
            return true;
        }
        return false;
}

bool intersects_figure_3(struct geometry figure,struct geometry figure_2,struct geometry figure_3)
{
    float figure3_figure2X, figure3_figureX, figure3_figure2Y,figure3_figureY;
    int flag = 0;

        if (figure_3.x > figure.x) {
            figure3_figureX = figure_3.x - figure.x;
        } else {
            figure3_figureX = figure.x - figure_3.x;
        }

        if (figure_3.x > figure_2.x) {
            figure3_figure2X = figure_3.x - figure_2.x;
        } else {
            figure3_figure2X = figure_2.x - figure_3.x;
        }

        if (figure_3.y > figure.y) {
            figure3_figureY = figure_3.y - figure.y;
        } else {
            figure3_figureY = figure.y - figure_3.y;
        }

        if (figure_3.y > figure_2.y) {
            figure3_figure2Y = figure_3.y - figure_2.y;
        } else {
            figure3_figure2Y = figure_2.y - figure_3.y;
        }

        printf("intersects:\n");

        if (figure.number + figure_3.number > figure3_figureX
            && figure.number + figure_3.number > figure3_figureY){
            printf("1. circle\n");
            flag++;
        }

        if (figure_3.number + figure_2.number > figure3_figure2X
            && figure_3.number + figure_2.number > figure3_figure2Y){
            printf("2. circle\n");
            flag++;
        }

        if(flag > 0)
            return true;
        else    
            return false;
}