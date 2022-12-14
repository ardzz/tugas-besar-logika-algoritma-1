//
// Created by Naufal Reky Ardhana on 18/11/22.
//
#define NOK 6
#ifndef REGRESI_LINEAR_BERGANDA_STATISTICS_H
#define REGRESI_LINEAR_BERGANDA_STATISTICS_H

#endif //REGRESI_LINEAR_BERGANDA_STATISTICS_H

long double sum(const long double numbers[], int size);
long double square_sum(const long double *array, int size);
long double sigma_of_sigma(long double sum_square, long double sum, int count);
long double sum_multi_value(const long double *array1, const long double *array2, int size);
long double sigma_x1x2(long double x1x2, long double x1, long double x2, int count);
int forwardElim(long double mat[NOK][NOK+1]);
long double backSub(long double mat[NOK][NOK+1], long double *gaussian_elimination);
long double gaussianElimination(long double mat[NOK][NOK+1], long double *gaussian_elimination);