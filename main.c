#include "statistics.h"
#include "stdio.h"
#include "regression.h"


int main() {
    struct multiple_linear_regression multiple_linear_regression;

    double x1[] = {60, 70, 75, 80, 80, 90, 95, 95, 100, 100};
    double x2[] = {110, 120, 115, 130, 110, 120, 120, 125, 110, 120};
    double y[] = {65, 70, 75, 75, 80, 80, 85, 95, 90, 98};
    multiple_linear_regression.n = sizeof(x1) / sizeof(x1[0]);

    linear_regression(x1, x2, y, &multiple_linear_regression);

    printf("b0: %f\n", multiple_linear_regression.result.b0);
    printf("b1: %f\n", multiple_linear_regression.result.b1);
    printf("b2: %f\n", multiple_linear_regression.result.b2);
    printf("standard error of estimate: %f\n", multiple_linear_regression.result.standard_error_estimate);
    printf("r squared: %f\n", multiple_linear_regression.result.r_squared);

    return 0;
}