//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#include "regression.h"

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