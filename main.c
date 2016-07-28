//
//  main.c
//  clockangle
//
//  Created by cliff on 2016-07-28.
//  Copyright © 2016 cliff. All rights reserved.

//  задано время, нужно рассчитать угол между часовой и минутной стрелками
//

#include <stdio.h>

float getMinuteAngle(int min){
    return 360 * ((float)min/60);
}

float getHourAngle(int hour, int min){
    return 360 * ((float)(hour % 12) / 12) + 360 * ((float) min / (60 * 12));
}

float getAngleBetweenArrows(int hour, int min){
    float min_angle = getMinuteAngle(min);
    float hour_angle = getHourAngle(hour, min);
    printf("minute angel from zero: %3.2f\n", min_angle);
    printf("hour angel from zero: %3.2f\n", hour_angle);
    return hour_angle - min_angle;
}

int main(int argc, const char * argv[]) {
    if (argc != 3){
        printf("wrong number of arguments. expected 2\n");
    } else {
        int hour;
        int min;
        if (sscanf (argv[1], "%i", &hour)!=1) {
            printf ("error %s - not an integer", argv[1]);
            return 1;
        }
        if (sscanf (argv[2], "%i", &min)!=1) {
            printf ("error %s - not an integer", argv[2]);
            return 1;
        }
        printf("search angle for time: %ih:%im\n", hour, min);
        float result = getAngleBetweenArrows(hour, min);
        printf("result. angel between arrows: %3.2f\n", result);
    }
    return 0;
}




