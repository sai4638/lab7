#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    int numswaps;
} element;

void swap(int *x, int *y, element* elements) {
    // Locate the elements in the array of structures
    int i = 0, j = 0;
    while (elements[i].data != *x) i++;
    while (elements[j].data != *y) j++;

    // Swap the data in the array and increment the swap count for each element
    int temp = *x;
    *x = *y;
    *y = temp;

    // Swap the corresponding elements in the swaps array
    element temp_element = elements[i];
    elements[i] = elements[j];
    elements[j] = temp_element;

    // Increment the swap count for each element
    elements[i].numswaps++;
    elements[j].numswaps++;
}


element* swapsBubbleSort(int arr[], int size) {
    element* swaps = (element*)malloc(sizeof(element)*size);
    for (int i = 0; i < size; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    for (int i = 0; i < size-1; i++) {     
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], swaps);
            }
        }
    }
    return swaps;
}

element* swapsSelectionSort(int arr[], int size) {
    element* swaps = (element*)malloc(sizeof(element)*size);
    for (int i = 0; i < size; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i], swaps);
        }
    }
    return swaps;
}

void printResults(element* elements, int size) {
    int total_swaps = 0;
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", elements[i].data, elements[i].numswaps);
        total_swaps += elements[i].numswaps;
    }
    printf("Total number of swaps: %d\n", total_swaps / 2); 
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int n2 = sizeof(array2)/sizeof(array2[0]);

    // Perform bubble sort and print results
    element *swaps_bubble1 = swapsBubbleSort(array1, n1);
    printf("array1 bubble sort:\n");
    printResults(swaps_bubble1, n1);
    free(swaps_bubble1);

    element *swaps_bubble2 = swapsBubbleSort(array2, n2);
    printf("\narray2 bubble sort:\n");
    printResults(swaps_bubble2, n2);
    free(swaps_bubble2);

    // Reset array to original order for selection sort
    int array1_original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2_original[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Perform selection sort and print results
    element *swaps_selection1 = swapsSelectionSort(array1_original, n1);
    printf("\narray1 selection sort:\n");
    printResults(swaps_selection1, n1);
    free(swaps_selection1);

    element *swaps_selection2 = swapsSelectionSort(array2_original, n2);
    printf("\narray2 selection sort:\n");
    printResults(swaps_selection2, n2);
    free(swaps_selection2);

    return 0;
}
