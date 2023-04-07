#include <stdbool.h>
#include <stdio.h>
#define ASCII_min_number 47
#define ASCII_max_number 58

#include "libgeometry/geometry.h"

int main()
{
    int size = 0, index_arr = 0, index_arr_2 = 0, index_arr_3 = 0, index_arr_4 = 0;
    int point = 0, point_2 = 0, point_3 = 0;
    char arr[100], arr_2[100], arr_3[100], fill;
    struct geometry figure,figure_2,figure_3;
    figure.number = figure.x = figure.y = 0.0;
    figure_2.number = figure_2.x = figure_2.y = 0.0;
    figure_3.number = figure_3.x = figure_3.y = 0.0;
    

    while ((fill = getchar()) != '\n') {
        arr[size] = fill;
        size++;
    }

    if (check_syntax_3(arr, size) == true) {
        while (arr[index_arr] != '.') {
            int x = arr[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                index_arr_2++;

            index_arr++;
        }

        point = index_arr;
        index_arr += 2;

        while (arr[index_arr] != '.') {
            int x = arr[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                index_arr_3++;

            index_arr++;
        }

        point_2 = index_arr;
        index_arr += 2;

        while (arr[index_arr] != '.') {
            int x = arr[index_arr];
            if (x > 47 && x < 58)
                index_arr_4++;

            index_arr++;
        }

        point_3 = index_arr;

        figure.x = reading_elements(figure.x, arr, index_arr_2, point);

        figure.y = reading_elements(figure.y, arr, index_arr_3, point_2);

        figure.number = reading_elements(figure.number, arr, index_arr_4, point_3);

        circle(figure.number);
        printf("\n");
    }

    size = index_arr = index_arr_2 = index_arr_3 = index_arr_4 = 0;
    point = point_2 = point_3 = 0;

    while ((fill = getchar()) != '\n') {
        arr_2[size] = fill;
        size++;
    }

    if (check_syntax_3(arr_2, size) == true) {
        while (arr_2[index_arr] != '.') {
            int x = arr_2[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                index_arr_2++;

            index_arr++;
        }

        point = index_arr;
        index_arr += 2;

        while (arr_2[index_arr] != '.') {
            int x = arr_2[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                index_arr_3++;

            index_arr++;
        }

        point_2 = index_arr;
        index_arr += 2;

        while (arr_2[index_arr] != '.') {
            int x = arr_2[index_arr];
            if (x > ASCII_min_number && x < ASCII_max_number)
                index_arr_4++;

            index_arr++;
        }

        point_3 = index_arr;

        figure_2.x = reading_elements(figure_2.x, arr_2, index_arr_2, point);

        figure_2.y = reading_elements(figure_2.y, arr_2, index_arr_3, point_2);

        figure_2.number = reading_elements(figure_2.number, arr_2, index_arr_4, point_3);

        circle(figure_2.number);

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
            && figure.number + figure_2.number > figure2_figureY)
            printf("1. circle\n\n");
    }

    size = index_arr = index_arr_2 = index_arr_3 = index_arr_4 = 0;
    point = point_2 = point_3 = 0;

    while ((fill = getchar()) != '\n') {
        arr_3[size] = fill;
        size++;
    }

    if (check_syntax_3(arr_3, size) == true) {
        while (arr_3[index_arr] != '.') {
            int x = arr_3[index_arr];
            if (x > 47 && x < 58)
                index_arr_2++;

            index_arr++;
        }

        point = index_arr;
        index_arr += 2;

        while (arr_3[index_arr] != '.') {
            int x = arr_3[index_arr];
            if (x > 47 && x < 58)
                index_arr_3++;

            index_arr++;
        }

        point_2 = index_arr;
        index_arr += 2;

        while (arr_3[index_arr] != '.') {
            int x = arr_3[index_arr];
            if (x > 47 && x < 58)
                index_arr_4++;

            index_arr++;
        }

        point_3 = index_arr;

        figure_3.x = reading_elements(figure_3.x, arr_3, index_arr_2, point);

        figure_3.y = reading_elements(figure_3.y, arr_3, index_arr_3, point_2);

        figure_3.number = reading_elements(figure_3.number, arr_3, index_arr_4, point_3);

        circle(figure_3.number);

        float figure3_figure2X, figure3_figureX, figure3_figure2Y,figure3_figureY;

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
            && figure.number + figure_3.number > figure3_figureY)
            printf("1. circle\n");

        if (figure_3.number + figure_2.number > figure3_figure2X
            && figure_3.number + figure_2.number > figure3_figure2Y)
            printf("2. circle\n");
    }
    return 0;
}