#include <stdio.h>

int main() {
    float grades[2][5] = {
    {3, 4, 4, 5, 3.5},
    {3, 3, 5, 5, 4.5}
    };
    int i;
    int j;
    float avgMath = 0;
    float avgPhys = 0;

    for (i = 0; i < 5; i++) {
        avgMath += grades[0][i];
        avgPhys += grades[1][i];
    }

    printf("Srednia z matematyki wynosi: %.2f\n", avgMath / 5);
    printf("Srednia z fizyki wynosi: %.2f\n", avgPhys / 5);
}
