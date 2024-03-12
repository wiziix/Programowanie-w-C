#include <stdio.h>

int binarySearch(int arr[], int leftIndex, int rightIndex, int value) { 
    
    if (rightIndex >= leftIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        if (arr[middleIndex] == value) {
            return middleIndex;
        }
        
        if (arr[middleIndex] > value) {
            return binarySearch(arr, leftIndex, middleIndex - 1, value);
        }
        
        return binarySearch(arr, middleIndex + 1, rightIndex, value);
    }
    
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, 10);
    
    printf("%d", result);
}
