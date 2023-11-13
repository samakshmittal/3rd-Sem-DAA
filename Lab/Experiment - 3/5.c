#include <stdio.h>

#define N 4

void printMatrix(char* display, int matrix[N][N]) {
    printf("\n%s =>\n", display);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void strassen(int A[N][N], int B[N][N], int C[N][N]) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int size = N / 2;
    int A11[size][size], A12[size][size], A21[size][size], A22[size][size];
    int B11[size][size], B12[size][size], B21[size][size], B22[size][size];
    int C11[size][size], C12[size][size], C21[size][size], C22[size][size];
    int P1[size][size], P2[size][size], P3[size][size], P4[size][size], P5[size][size], P6[size][size], P7[size][size];
    int temp1[size][size], temp2[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size];
            A21[i][j] = A[i + size][j];
            A22[i][j] = A[i + size][j + size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size];
            B21[i][j] = B[i + size][j];
            B22[i][j] = B[i + size][j + size];
        }
    }

    strassen(A11, B11, P1);
    strassen(A12, B21, P2);
    strassen(A11, B12, P3);
    strassen(A12, B22, P4);
    strassen(A21, B11, P5);
    strassen(A22, B21, P6);
    strassen(A21, B12, P7);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

int main() {
    int A[N][N] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {2, 2, 2, 2}
    };

    int B[N][N] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {2, 2, 2, 2}
    };

    int C[N][N];

    strassen(A, B, C);

    printMatrix("Matrix A", A);
    printMatrix("Matrix B", B);
    printMatrix("Matrix C (Result)", C);

    return 0;
}
