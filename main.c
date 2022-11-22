#include "statistics.h"
#include "stdio.h"
#include "regression.h"


int main() {
    double x1[] = {21, 16, 17, 20, 22, 18};
    double x2[] = {8, 2, 6, 4, 7, 3};
    double y[] = {7, 3, 7, 2, 8, 3};
    int n = sizeof(x1) / sizeof(x1[0]);

    struct regression_output regression_output;
    multiple_regression(x1, x2, y, &regression_output, n);

    printf("b0: %f\n", regression_output.b0);
    printf("b1: %f\n", regression_output.b1);
    printf("b2: %f\n", regression_output.b2);

    return 0;
}