//Axel Rodriguez
#include <stdio.h>

//bubble sort
int bubbleSort(int arr[], int n) { 
    int i, j, temp;
    int count = 0;
    for (i = 0; i < n - 1; i++) {
         
        for (j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}
//selection sort
int selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    int count = 0;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 9;
    int bubbleArr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int selectionArr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int bSwaps = bubbleSort(bubbleArr1, n);
    int sSwaps = selectionSort(selectionArr1, n);
    printf("array1:\n");
    printf("Number of Bubble swaps: %d\n", bSwaps);
    printf("Number of Selection swaps: %d\n", sSwaps);
    
    int bubbleArr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int selectionArr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    bSwaps = bubbleSort(bubbleArr2, n);
    sSwaps = selectionSort(selectionArr2, n);
    printf("array2:\n");
    printf("Number of Bubble swaps: %d\n", bSwaps);
    printf("Number of Selection swaps: %d\n", sSwaps);
    return 0;
}
