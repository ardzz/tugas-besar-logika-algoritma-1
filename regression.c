//
// Created by Naufal Reky Ardhana on 21/11/22.
//
#include "regression.h"
#include "statistics.h"
#include "math.h"

int linear_regression(
        const long double *x1, const long double *x2, const long double *x3,
        const long double *x4, const long double *x5, const long double *x6,
        long double *y, struct multiple_linear_regression *multiple_linear_regression){

    struct sigma_x *sigma_x = &multiple_linear_regression->sigma_x;
    struct sigma_y *sigma_y = &multiple_linear_regression->sigma_y;
    struct sigma_xy *sigma_xy = &multiple_linear_regression->sigma_xy;

    long double b0, b1, b2, b3, b4, b5, b6;

    sigma_y->y.sum = sum(y, multiple_linear_regression->n);
    sigma_y->y.square_sum = square_sum(y, multiple_linear_regression->n);
    sigma_y->y.sigma_of_sigma = sigma_of_sigma(sigma_y->y.square_sum, sigma_y->y.sum, multiple_linear_regression->n);
    sigma_y->y.average = sigma_y->y.sum / multiple_linear_regression->n;

    sigma_x->x1.sum = sum(x1, multiple_linear_regression->n);
    sigma_x->x1.square_sum = square_sum(x1, multiple_linear_regression->n);
    sigma_x->x1.sigma_of_sigma = sigma_of_sigma(sigma_x->x1.square_sum, sigma_x->x1.sum, multiple_linear_regression->n);
    sigma_x->x1.average = sigma_x->x1.sum / multiple_linear_regression->n;

    sigma_x->x2.sum = sum(x2, multiple_linear_regression->n);
    sigma_x->x2.square_sum = square_sum(x2, multiple_linear_regression->n);
    sigma_x->x2.sigma_of_sigma = sigma_of_sigma(sigma_x->x2.square_sum, sigma_x->x2.sum, multiple_linear_regression->n);
    sigma_x->x2.average = sigma_x->x2.sum / multiple_linear_regression->n;

    sigma_x->x3.sum = sum(x3, multiple_linear_regression->n);
    sigma_x->x3.square_sum = square_sum(x3, multiple_linear_regression->n);
    sigma_x->x3.sigma_of_sigma = sigma_of_sigma(sigma_x->x3.square_sum, sigma_x->x3.sum, multiple_linear_regression->n);
    sigma_x->x3.average = sigma_x->x3.sum / multiple_linear_regression->n;

    sigma_x->x4.sum = sum(x4, multiple_linear_regression->n);
    sigma_x->x4.square_sum = square_sum(x4, multiple_linear_regression->n);
    sigma_x->x4.sigma_of_sigma = sigma_of_sigma(sigma_x->x4.square_sum, sigma_x->x4.sum, multiple_linear_regression->n);
    sigma_x->x4.average = sigma_x->x4.sum / multiple_linear_regression->n;

    sigma_x->x5.sum = sum(x5, multiple_linear_regression->n);
    sigma_x->x5.square_sum = square_sum(x5, multiple_linear_regression->n);
    sigma_x->x5.sigma_of_sigma = sigma_of_sigma(sigma_x->x5.square_sum, sigma_x->x5.sum, multiple_linear_regression->n);

    sigma_x->x6.sum = sum(x6, multiple_linear_regression->n);
    sigma_x->x6.square_sum = square_sum(x6, multiple_linear_regression->n);
    sigma_x->x6.sigma_of_sigma = sigma_of_sigma(sigma_x->x6.square_sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_x->x1x2.sum = sum_multi_value(x1, x2, multiple_linear_regression->n);
    sigma_x->x1x2.sigma_of_sigma = sigma_x1x2(sigma_x->x1x2.sum, sigma_x->x1.sum, sigma_x->x2.sum, multiple_linear_regression->n);

    sigma_x->x1x3.sum = sum_multi_value(x1, x3, multiple_linear_regression->n);
    sigma_x->x1x3.sigma_of_sigma = sigma_x1x2(sigma_x->x1x3.sum, sigma_x->x1.sum, sigma_x->x3.sum, multiple_linear_regression->n);

    sigma_x->x1x4.sum = sum_multi_value(x1, x4, multiple_linear_regression->n);
    sigma_x->x1x4.sigma_of_sigma = sigma_x1x2(sigma_x->x1x4.sum, sigma_x->x1.sum, sigma_x->x4.sum, multiple_linear_regression->n);

    sigma_x->x1x5.sum = sum_multi_value(x1, x5, multiple_linear_regression->n);
    sigma_x->x1x5.sigma_of_sigma = sigma_x1x2(sigma_x->x1x5.sum, sigma_x->x1.sum, sigma_x->x5.sum, multiple_linear_regression->n);

    sigma_x->x1x6.sum = sum_multi_value(x1, x6, multiple_linear_regression->n);
    sigma_x->x1x6.sigma_of_sigma = sigma_x1x2(sigma_x->x1x6.sum, sigma_x->x1.sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_x->x2x3.sum = sum_multi_value(x2, x3, multiple_linear_regression->n);
    sigma_x->x2x3.sigma_of_sigma = sigma_x1x2(sigma_x->x2x3.sum, sigma_x->x2.sum, sigma_x->x3.sum, multiple_linear_regression->n);

    sigma_x->x2x4.sum = sum_multi_value(x2, x4, multiple_linear_regression->n);
    sigma_x->x2x4.sigma_of_sigma = sigma_x1x2(sigma_x->x2x4.sum, sigma_x->x2.sum, sigma_x->x4.sum, multiple_linear_regression->n);

    sigma_x->x2x5.sum = sum_multi_value(x2, x5, multiple_linear_regression->n);
    sigma_x->x2x5.sigma_of_sigma = sigma_x1x2(sigma_x->x2x5.sum, sigma_x->x2.sum, sigma_x->x5.sum, multiple_linear_regression->n);

    sigma_x->x2x6.sum = sum_multi_value(x2, x6, multiple_linear_regression->n);
    sigma_x->x2x6.sigma_of_sigma = sigma_x1x2(sigma_x->x2x6.sum, sigma_x->x2.sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_x->x3x4.sum = sum_multi_value(x3, x4, multiple_linear_regression->n);
    sigma_x->x3x4.sigma_of_sigma = sigma_x1x2(sigma_x->x3x4.sum, sigma_x->x3.sum, sigma_x->x4.sum, multiple_linear_regression->n);

    sigma_x->x3x5.sum = sum_multi_value(x3, x5, multiple_linear_regression->n);
    sigma_x->x3x5.sigma_of_sigma = sigma_x1x2(sigma_x->x3x5.sum, sigma_x->x3.sum, sigma_x->x5.sum, multiple_linear_regression->n);

    sigma_x->x3x6.sum = sum_multi_value(x3, x6, multiple_linear_regression->n);
    sigma_x->x3x6.sigma_of_sigma = sigma_x1x2(sigma_x->x3x6.sum, sigma_x->x3.sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_x->x4x5.sum = sum_multi_value(x4, x5, multiple_linear_regression->n);
    sigma_x->x4x5.sigma_of_sigma = sigma_x1x2(sigma_x->x4x5.sum, sigma_x->x4.sum, sigma_x->x5.sum, multiple_linear_regression->n);

    sigma_x->x4x6.sum = sum_multi_value(x4, x6, multiple_linear_regression->n);
    sigma_x->x4x6.sigma_of_sigma = sigma_x1x2(sigma_x->x4x6.sum, sigma_x->x4.sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_x->x5x6.sum = sum_multi_value(x5, x6, multiple_linear_regression->n);
    sigma_x->x5x6.sigma_of_sigma = sigma_x1x2(sigma_x->x5x6.sum, sigma_x->x5.sum, sigma_x->x6.sum, multiple_linear_regression->n);

    sigma_xy->x1y_sum = sum_multi_value(x1, y, multiple_linear_regression->n);
    sigma_xy->x1y_sigma_of_sigma = sigma_x1x2(sigma_xy->x1y_sum, sigma_x->x1.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x2y_sum = sum_multi_value(x2, y, multiple_linear_regression->n);
    sigma_xy->x2y_sigma_of_sigma = sigma_x1x2(sigma_xy->x2y_sum, sigma_x->x2.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x3y_sum = sum_multi_value(x3, y, multiple_linear_regression->n);
    sigma_xy->x3y_sigma_of_sigma = sigma_x1x2(sigma_xy->x3y_sum, sigma_x->x3.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x4y_sum = sum_multi_value(x4, y, multiple_linear_regression->n);
    sigma_xy->x4y_sigma_of_sigma = sigma_x1x2(sigma_xy->x4y_sum, sigma_x->x4.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x5y_sum = sum_multi_value(x5, y, multiple_linear_regression->n);
    sigma_xy->x5y_sigma_of_sigma = sigma_x1x2(sigma_xy->x5y_sum, sigma_x->x5.sum, sigma_y->y.sum, multiple_linear_regression->n);

    sigma_xy->x6y_sum = sum_multi_value(x6, y, multiple_linear_regression->n);
    sigma_xy->x6y_sigma_of_sigma = sigma_x1x2(sigma_xy->x6y_sum, sigma_x->x6.sum, sigma_y->y.sum, multiple_linear_regression->n);

    long double matrix[NOK][NOK+1] = {
            {sigma_x->x1.sigma_of_sigma, sigma_x->x1x2.sigma_of_sigma, sigma_x->x1x3.sigma_of_sigma, sigma_x->x1x4.sigma_of_sigma, sigma_x->x1x5.sigma_of_sigma, sigma_x->x1x6.sigma_of_sigma, sigma_xy->x1y_sigma_of_sigma},
            {sigma_x->x1x2.sigma_of_sigma, sigma_x->x2.sigma_of_sigma, sigma_x->x2x3.sigma_of_sigma, sigma_x->x2x4.sigma_of_sigma, sigma_x->x2x5.sigma_of_sigma, sigma_x->x2x6.sigma_of_sigma, sigma_xy->x2y_sigma_of_sigma},
            {sigma_x->x1x3.sigma_of_sigma, sigma_x->x2x3.sigma_of_sigma, sigma_x->x3.sigma_of_sigma, sigma_x->x3x4.sigma_of_sigma, sigma_x->x3x5.sigma_of_sigma, sigma_x->x3x6.sigma_of_sigma, sigma_xy->x3y_sigma_of_sigma},
            {sigma_x->x1x4.sigma_of_sigma, sigma_x->x2x4.sigma_of_sigma, sigma_x->x3x4.sigma_of_sigma, sigma_x->x4.sigma_of_sigma, sigma_x->x4x5.sigma_of_sigma, sigma_x->x4x6.sigma_of_sigma, sigma_xy->x4y_sigma_of_sigma},
            {sigma_x->x1x5.sigma_of_sigma, sigma_x->x2x5.sigma_of_sigma, sigma_x->x3x5.sigma_of_sigma, sigma_x->x4x5.sigma_of_sigma, sigma_x->x5.sigma_of_sigma, sigma_x->x5x6.sigma_of_sigma, sigma_xy->x5y_sigma_of_sigma},
            {sigma_x->x1x6.sigma_of_sigma, sigma_x->x2x6.sigma_of_sigma, sigma_x->x3x6.sigma_of_sigma, sigma_x->x4x6.sigma_of_sigma, sigma_x->x5x6.sigma_of_sigma, sigma_x->x6.sigma_of_sigma, sigma_xy->x6y_sigma_of_sigma}
    };

    long double gaussian_elimination[NOK];
    gaussianElimination(matrix, (long double *) &gaussian_elimination);

    multiple_linear_regression->result.b1 = gaussian_elimination[0];
    multiple_linear_regression->result.b2 = gaussian_elimination[1];
    multiple_linear_regression->result.b3 = gaussian_elimination[2];
    multiple_linear_regression->result.b4 = gaussian_elimination[3];
    multiple_linear_regression->result.b5 = gaussian_elimination[4];
    multiple_linear_regression->result.b6 = gaussian_elimination[5];
    multiple_linear_regression->result.b0 = sigma_y->y.average - (multiple_linear_regression->result.b1 * sigma_x->x1.average) - (multiple_linear_regression->result.b2 * sigma_x->x2.average) - (multiple_linear_regression->result.b3 * sigma_x->x3.average) - (multiple_linear_regression->result.b4 * sigma_x->x4.average) - (multiple_linear_regression->result.b5 * sigma_x->x5.average) - (multiple_linear_regression->result.b6 * sigma_x->x6.average);

    return 0;
}

/*
 * Sigma (y_actual - y_predicted)^2
 */
long double mean_absolute_error(const long double *y, const long double *y_hat, int n){
    long double sum = 0;
    int i;

    for(i = 0; i < n; i++){
        sum += fabsl(y[i] - y_hat[i]);
    }

    return sum / n;
}

long double predict(struct multiple_linear_regression *multiple_linear_regression, long double x1, long double x2, long double x3, long double x4, long double x5, long double x6){
    return multiple_linear_regression->result.b0 + (multiple_linear_regression->result.b1 * x1) + (multiple_linear_regression->result.b2 * x2) + (multiple_linear_regression->result.b3 * x3) + (multiple_linear_regression->result.b4 * x4) + (multiple_linear_regression->result.b5 * x5) + (multiple_linear_regression->result.b6 * x6);
}