#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int arr[10];
    
    
    for (i; i < 10; i++) {
        arr[i] = i;
    }
    
    int *intpointer = &arr[0];
    
    for(j; j < 10; j++) {

        
        printf("%d, ", *intpointer);
        
        intpointer++;
    }
    
    printf("\n");
}
