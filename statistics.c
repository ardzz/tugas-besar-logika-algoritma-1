//
// Created by Naufal Reky Ardhana on 18/11/22.
//
#include "statistics.h"
#include "stdio.h"
#include "math.h"

double sum(const double numbers[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += numbers[i];
    }
    return sum;
}

double square_sum(const double *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i] * array[i];
    }
    return sum;
}

double sigma_of_sigma(double sum_square, double sum, int count) {
    return sum_square - ((sum * sum) / count);
}

double sum_multi_value(const double *array1, const double *array2, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array1[i] * array2[i];
    }
    return sum;
}

double sigma_x1x2(double x1x2, double x1, double x2, int count) {
    return x1x2 - ((x1 * x2) / count);
}

double gaussianElimination(double mat[NOK][NOK+1], double *gaussian_elimination)
{
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat);

    /* if matrix is singular */
    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");

        /* if the RHS of equation corresponding to
        zero row is 0, * system has infinitely
        many solutions, else inconsistent*/
        if (mat[singular_flag][NOK])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return 0;
    }

    /* get solution to system and print it using
    backward substitution */
    return backSub(mat, gaussian_elimination);
}

// function for elementary operation of swapping two rows
void swap_row(double mat[NOK][NOK+1], int i, int j)
{
    //printf("Swapped rows %d and %d\n", i, j);

    for (int k=0; k<=NOK; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// function to reduce matrix to r.e.f.
int forwardElim(double mat[NOK][NOK+1])
{
    for (int k=0; k<NOK; k++)
    {
        // Initialize maximum value and index for pivot
        int i_max = k;
        int v_max = mat[i_max][k];

        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < NOK; i++)
            if (fabs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;

        /* if a principal diagonal element is zero,
        * it denotes that matrix is singular, and
        * will lead to a division-by-zero later. */
        if (!mat[k][i_max])
            return k; // Matrix is singular

        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap_row(mat, k, i_max);


        for (int i=k+1; i<NOK; i++)
        {
            /* factor f to set current row kth element to 0,
            * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k];

            /* subtract fth multiple of corresponding kth
            row element*/
            for (int j=k+1; j<=NOK; j++)
                mat[i][j] -= mat[k][j]*f;

            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }

        //print(mat);	 //for matrix state
    }
    //print(mat);		 //for matrix state
    return -1;
}

// function to calculate the values of the unknowns
double backSub(double mat[NOK][NOK+1], double *gaussian_elimination)
{
    double x[NOK]; // An array to store solution

    /* Start calculating from last equation up to the
    first */
    for (int i = NOK-1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][NOK];

        /* Initialize j to i+1 since matrix is upper
        triangular*/
        for (int j=i+1; j<NOK; j++)
        {
            /* subtract all the lhs values
            * except the coefficient of the variable
            * whose value is being calculated */
            x[i] -= mat[i][j]*x[j];
        }

        /* divide the RHS by the coefficient of the
        unknown being calculated */
        x[i] = x[i]/mat[i][i];
    }

    //printf("\nSolution for the system:\n");
    for (int i=0; i<NOK; i++){
        //printf("%lf\n", x[i]);
        gaussian_elimination[i] = x[i];
    }
    return 0;
}