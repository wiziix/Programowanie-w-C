#include <stdio.h>
#include <stdlib.h>

void generatePascal(int n) {
    int i, j;

    // alokacja pamieci dla tablicy dwuwymiarowej
    int **pascal = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        pascal[i] = (int*)malloc( (i + 1) * sizeof(int));
    }

    // obliczanie wartosci trojkata Pascala
    for (i = 0; i < n; i++) {
        pascal[i][0] = 1;
        for (j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
        if (i != 0) {
            pascal[i][i] = 1;
        }
    }

    // wyswietlanie trojkata Pascala
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    // zwalnianie pamieci
    for (i = 0; i < n; i++) {
        free(pascal[i]);
    }
    free(pascal);
}

int main() {
    generatePascal(7);
}
