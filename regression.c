//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#include "regression.h"
#include "statistics.h"
#include "math.h"

double b1(struct multiple_linear_regression *multiple_linear_regression){
    double x, y, sigma_x1, sigma_x2, sigma_x1x2, sigma_x1y, sigma_x2y;

    sigma_x1   = multiple_linear_regression->sigma_x.x1.sigma_of_sigma;
    sigma_x2   = multiple_linear_regression->sigma_x.x2.sigma_of_sigma;
    sigma_x1x2 = multiple_linear_regression->sigma_x.x1x2.sigma_of_sigma;
    sigma_x1y  = multiple_linear_regression->sigma_xy.x1y_sigma_of_sigma;
    sigma_x2y  = multiple_linear_regression->sigma_xy.x2y_sigma_of_sigma;

    x = (sigma_x2 * sigma_x1y) - (sigma_x2y * sigma_x1x2);
    y = (sigma_x1 * sigma_x2) - (sigma_x1x2 * sigma_x1x2);

    return x / y;
}

double b2(struct multiple_linear_regression *multiple_linear_regression){
    double x, y, sigma_x1, sigma_x2, sigma_x1x2, sigma_x1y, sigma_x2y;

    sigma_x1   = multiple_linear_regression->sigma_x.x1.sigma_of_sigma;
    sigma_x2   = multiple_linear_regression->sigma_x.x2.sigma_of_sigma;
    sigma_x1x2 = multiple_linear_regression->sigma_x.x1x2.sigma_of_sigma;
    sigma_x1y  = multiple_linear_regression->sigma_xy.x1y_sigma_of_sigma;
    sigma_x2y  = multiple_linear_regression->sigma_xy.x2y_sigma_of_sigma;

    x = (sigma_x1 * sigma_x2y) - (sigma_x1y * sigma_x1x2);
    y = (sigma_x1 * sigma_x2) - (sigma_x1x2 * sigma_x1x2);
    return x / y;
}

double b0(struct multiple_linear_regression *multiple_linear_regression){
    double x, y, sigma_x1, sigma_x2, sigma_y, b1, b2, n;

    sigma_x1   = multiple_linear_regression->sigma_x.x1.sigma_of_sigma;
    sigma_x2   = multiple_linear_regression->sigma_x.x2.sigma_of_sigma;
    sigma_y    = multiple_linear_regression->sigma_y.y.sigma_of_sigma;
    b1         = multiple_linear_regression->result.b1;
    b2         = multiple_linear_regression->result.b2;
    n          = multiple_linear_regression->n;

    return (sigma_y - (b1 * sigma_x1) - (b2 * sigma_x2)) / n;
}

int linear_regression(const double *x1, const double *x2, double *y, struct multiple_linear_regression *multiple_linear_regression){
    struct sigma_x *sigma_x = &multiple_linear_regression->sigma_x;
    struct sigma_y *sigma_y = &multiple_linear_regression->sigma_y;
    struct sigma_xy *sigma_xy = &multiple_linear_regression->sigma_xy;
    double b0_result, b1_result, b2_result;

    sigma_y->y.sum = sum(y, multiple_linear_regression->n);
    sigma_y->y.square_sum = square_sum(y, multiple_linear_regression->n);
    sigma_y->y.sigma_of_sigma = sigma_of_sigma(sigma_y->y.square_sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_x->x1.sum = sum(x1, multiple_linear_regression->n);
    sigma_x->x1.square_sum = square_sum(x1, multiple_linear_regression->n);
    sigma_x->x1.sigma_of_sigma = sigma_of_sigma(sigma_x->x1.square_sum, sigma_x->x1.sum, multiple_linear_regression->n);

    sigma_x->x2.sum = sum(x2, multiple_linear_regression->n);
    sigma_x->x2.square_sum = square_sum(x2, multiple_linear_regression->n);
    sigma_x->x2.sigma_of_sigma = sigma_of_sigma(sigma_x->x2.square_sum, sigma_x->x2.sum, multiple_linear_regression->n);

    sigma_x->x1x2.sum = sum_multi_value(x1, x2, multiple_linear_regression->n);
    sigma_x->x1x2.sigma_of_sigma = sigma_x1x2(sigma_x->x1x2.sum, sigma_x->x1.sum, sigma_x->x2.sum, multiple_linear_regression->n);

    sigma_xy->x1y_sum = sum_multi_value(x1, y, multiple_linear_regression->n);
    sigma_xy->x1y_sigma_of_sigma = sigma_x1x2(sigma_xy->x1y_sum, sigma_x->x1.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x2y_sum = sum_multi_value(x2, y, multiple_linear_regression->n);
    sigma_xy->x2y_sigma_of_sigma = sigma_x1x2(sigma_xy->x2y_sum, sigma_x->x2.sum, sigma_y->y.sum, multiple_linear_regression->n);

    b1_result = b1(multiple_linear_regression);
    b2_result = b2(multiple_linear_regression);
    b0_result = b0(multiple_linear_regression);

    multiple_linear_regression->result.b0 = b0_result;
    multiple_linear_regression->result.b1 = b1_result;
    multiple_linear_regression->result.b2 = b2_result;

    standard_error_of_estimate(multiple_linear_regression);
    r_squared(multiple_linear_regression);

    return 0;
}

double standard_error_of_estimate(struct multiple_linear_regression *regression){
    double numerator, denominator, sigma_y, sigma_y_square, sigma_x1y, sigma_x2y;

    sigma_y = regression->sigma_y.y.sigma_of_sigma;
    sigma_y_square = regression->sigma_y.y.square_sum;
    sigma_x1y = regression->sigma_xy.x1y_sigma_of_sigma;
    sigma_x2y = regression->sigma_xy.x2y_sigma_of_sigma;

    numerator = sigma_y_square - (regression->result.b0 * sigma_y) - (regression->result.b1 * sigma_x1y) - (regression->result.b2 * sigma_x2y);
    denominator = regression->n - 3;

    regression->result.standard_error_estimate = sqrt(numerator / denominator);
    return regression->result.standard_error_estimate;
}

double r_squared(struct multiple_linear_regression *multiple_linear_regression){
    double numerator, denominator, b1, sigma_x1y, b2, sigma_x2y, sigma_y;

    b1 = multiple_linear_regression->result.b1;
    b2 = multiple_linear_regression->result.b2;
    sigma_x1y = multiple_linear_regression->sigma_xy.x1y_sigma_of_sigma;
    sigma_x2y = multiple_linear_regression->sigma_xy.x2y_sigma_of_sigma;
    sigma_y = multiple_linear_regression->sigma_y.y.sigma_of_sigma;

    numerator = (b1 * sigma_x1y) + (b2 * sigma_x2y);
    denominator = sigma_y;

    multiple_linear_regression->result.r_squared = (numerator / denominator);

    return multiple_linear_regression->result.r_squared;
}