// C-Programming Assignment Task-01(Linear Regression)
// Student Id : 2358196
// Name : Avimanyu Rimal

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to read data from a file and update the sums and count
void read_data(FILE *fptr, float *sum_X, float *sum_Y, float *sum_XY, float *sum_Xsq, int *n);

int main()
{
    // Array of file pointers for the four datasets
    FILE *fptr[4];
    fptr[0] = fopen("datasetLR1.txt", "r");
    fptr[1] = fopen("datasetLR2.txt", "r");
    fptr[2] = fopen("datasetLR3.txt", "r");
    fptr[3] = fopen("datasetLR4.txt", "r");

    // Initialize variables for sums and calculations
    int n = 0;
    float sum_X = 0;
    float sum_Y = 0;
    float sum_XY = 0;
    float sum_Xsq = 0;
    float calc_A, calc_B, y_Pred, user_x;

    // Loop through each dataset and update sums
    for (int i = 0; i < 4; i++)
        read_data(fptr[i], &sum_X, &sum_Y, &sum_XY, &sum_Xsq, &n);

    // Calculate linear regression coefficients
    calc_A = ((sum_Y * sum_Xsq) - (sum_X * sum_XY)) / ((n * sum_Xsq) - pow(sum_X, 2));
    calc_B = ((n * sum_XY) - (sum_X * sum_Y)) / ((n * sum_Xsq) - pow(sum_X, 2));

    // Display the calculated coefficients
    printf("A = %0.2f\n", calc_A);
    printf("-------------------------------------\n");
    printf("B = %0.2f\n", calc_B);
    printf("-------------------------------------\n");
    printf("The linear equation obtained from the given calculation is : %0.2fx + %0.2f\n", calc_B, calc_A);
    printf("-------------------------------------\n");

    // Get user input for x coordinate to predict y
    printf("\nEnter x coordinate to predict y: ");
    scanf("%f", &user_x);
    printf("-------------------------------------\n");

    // Calculate and display the predicted y value
    y_Pred = calc_B * user_x + calc_A;
    printf("-------------------------------------\n");
    printf("The value of x = %0.2f", user_x);
    printf("\nThe predicted result is y = %0.2f\n", y_Pred);
    printf("-------------------------------------\n");

    // Close all file pointers
    for (int i = 0; i < 4; i++)
        fclose(fptr[i]);

    return 0;
}

// Function to read data from a file and update the sums and count
void read_data(FILE *fptr, float *sum_X, float *sum_Y, float *sum_XY, float *sum_Xsq, int *n)
{
    int x, y;
    // Read data from the file until the end of file is reached
    while (fscanf(fptr, "%d, %d", &x, &y) != EOF)
    {
        (*sum_X) += x;
        (*sum_Y) += y;
        (*sum_Xsq) += pow(x, 2);
        (*sum_XY) += (x * y);
        (*n)++;
    }
}

