#include "stdio.h"
#include "csvReader.h"
#include "regression.h"

int main()
    {
    #define N 782
    CSVFILE file;
        char *dataset = "/Users/macbookair/Collage/Logika dan Algoritma/Regresi Linear Berganda/dataset.csv";
        long double x1[N], x2[N], x3[N], x4[N], x5[N], x6[N], y[N];
        long double y_hat;
        int index = 0;

        if(csvOpen(&file, dataset)) {
            while(csvReadLine(&file)){
                x1[index] = file.GetField(&file, "Attack");
                x2[index] = file.GetField(&file, "Defense");
                x3[index] = file.GetField(&file, "Sp. Atk");
                x4[index] = file.GetField(&file, "Sp. Def");
                x5[index] = file.GetField(&file, "Speed");
                x6[index] = file.GetField(&file, "HP");
                y[index] = file.GetField(&file, "Win Percentage");
                index++;
            }
        }

        struct multiple_linear_regression regression;

        regression.n = N;

        linear_regression(x1, x2, x3, x4, x5, x6, y, &regression);

        printf("Tugas Besar: Logika dan Algoritma Semester 1\n");
        printf("Model Regresi Linear Berganda: \n");
        printf("y = %Lf + (%Lf)x1 + (%Lf)x2 + (%Lf)x3 + (%Lf)x4 + (%Lf)x5 + (%Lf)x6\n\n", regression.result.b0, regression.result.b1, regression.result.b2,
               regression.result.b3, regression.result.b4, regression.result.b5, regression.result.b6);

        printf("Input variabel independen: \n");
        double x1_input, x2_input, x3_input, x4_input, x5_input, x6_input;
        printf("x1 [Attack]: ");
        scanf("%lf", &x1_input);
        printf("x2 [Defense]: ");
        scanf("%lf", &x2_input);
        printf("x3 [Sp. Atk]: ");
        scanf("%lf", &x3_input);
        printf("x4 [Sp. Def]: ");
        scanf("%lf", &x4_input);
        printf("x5 [Speed]: ");
        scanf("%lf", &x5_input);
        printf("x6 [HP]: ");
        scanf("%lf", &x6_input);

        printf("Berdasarkan data diatas, berapakah presentase kemenangan pokemon tersebut? \n\n");

        printf("Substitusi nilai variabel independen ke dalam model machine learning: \n");
        printf("y = %Lf + (%Lf)(%f) + (%Lf)(%f) + (%Lf)(%f) + (%Lf)(%f) + (%Lf)(%f) + (%Lf)(%f)\n", regression.result.b0,
               regression.result.b1, x1_input, regression.result.b2, x2_input, regression.result.b3, x3_input,
               regression.result.b4, x4_input, regression.result.b5, x5_input,  regression.result.b6, x6_input);
        y_hat = predict(&regression, x1_input, x2_input, x3_input, x4_input, x5_input, x6_input);
        printf("Jadi presentase kemenangan pokemon tersebut adalah sebanyak %Lf persen\n", y_hat * 100);

        return 0;
    }