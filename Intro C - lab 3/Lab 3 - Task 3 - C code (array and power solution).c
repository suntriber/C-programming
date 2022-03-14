#include <stdio.h>
#include <math.h>

/*
 * 3.3 Task 3  Bitwise Operations
 * In embedded systems, various sensors are used to collect the system statuses,
 * and the statuses are stored in a variable (usually char, 8-bit or 16-bit integer).
 * A car is an embedded system. A modern car has many micro-controllers and is able to
 * collect many statuses in the system.
 *
 * In this task, relevant information about the operational parameters (physical quantities)
 * of a car are to be stored, retrieved and tested. A 16-bit integer storage variable is to be
 * used for this purpose. We shall call this variable stat.
 *
 *
 */


void main() {
    int next;
    int stat = 0;
    int myStatArray[] = {0, 0, 0, 0, 0, 0, 0, 0};


    printf("(-1 to quit) Input bits between 0-7 to set: ");
    while (1) {
        scanf("%d", &next);
        if (next == -1) {
            break;
        }
        if (next < 0 || next > 7) {
            printf("Wrong bit.\n");
        }
        myStatArray[next] = 1;
        stat = stat + pow(2, next);
    }


    if (stat == 0) {
        printf("All good\n");
    }
    if (stat & 0b00000001 || stat & 0b00000010 || stat & 0b00000011) {
        printf("Brake's a busted!\n");
    }
    if (stat & 0b00010000) {
        printf("Fuel level low\n");
    }
    if ((stat & 0b00100100) == 0b00100100) {
        printf("It's both snowing and the engine is hot!\n");
    }
    printf("Binary output: ");
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", myStatArray[i]);  // verification printloop
    }
    printf("\nStat = %d", stat);
}
