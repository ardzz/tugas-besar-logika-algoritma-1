//
// Created by Naufal Reky Ardhana on 18/11/22.
//
#include "statistics.h"

double sum(const int numbers[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += numbers[i];
    }
    return sum;
}

double square_sum(const int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i] * array[i];
    }
    return sum;
}

double sigma_of_sigma(double sum_square, double sum, int count) {
    return sum_square - ((sum * sum) / count);
}

double sum_multi_value(const int *array1, const int *array2, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array1[i] * array2[i];
    }
    return sum;
}

double sigma_x1x2(double x1x2, double x1, double x2, int count) {
    return x1x2 - ((x1 * x2) / count);
}