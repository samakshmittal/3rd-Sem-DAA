#include <stdio.h>
void add(int A[][256], int B[][256], int C[][256], int n) {                               // Defining function to add two matrices
    for (int i = 0; i < n; i++) {                                                         // n+1 times
        for (int j = 0; j < n; j++) {                                                     // n(n+1) times
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtract(int A[][256], int B[][256], int C[][256], int n) {                          // Defining function to subtract two matrices
    for (int i = 0; i < n; i++) {                                                         // n+1 times
        for (int j = 0; j < n; j++) {                                                     // n(n+1) times
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void combineSubmatrices(int C11[][256], int C12[][256], int C21[][256], int C22[][256], int C[][256], int n) {   // Defining function to combine submatrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
    }
}
void strassenMatrixMultiplication(int A[][256], int B[][256], int C[][256], int n) {      // Defining function to perform Strassen's matrix multiplication
    int i , j;
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    // if(n == 2){
    //     C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    //     C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    //     C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    //     C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    // }
    int newSize = n / 2;                                                                  // Divide matrices into submatrices
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize], B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize], C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize], M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize], temp1[newSize][newSize], temp2[newSize][newSize];    // Initializing matrix A, B, C, M1 to M7, 2 temporary matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {                                               // Divide matrices into submatrices
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    printf("A11 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", A11[i][j]);
        }
        printf("\n");
    }

    printf("A12 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", A12[i][j]);
        }
        printf("\n");
    }

    printf("A21 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", A21[i][j]);
        }
        printf("\n");
    }

    printf("A22 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", A22[i][j]);
        }
        printf("\n");
    }

    printf("B11 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", B11[i][j]);
        }
        printf("\n");
    }
    
    printf("B12 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", B12[i][j]);
        }
        printf("\n");
    }
    
    printf("B21 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", B21[i][j]);
        }
        printf("\n");
    }

    printf("B22 : ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", B22[i][j]);
        }
        printf("\n");
    }

    subtract(B12, B22, temp1, newSize);
    strassenMatrixMultiplication(A11, temp1, M1, newSize);                                // Finding M1

    add(A11, A12, temp1, newSize);
    strassenMatrixMultiplication(temp1, B22, M2, newSize);                                // Finding M2

    add(A21, A22, temp2, newSize);
    strassenMatrixMultiplication(temp2, B11, M3, newSize);                                // Finding M3

    subtract(B21, B11, temp2, newSize);
    strassenMatrixMultiplication(A22, temp2, M4, newSize);                                // Finding M4

    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M5, newSize);                              // Finding M5

    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M6, newSize);                              // Finding M6

    subtract(A11, A21, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M6, newSize);                              // Finding M7

    add(M5, M4, temp1, newSize);
    subtract(temp1, M2, temp2, newSize);
    add(temp2, M6, C11, newSize);                                                         // Finding C11

    add(M1, M2, C12, newSize);                                                            // Finding C12

    add(M3, M4, C21, newSize);                                                            // Finding C21

    add(M1, M5, temp1, newSize);
    add(temp1, M3, temp2, newSize);
    add(temp2, M7, C22, newSize);                                                         // Finding C22

    combineSubmatrices(C11, C12, C21, C22, C, newSize);
}
int main(){
    int n, i, j;
    printf("Enter size of matrix nxn where n is 2^n");
    scanf("%d", &n);
    int A[n][n], B[n][n], C[n][n];
    printf("Enter data in Matrix A");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Enter A[%d][%d]", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Enter B[%d][%d]", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    strassenMatrixMultiplication(A, B, C, n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}