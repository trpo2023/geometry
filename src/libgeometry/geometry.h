#include <stdbool.h>

#define ASCII_min_number 47
#define ASCII_max_number 58

struct geometry {
    float x;
    float y;
    float number;
};

float circle_perimeter(float R);

float circle_area(float R);

int degree(int x, int y);

bool check_read_circle(char* arr);

bool check_syntax_bracket(char* arr,int size);

bool check_syntax_extra_character(char *arr, int size);

float reading_elements(float elements, char* arr, int count_digits, int size);

int search_index_point(char *arr,int index_arr);

int search_elements(char *arr,int index_arr);

bool intersects_figure_2(struct geometry figure,struct geometry figure_2);

bool intersects_figure_3(struct geometry figure,struct geometry figure_2,struct geometry figure_3);