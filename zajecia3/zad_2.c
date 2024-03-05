#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int rows, int columns) {
    int i, j;
    
    // alokacja pamieci dla tablicy dwuwymiarowej
    int **arr = (int **) malloc(rows * sizeof(int *));
    
    for(i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(columns * sizeof(int));
    }
    
    //wypelnianie tablicy losowymi wartosciami
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            arr[i][j] = rand();
        }
    }
    
    //wyswietlanie wypelnionej tablicy
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    //zwalnianie pamieci
    for (int i = 0; i < columns; i++) {
        free(arr[i]);
    }
    free(arr);

}

int main() {
    int rows, columns;
    srand(time(NULL));
    
    printf("Enter Number of Rows: ");
    scanf("%d", &rows);
    printf("Enter Number of Columns: ");
    scanf("%d", &columns);
    
    generateArray(rows, columns);
}
