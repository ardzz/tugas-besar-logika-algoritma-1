//
// Created by Naufal Reky Ardhana on 18/11/22.
//
#define NOK 6
#ifndef REGRESI_LINEAR_BERGANDA_STATISTICS_H
#define REGRESI_LINEAR_BERGANDA_STATISTICS_H

#endif //REGRESI_LINEAR_BERGANDA_STATISTICS_H

double sum(const double numbers[], int size);
double square_sum(const double *array, int size);
double sigma_of_sigma(double sum_square, double sum, int count);
double sum_multi_value(const double *array1, const double *array2, int size);
double sigma_x1x2(double x1x2, double x1, double x2, int count);
int forwardElim(double mat[NOK][NOK+1]);
double backSub(double mat[NOK][NOK+1], double *gaussian_elimination);
double gaussianElimination(double mat[NOK][NOK+1], double *gaussian_elimination);