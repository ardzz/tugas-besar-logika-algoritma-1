//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#define NOK 6
#ifndef REGRESI_LINEAR_BERGANDA_REGRESSION_H
#define REGRESI_LINEAR_BERGANDA_REGRESSION_H

struct sum{
    long double sum;
    long double square_sum;
    long double sigma_of_sigma;
    long double average;
};

struct sigma_x {
    struct sum x1;
    struct sum x2;
    struct sum x3;
    struct sum x4;
    struct sum x5;
    struct sum x6;

    struct sum x1x2;
    struct sum x1x3;
    struct sum x1x4;
    struct sum x1x5;
    struct sum x1x6;

    struct sum x2x3;
    struct sum x2x4;
    struct sum x2x5;
    struct sum x2x6;

    struct sum x3x4;
    struct sum x3x5;
    struct sum x3x6;

    struct sum x4x5;
    struct sum x4x6;

    struct sum x5x6;
};

struct sigma_y {
    struct sum y;
};

struct sigma_xy {
    long double x1y_sum;
    long double x1y_sigma_of_sigma;
    long double x2y_sum;
    long double x2y_sigma_of_sigma;
    long double x3y_sum;
    long double x3y_sigma_of_sigma;
    long double x4y_sum;
    long double x4y_sigma_of_sigma;
    long double x5y_sum;
    long double x5y_sigma_of_sigma;
    long double x6y_sum;
    long double x6y_sigma_of_sigma;
};

struct result{
    long double b0;
    long double b1;
    long double b2;
    long double b3;
    long double b4;
    long double b5;
    long double b6;
    long double standard_error_estimate;
    long double r_squared;
    long double mean_absolute_error;
};

struct multiple_linear_regression {
    struct sigma_x sigma_x;
    struct sigma_y sigma_y;
    struct sigma_xy sigma_xy;
    struct result result;
    int n;
};
#endif //REGRESI_LINEAR_BERGANDA_REGRESSION_H

int linear_regression(const long double *x1, const long double *x2, const long double *x3,
                      const long double *x4, const long double *x5, const long double *x6,
                      long double *y, struct multiple_linear_regression *multiple_linear_regression);

long double standard_error_of_estimate(struct multiple_linear_regression *multiple_linear_regression);

long double r_squared(struct multiple_linear_regression *multiple_linear_regression);

long double mean_absolute_error(const long double *y, const long double *y_hat, int n);

long double predict(struct multiple_linear_regression *multiple_linear_regression, long double x1, long double x2, long double x3, long double x4, long double x5, long double x6);