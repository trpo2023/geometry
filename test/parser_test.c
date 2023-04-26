#include <ctest.h>
#include <libgeometry/geometry.h>
#define _USE_MATH_DEFINES

CTEST(degree, test1)
{
    int test_degree_1 = degree(2, 5);
    int test_degree_2 = degree(2, 0);
    int test_degree_3 = degree(2, -2);

    ASSERT_EQUAL(test_degree_1, 32);
    ASSERT_EQUAL(test_degree_2, 1);
    ASSERT_EQUAL(test_degree_3, -1);
}

CTEST(check_read_circle, test2)
{
    char test_check_read_circle_1[] = "circle(";
    char test_check_read_circle_2[] = "ciFcle";

    ASSERT_TRUE(check_read_circle(test_check_read_circle_1));
    ASSERT_FALSE(check_read_circle(test_check_read_circle_2));
}

CTEST(check_syntax_extra_character, test3)
{
    char test_check_syntax_extra_character_1[] = "circle(10.4 14.9 , 12.1)";
    char test_check_syntax_extra_character_2[] = "circle(10.4 14.9 , 12.1) ";
    char test_check_syntax_extra_character_3[] = "circle(10.4 14.9 , 12.1)fg";

    ASSERT_TRUE(check_syntax_extra_character(
            test_check_syntax_extra_character_1, 24));
    ASSERT_TRUE(check_syntax_extra_character(
            test_check_syntax_extra_character_2, 24));
    ASSERT_FALSE(check_syntax_extra_character(
            test_check_syntax_extra_character_3, 26));
}

CTEST(check_syntax_bracket, test4)
{
    char test_check_syntax_bracket_1[] = "circle(10.4 14.9 , 12.1)";
    char test_check_syntax_bracket_2[] = "circle)10.4 14.9 , 12.1)";
    char test_check_syntax_bracket_3[] = "circle(10.4 14.9 , 12.1(";
    char test_check_syntax_bracket_4[] = "circle)10.4 14.9 , 12.1(";

    ASSERT_TRUE(check_syntax_bracket(test_check_syntax_bracket_1, 24));
    ASSERT_FALSE(check_syntax_bracket(test_check_syntax_bracket_2, 24));
    ASSERT_FALSE(check_syntax_bracket(test_check_syntax_bracket_3, 24));
    ASSERT_FALSE(check_syntax_bracket(test_check_syntax_bracket_4, 24));
}

CTEST(reading_elements, test5)
{
    char str[] = "circle(1.0 5.9 , 12.1)";
    float test_reading_elements_1 = 0.0;
    float test_reading_elements_2 = 0.0;
    float test_reading_elements_3 = 0.0;

    test_reading_elements_1
            = reading_elements(test_reading_elements_1, str, 1, 8);
    test_reading_elements_2
            = reading_elements(test_reading_elements_2, str, 1, 12);
    test_reading_elements_3
            = reading_elements(test_reading_elements_3, str, 2, 19);

    ASSERT_EQUAL(test_reading_elements_1, 1.0);
    ASSERT_EQUAL(test_reading_elements_2, 5.9);
    ASSERT_EQUAL(test_reading_elements_3, 12.1);
}

CTEST(search_index_point, test6)
{
    char test_search_index_point[] = "123.5";

    ASSERT_EQUAL(search_index_point(test_search_index_point, 0), 3);
}

CTEST(search_elements, test7)
{
    char test_search_element_1[] = "1.0";
    char test_search_element_2[] = "10.0";

    ASSERT_EQUAL(search_elements(test_search_element_1, 0), 1);
    ASSERT_EQUAL(search_elements(test_search_element_2, 0), 2);
}

CTEST(circle_perimeter, test8)
{
    float perimeter = circle_perimeter(3.5);

    ASSERT_EQUAL(perimeter, 21.991148);
}

CTEST(circle_area, test9)
{
    float area = circle_area(3.5);

    ASSERT_EQUAL(area, 38.484509);
}

CTEST(intersects_figure_2, test10)
{
    struct geometry figure_1, figure_2;

    figure_1.x = figure_2.x = 1.0;
    figure_1.y = figure_2.y = 3.0;
    figure_1.number = figure_2.number = 5.0;

    ASSERT_TRUE(intersects_figure_2(figure_1, figure_2));
}

CTEST(intersects_figure_3, test11)
{
    struct geometry figure_1, figure_2, figure_3;

    figure_1.x = figure_2.x = figure_3.x = 1.0;
    figure_1.y = figure_2.y = figure_3.y = 3.0;
    figure_1.number = figure_2.number = figure_3.number = 5.0;

    ASSERT_TRUE(intersects_figure_3(figure_1, figure_2, figure_3));
}