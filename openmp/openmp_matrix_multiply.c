#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500

double A[N][N];
double B[N][N];
double C[N][N];

int main() {

    // Initialize matrices
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0.0;
        }
    }

    double start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end = omp_get_wtime();

    printf("Matrix multiplication completed in %f seconds\n", end-start);

    return 0;
}
