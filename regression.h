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

struct polynomial_regression {
    struct sigma_x sigma_x;
    struct sigma_y sigma_y;
    struct sigma_xy sigma_xy;
};

struct regression_output {
    double b0;
    double b1;
    double b2;
};
#endif //REGRESI_LINEAR_BERGANDA_REGRESSION_H

double b1(double sigma_x1, double sigma_x2, double sigma_x1y, double sigma_x2y, double sigma_x1x2);
double b2(double sigma_x1, double sigma_x2, double sigma_x1y, double sigma_x2y, double sigma_x1x2);
double b0(double sigma_y, double b1, double sigma_x1, double b2, double sigma_x2, int n);
double multiple_regression(const double *x1, const double *x2, double *y, struct regression_output *regression_output, int n);