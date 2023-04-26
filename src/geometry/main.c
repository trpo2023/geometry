#include <stdbool.h>
#include <stdio.h>

#include <libgeometry/geometry.h>

int main()
{
    int size = 0, index_arr = 0, search_point_1 = 0, search_point_2 = 0,
        search_point_3 = 0;
    int point = 0, point_2 = 0, point_3 = 0;
    char arr[100], arr_2[100], arr_3[100], fill;
    struct geometry figure, figure_2, figure_3;
    figure.number = figure.x = figure.y = 0.0;
    figure_2.number = figure_2.x = figure_2.y = 0.0;
    figure_3.number = figure_3.x = figure_3.y = 0.0;

    while ((fill = getchar()) != '\n') {
        arr[size] = fill;
        size++;
    }

    if (check_syntax_extra_character(arr, size) == true) {
        search_point_1 = search_elements(arr, index_arr);
        index_arr = search_index_point(arr, index_arr);

        point = index_arr;
        index_arr += 2;

        search_point_2 = search_elements(arr, index_arr);
        index_arr = search_index_point(arr, index_arr);

        point_2 = index_arr;
        index_arr += 2;

        search_point_3 = search_elements(arr, index_arr);
        index_arr = search_index_point(arr, index_arr);

        point_3 = index_arr;

        figure.x = reading_elements(figure.x, arr, search_point_1, point);
        figure.y = reading_elements(figure.y, arr, search_point_2, point_2);
        figure.number
                = reading_elements(figure.number, arr, search_point_3, point_3);

        circle_perimeter(figure.number);
        circle_area(figure.number);
        printf("\n");
    }

    size = index_arr = search_point_1 = search_point_2 = search_point_3 = 0;
    point = point_2 = point_3 = 0;

    while ((fill = getchar()) != '\n') {
        arr_2[size] = fill;
        size++;
    }

    if (check_syntax_extra_character(arr_2, size) == true) {
        search_point_1 = search_elements(arr_2, index_arr);
        index_arr = search_index_point(arr_2, index_arr);

        point = index_arr;
        index_arr += 2;

        search_point_2 = search_elements(arr_2, index_arr);
        index_arr = search_index_point(arr_2, index_arr);

        point_2 = index_arr;
        index_arr += 2;

        search_point_3 = search_elements(arr_2, index_arr);
        index_arr = search_index_point(arr_2, index_arr);

        point_3 = index_arr;

        figure_2.x = reading_elements(figure_2.x, arr_2, search_point_1, point);
        figure_2.y
                = reading_elements(figure_2.y, arr_2, search_point_2, point_2);
        figure_2.number = reading_elements(
                figure_2.number, arr_2, search_point_3, point_3);

        circle_perimeter(figure_2.number);
        circle_area(figure_2.number);
        intersects_figure_2(figure, figure_2);
    }

    size = index_arr = search_point_1 = search_point_2 = search_point_3 = 0;
    point = point_2 = point_3 = 0;

    while ((fill = getchar()) != '\n') {
        arr_3[size] = fill;
        size++;
    }

    if (check_syntax_extra_character(arr_3, size) == true) {
        search_point_1 = search_elements(arr_3, index_arr);
        index_arr = search_index_point(arr_3, index_arr);

        point = index_arr;
        index_arr += 2;

        search_point_2 = search_elements(arr_3, index_arr);
        index_arr = search_index_point(arr_3, index_arr);

        point_2 = index_arr;
        index_arr += 2;

        search_point_3 = search_elements(arr_3, index_arr);
        index_arr = search_index_point(arr_3, index_arr);

        point_3 = index_arr;

        figure_3.x = reading_elements(figure_3.x, arr_3, search_point_1, point);
        figure_3.y
                = reading_elements(figure_3.y, arr_3, search_point_2, point_2);
        figure_3.number = reading_elements(
                figure_3.number, arr_3, search_point_3, point_3);

        circle_perimeter(figure_3.number);
        circle_area(figure_3.number);
        intersects_figure_3(figure, figure_2, figure_3);
    }
    return 0;
}