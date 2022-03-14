#include <stdio.h>

/*
 * 3.1 Task 1 Multiplication Table
 * Develop an algorithm for printing a multiplication table and implementation it in C.
 * Consider the following questions when you develop the solution:
 *
 * What is input, and what is the expected output. Develop test cases for the solution
 * Using top-down design approach, develop an algorithm to print a multiplication table with
 * the input size.
 * Represent your algorithm in both pseudo-code and flowchart
 * Test your algorithm by going through the algorithm yourself with the test cases.
 * Implement your algorithm in C, and test the program with the test cases.
 *
 */
void main() {
    int size;
    char x = 'x';


    int i;
    int j;


    do {
        printf("Input size (1-100) : ");
        scanf("%d", &size);
    } while (size < 1 || size > 100);


    printf("\n\n%4c  |", x);
    for (i = 1; i <= 10; i++) {
        printf("%4d", i);
    }
    printf("\n   ");

    for (i = 0; i <= 10; i++) {
        printf("----");
    }
    printf("\n");


    for (i = 1; i <= size; i++) {
        printf("%4d  |", i);
        for (j = 1; j <= 10; j++) {
            printf("%4d", (j * i));
        }
        printf("\n");
    }

}
