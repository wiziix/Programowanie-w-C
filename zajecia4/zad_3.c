#include <stdio.h>

void swap(int *arr, int x, int y) {
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void permute(int *array, int start, int end) {
  
    if (start == end) {
        for (int i = 0; i <= end; i++) {
           printf("%d ", array[i]); 
        }
        printf("\n");   
    }
    
    for (int i = start; i <= end; i++) {
            swap(array, start, i);    
            permute(array, start + 1, end); 
            swap(array, start, i); 
    }    
}


int main()
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    permute(arr, 0, size - 1);    
}
