#include <stdio.h>
void strassen(int A[][2], int B[][2], int C[][2]) {//definnig all formaulae given by strssn
    int i, j;
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}
int main() {
    int n;
    printf("Enter the order of the matrices (n): ");//taking user input for order
    scanf("%d", &n);
    int A[n][n], B[n][n], C[n][n];
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; i++) {//taking elmnts of frst matrix
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++) {//taking elemnts of second matrix
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassen(A, B, C);//calling funcition and priting values
    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t\t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}