#include "statistics.h"
#include "stdio.h"
#include "regression.h"


int main() {

    struct polynomial_regression polynomial_regression;
    struct sigma_x *sigma_x = &polynomial_regression.sigma_x;
    struct sigma_y *sigma_y = &polynomial_regression.sigma_y;
    struct sigma_xy *sigma_xy = &polynomial_regression.sigma_xy;

    int x1[] = {21, 16, 17, 20, 22, 18};
    int x2[] = {8, 2, 6, 4, 7, 3};
    int y[] = {7, 3, 7, 2, 8, 3};
    double b0_result, b1_result, b2_result;

    sigma_y->y.sum = sum(y, 6);

    sigma_x->x1.sum = sum(x1, 6);
    sigma_x->x1.square_sum = square_sum(x1, 6);
    sigma_x->x1.sigma_of_sigma = sigma_of_sigma(sigma_x->x1.square_sum, sigma_x->x1.sum, 6);

    sigma_x->x2.sum = sum(x2, 6);
    sigma_x->x2.square_sum = square_sum(x2, 6);
    sigma_x->x2.sigma_of_sigma = sigma_of_sigma(sigma_x->x2.square_sum, sigma_x->x2.sum, 6);

    sigma_x->x1x2.sum = sum_multi_value(x1, x2, 6);
    sigma_x->x1x2.sigma_of_sigma = sigma_x1x2(sigma_x->x1x2.sum, sigma_x->x1.sum, sigma_x->x2.sum, 6);

    sigma_xy->x1y_sum = sum_multi_value(x1, y, 6);
    sigma_xy->x1y_sigma_of_sigma = sigma_x1x2(sigma_xy->x1y_sum, sigma_x->x1.sum, sigma_y->y.sum, 6);

    sigma_xy->x2y_sum = sum_multi_value(x2, y, 6);
    sigma_xy->x2y_sigma_of_sigma = sigma_x1x2(sigma_xy->x2y_sum, sigma_x->x2.sum, sigma_y->y.sum, 6);

    b1_result = b1(
            sigma_x->x1.sigma_of_sigma,sigma_x->x2.sigma_of_sigma,
            sigma_xy->x1y_sigma_of_sigma,sigma_xy->x2y_sigma_of_sigma,
            sigma_x->x1x2.sigma_of_sigma
            );
    b2_result = b2(
            sigma_x->x1.sigma_of_sigma,sigma_x->x2.sigma_of_sigma,
            sigma_xy->x1y_sigma_of_sigma,sigma_xy->x2y_sigma_of_sigma,
            sigma_x->x1x2.sigma_of_sigma
            );
    b0_result = b0(sigma_y->y.sum, b1_result, sigma_x->x1.sum, b2_result, sigma_x->x2.sum, 6);

    printf("b1 = %f\n", b1_result);
    printf("b2 = %f\n", b2_result);
    printf("b0 = %f\n", b0_result);
}