//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#define NOK 6
#ifndef REGRESI_LINEAR_BERGANDA_REGRESSION_H
#define REGRESI_LINEAR_BERGANDA_REGRESSION_H

struct sum{
    double sum;
    double square_sum;
    double sigma_of_sigma;
    double average;
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
    double x1y_sum;
    double x1y_sigma_of_sigma;
    double x2y_sum;
    double x2y_sigma_of_sigma;
    double x3y_sum;
    double x3y_sigma_of_sigma;
    double x4y_sum;
    double x4y_sigma_of_sigma;
    double x5y_sum;
    double x5y_sigma_of_sigma;
    double x6y_sum;
    double x6y_sigma_of_sigma;
};

struct result{
    double b0;
    double b1;
    double b2;
    double b3;
    double b4;
    double b5;
    double b6;
    double standard_error_estimate;
    double r_squared;
    double mean_absolute_error;
};

struct multiple_linear_regression {
    struct sigma_x sigma_x;
    struct sigma_y sigma_y;
    struct sigma_xy sigma_xy;
    struct result result;
    int n;
};
#endif //REGRESI_LINEAR_BERGANDA_REGRESSION_H

int linear_regression(const double *x1, const double *x2, const double *x3,
                      const double *x4, const double *x5, const double *x6,
                      double *y, struct multiple_linear_regression *multiple_linear_regression);

double standard_error_of_estimate(struct multiple_linear_regression *multiple_linear_regression);

double r_squared(struct multiple_linear_regression *multiple_linear_regression);

double mean_absolute_error(const double *y, const double *y_hat, int n);

double predict(struct multiple_linear_regression *multiple_linear_regression, double x1, double x2, double x3, double x4, double x5, double x6);