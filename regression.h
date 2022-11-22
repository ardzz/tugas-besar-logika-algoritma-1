//
// Created by Naufal Reky Ardhana on 21/11/22.
//

#ifndef REGRESI_LINEAR_BERGANDA_REGRESSION_H
#define REGRESI_LINEAR_BERGANDA_REGRESSION_H
struct sum{
    double sum;
    double square_sum;
    double sigma_of_sigma;
};

struct sigma_x {
    struct sum x1;
    struct sum x2;
    struct sum x1x2;
};

struct sigma_y {
    struct sum y;
};

struct sigma_xy {
    double x1y_sum;
    double x1y_sigma_of_sigma;
    double x2y_sum;
    double x2y_sigma_of_sigma;
};

struct result{
    double b0;
    double b1;
    double b2;
    double standard_error_estimate;
    double r_squared;
};

struct multiple_linear_regression {
    struct sigma_x sigma_x;
    struct sigma_y sigma_y;
    struct sigma_xy sigma_xy;
    struct result result;
    int n;
};
#endif //REGRESI_LINEAR_BERGANDA_REGRESSION_H

double b1(struct multiple_linear_regression *multiple_linear_regression);

double b2(struct multiple_linear_regression *multiple_linear_regression);

double b0(struct multiple_linear_regression *multiple_linear_regression);

int linear_regression(const double *x1, const double *x2, double *y, struct multiple_linear_regression *multiple_linear_regression);

double standard_error_of_estimate(struct multiple_linear_regression *multiple_linear_regression);

double r_squared(struct multiple_linear_regression *multiple_linear_regression);