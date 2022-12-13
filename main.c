#include "stdio.h"
#include "csvReader.h"
#include "regression.h"

#define NOK 6
#define N 783

int main()
    {
        CSVFILE file;
        char *dataset = "/Users/macbookair/Collage/Logika dan Algoritma/Regresi Linear Berganda/dataset.csv";
        double x1[N], x2[N], x3[N], x4[N], x5[N], x6[N], y[N];
        double y_hat;
        int index = 1;

        if(csvOpen(&file, dataset)) {
            while(csvReadLine(&file)){
                x1[index] = file.GetField(&file, "Attack");
                x2[index] = file.GetField(&file, "Defense");
                x3[index] = file.GetField(&file, "Sp. Atk");
                x4[index] = file.GetField(&file, "Sp. Def");
                x5[index] = file.GetField(&file, "Speed");
                x6[index] = file.GetField(&file, "Generation");
                y[index] = file.GetField(&file, "Win Percentage");
                index++;
            }
        }

        struct multiple_linear_regression regression;

        regression.n = N;

        linear_regression(x1, x2, x3, x4, x5, x6, y, &regression);

        printf("Model Regresi Linear Berganda: \n");
        printf("y = %f + (%f)x1 + (%f)x2 + (%f)x3 + (%f)x4 + (%f)x5 + (%f)x6\n\n", regression.result.b0, regression.result.b1, regression.result.b2, regression.result.b3, regression.result.b4, regression.result.b5, regression.result.b6);

        printf("Diketahui variabel independen: \n");
        printf("x1 [Attack] = %f\n", x1[1]);
        printf("x2 [Defense] = %f\n", x2[1]);
        printf("x3 [Sp. Atk] = %f\n", x3[1]);
        printf("x4 [Sp. Def] = %f\n", x4[1]);
        printf("x5 [Speed] = %f\n", x5[1]);
        printf("x6 [Generation] = %f\n", x6[1]);
        printf("Berdasarkan data diatas, berapakah presentase kemenangan pokemon tersebut? \n\n");

        printf("Substitusi nilai variabel independen ke dalam model machine learning: \n");
        printf("y = %f + (%f)(%f) + (%f)(%f) + (%f)(%f) + (%f)(%f) + (%f)(%f) + (%f)(%f)\n", regression.result.b0, regression.result.b1, x1[1], regression.result.b2, x2[1], regression.result.b3, x3[1], regression.result.b4, x4[1], regression.result.b5, x5[1], regression.result.b6, x6[1]);
        y_hat = predict(&regression, x1[1], x2[1], x3[1], x4[1], x5[1], x6[1]);
        printf("Jadi presentase kemenangan pokemon tersebut adalah sebanyak %2f persen\n", y_hat * 100);


        return 0;
    }