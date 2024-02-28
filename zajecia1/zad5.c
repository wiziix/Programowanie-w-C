#include <stdio.h>

int Average(int num) {
    if (num < 0) {
        return 0;
    }
    else {

        int i;
        int sum = 0;
        for (i = 1; i < num; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                sum += i;
            }
            else if (i % 5 == 0 || i % 3 == 0) {
                sum += i;
            }
        }
        return sum;
    }
}

int main() {    
    printf("%d", Average(24));
}

