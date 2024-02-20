#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 200; i++) {
        if (i % 7 == 0 && i % 5 == 0) {
            printf("FooBar\n");
        }
        else if (i % 7 == 0) {
            printf("Bar\n");
        }
        else if (i % 5 == 0) {
            printf("Foo\n");
        }
        else {
            printf("%d\n", i);
        }
    }
}