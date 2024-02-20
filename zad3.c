#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i;
    int j;
    int factorial;

    for (i = 0; i < 10; i++) {
        factorial = array[i];
        for (j = 0; j < i; j++) {
            factorial *= array[j];
        }
        printf("%d\n", factorial);
    }

}