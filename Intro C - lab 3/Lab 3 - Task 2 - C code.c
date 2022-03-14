#include <stdio.h>
/*
 * 3.2 Task 2  Computation of e^x
 * This task requires knowledge on absolute value and factorial.
 * You can read about factorial at https://en.wikipedia.org/wiki/Factorial (Links to an external site.)
 * The exponential function ex can be represented by the Taylor series:
 *
 * where n! denotes the factorial of n. This Taylor series is an infinite series and it is not
 * possible for you to implement an infinite loop to compute the function. In practice,
 * it is enough to add the first n terms as a good approximation. The more terms are summed,
 * the result is more accurate.
 *
 * The requirements on the solution are

 * You can only use basic addition, subtraction, multiplication, and division in your solution.
 * No math function like pow( ) should be used in the computation.
 * The value of ex is obtained by summing up terms in the Taylor series until it finds that
 * the absolute value of a term is less than 0.0000001.
 * Your solution should print out a table of values summing up 1, 2, 3, …n terms
 */

double getDifference(double power, int approximation);

void main() {
    double power;
    int approximation = 1;
    double totalSum = 1;
    printf("Enter to what power you want e raised: ");
    scanf("%lf", &power);
    printf("\n");
    while (1) {
        totalSum += getDifference(power, approximation);
        double tmpOne = getDifference(power, approximation);
        double tmpTwo = getDifference(power, approximation+1);
        printf("e^%.1lf\tapproximation #%d\tAbsolute value: %.7lf\tDifference: %.7lf\n", power, approximation, totalSum,
               getDifference(power, approximation));
        if (tmpTwo - tmpOne == 0) {
            approximation++;
        } else if (tmpTwo - tmpOne > 0.0000001 ||
                   (tmpTwo - tmpOne) < -0.0000001) {
            approximation++;
        } else { break; }
    }
}


double getDifference(double power, int approximation) {
    double sum;
    double temp = 1;
    int i;
    for (i = 1; i <= approximation; i++) {
        temp = (temp * power) / i;
        sum = temp;
    }
    return sum;

}









