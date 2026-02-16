#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix elements
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of primary diagonal
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    // Output result
    printf("%d", sum);

    return 0;
}
