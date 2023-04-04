#include <stdio.h>
#include <stdbool.h>
#include "libgeometry/geometry.h"

struct geometry figure;
struct geometry figure_2;
struct geometry figure_3;

int main()
{
    int size = 0,counter = 0,counter_2 = 0,counter_3 = 0,counter_4 = 0;
    int point = 0,point_2 = 0,point_3 = 0;
    char arr[100],arr_2[100],arr_3[100],fill;

    while((fill = getchar()) != '\n'){
        arr[size] = fill;
        size++;
    }

    if(test(arr,size) == true){
        while(arr[counter] != '.'){
            int x = arr[counter];
            if(x > 47 && x < 58)
                counter_2++;
                    
            counter++;
        }

        point = counter;
        counter += 2;

        while(arr[counter] != '.'){
            int x = arr[counter];
            if(x > 47 && x < 58)
                counter_3++;

            counter++;
        }

        point_2 = counter;
        counter += 2;

        while(arr[counter] != '.'){
            int x = arr[counter];
            if(x > 47 && x < 58)
                counter_4++;

            counter++;
        }

        point_3 = counter;

        figure.x = reading_elements(figure.x,arr,counter_2,point);

        figure.y = reading_elements(figure.y,arr,counter_3,point_2);

        figure.number = reading_elements(figure.number,arr,counter_4,point_3);

        circle(figure.number);
        printf("\n");
    }
    
    size = counter = counter_2 = counter_3 = counter_4 = 0;
    point = point_2 = point_3 = 0;

    while((fill = getchar()) != '\n'){
        arr_2[size] = fill;
        size++;
    }

    if(test(arr_2,size) == true){
        while(arr_2[counter] != '.'){
            int x = arr_2[counter];
            if(x > 47 && x < 58)
                counter_2++;
                        
            counter++;
        }

        point = counter;
        counter += 2;

        while(arr_2[counter] != '.'){
            int x = arr_2[counter];
            if(x > 47 && x < 58)
                counter_3++;

            counter++;
        }

        point_2 = counter;
        counter += 2;

        while(arr_2[counter] != '.'){
            int x = arr_2[counter];
            if(x > 47 && x < 58)
                counter_4++;

            counter++;
        }

        point_3 = counter;

        figure_2.x = reading_elements(figure_2.x,arr_2,counter_2,point);

        figure_2.y = reading_elements(figure_2.y,arr_2,counter_3,point_2);

        figure_2.number = reading_elements(figure_2.number,arr_2,counter_4,point_3);
        
        circle(figure_2.number);

        float figure2_figureX,figure2_figureY;

        if(figure_2.x > figure.x){
            figure2_figureX = figure_2.x - figure.x;
        }else{
            figure2_figureX = figure.x - figure_2.x;
        }

        if(figure_2.y > figure.y){
            figure2_figureY = figure_2.y - figure.y;
        }else{
            figure2_figureY = figure.y - figure_2.y;
        }

        printf("intersects:\n");

        if(figure.number + figure_2.number > figure2_figureX && figure.number + figure_2.number > figure2_figureY)
            printf("1. circle\n\n");
    }

    size = counter = counter_2 = counter_3 = counter_4 = 0;
    point = point_2 = point_3 = 0;   

    while((fill = getchar()) != '\n'){
        arr_3[size] = fill;
        size++;
    }

    if(test(arr_3,size) == true){
        while(arr_3[counter] != '.'){
            int x = arr_3[counter];
            if(x > 47 && x < 58)
                counter_2++;
                        
            counter++;
        }

        point = counter;
        counter += 2;

        while(arr_3[counter] != '.'){
            int x = arr_3[counter];
            if(x > 47 && x < 58)
                counter_3++;

            counter++;
        }

        point_2 = counter;
        counter += 2;

        while(arr_3[counter] != '.'){
            int x = arr_3[counter];
            if(x > 47 && x < 58)
                counter_4++;

            counter++;
        }

        point_3 = counter;

        figure_3.x = reading_elements(figure_3.x,arr_3,counter_2,point);

        figure_3.y = reading_elements(figure_3.y,arr_3,counter_3,point_2);

        figure_3.number = reading_elements(figure_3.number,arr_3,counter_4,point_3);

        circle(figure_3.number);

        float figure3_figure2X,figure3_figureX,figure3_figure2Y,figure3_figureY;

        if(figure_3.x > figure.x){
            figure3_figureX = figure_3.x - figure.x;
        }else{
            figure3_figureX = figure.x - figure_3.x;
        }

        if(figure_3.x > figure_2.x){
            figure3_figure2X = figure_3.x - figure_2.x;
        }else{
            figure3_figure2X = figure_2.x - figure_3.x;
        }

        if(figure_3.y > figure.y){
            figure3_figureY = figure_3.y - figure.y;
        }else{
            figure3_figureY = figure.y - figure_3.y;
        }

        if(figure_3.y > figure_2.y){
            figure3_figure2Y = figure_3.y - figure_2.y;
        }else{
            figure3_figure2Y = figure_2.y - figure_3.y;
        }          

        printf("intersects:\n");

        if(figure.number + figure_3.number > figure3_figureX && figure.number + figure_3.number > figure3_figureY)
            printf("1. circle\n");
            
        if(figure_3.number + figure_2.number > figure3_figure2X && figure_3.number + figure_2.number > figure3_figure2Y)
            printf("2. circle\n");
        }
    return 0;
}