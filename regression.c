//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#include "regression.h"
#include "statistics.h"

double b1(double sigma_x1, double sigma_x2, double sigma_x1y, double sigma_x2y, double sigma_x1x2){
    double x, y;
    x = (sigma_x2 * sigma_x1y) - (sigma_x2y * sigma_x1x2);
    y = (sigma_x1 * sigma_x2) - (sigma_x1x2 * sigma_x1x2);
    return x / y;
}

double b2(double sigma_x1, double sigma_x2, double sigma_x1y, double sigma_x2y, double sigma_x1x2){
    double x, y;
    x = (sigma_x1 * sigma_x2y) - (sigma_x1y * sigma_x1x2);
    y = (sigma_x1 * sigma_x2) - (sigma_x1x2 * sigma_x1x2);
    return x / y;
}

double b0(double sigma_y, double b1, double sigma_x1, double b2, double sigma_x2, int n){
    return (sigma_y - (b1 * sigma_x1) - (b2 * sigma_x2)) / n;
}

double multiple_regression(const double *x1, const double *x2, double *y, struct regression_output *regression_output, int n){
    struct polynomial_regression polynomial_regression;
    struct sigma_x *sigma_x = &polynomial_regression.sigma_x;
    struct sigma_y *sigma_y = &polynomial_regression.sigma_y;
    struct sigma_xy *sigma_xy = &polynomial_regression.sigma_xy;
    double b0_result, b1_result, b2_result;

    sigma_y->y.sum = sum(y, n);

    sigma_x->x1.sum = sum(x1, n);
    sigma_x->x1.square_sum = square_sum(x1, n);
    sigma_x->x1.sigma_of_sigma = sigma_of_sigma(sigma_x->x1.square_sum, sigma_x->x1.sum, n);

    sigma_x->x2.sum = sum(x2, n);
    sigma_x->x2.square_sum = square_sum(x2, n);
    sigma_x->x2.sigma_of_sigma = sigma_of_sigma(sigma_x->x2.square_sum, sigma_x->x2.sum, n);

    sigma_x->x1x2.sum = sum_multi_value(x1, x2, n);
    sigma_x->x1x2.sigma_of_sigma = sigma_x1x2(sigma_x->x1x2.sum, sigma_x->x1.sum, sigma_x->x2.sum, n);

    sigma_xy->x1y_sum = sum_multi_value(x1, y, n);
    sigma_xy->x1y_sigma_of_sigma = sigma_x1x2(sigma_xy->x1y_sum, sigma_x->x1.sum, sigma_y->y.sum, n);

    sigma_xy->x2y_sum = sum_multi_value(x2, y, n);
    sigma_xy->x2y_sigma_of_sigma = sigma_x1x2(sigma_xy->x2y_sum, sigma_x->x2.sum, sigma_y->y.sum, n);

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
    b0_result = b0(sigma_y->y.sum, b1_result, sigma_x->x1.sum, b2_result, sigma_x->x2.sum, n);

    regression_output->b0 = b0_result;
    regression_output->b1 = b1_result;
    regression_output->b2 = b2_result;

    return 0;
}