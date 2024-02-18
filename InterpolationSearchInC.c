#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int interpolationSearch(int array[], int size, int value) {
    int high = size - 1;
    int low = 0;

    while (value >= array[low] && value <= array[high] && low <= high) {
        int probe = low + ((double)(high - low) * (value - array[low])) / (array[high] - array[low]);
        if (array[probe] == value) {
            return probe;
        } else if (array[probe] < value) {
            low = probe + 1;
        } else {
            high = probe - 1;
        }
    }

    return -1;
}
/*
int compare(const void *a, const void *b) {
    double double_a = *((double*)a);
    double double_b = *((double*)b);

    if (double_a < double_b) return -1;
    if (double_a > double_b) return 1;
    return 0;
}
*/

int* createUniformArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100; // 0 ile 100
    }

    return array;
}


int compare(const void *a, const void *b)
{
    int value_a = *((int*)a);
    int value_b = *((int*)b);

    if (value_a < value_b) return -1;
    if (value_a > value_b) return 1;
    return 0;
}

void PrintArray(int* arr, size_t size)
{
    for(size_t i = 0; i<size;i++)
        printf(" %d ",arr[i]);
    printf("\n---------\n");
}

int main()
{
    /*int arr[] = { 8,-1,998,885,61,68,48,285,77,55,10, 12, 99,13,1204,255 ,16,995 ,18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47,-999,-9,-10,0,55,988,22,2585,-3,-21,-55,-45 };
                  */
    int n = 0;
    printf("Array size: ");
    scanf("%d",&n);
    int* arr = createUniformArray(n);
    assert(n>10);

    int x = arr[11]; // Element to be searched

    PrintArray(arr,n);
    if(!isSorted(arr,n)){
        printf("Sorting Operation\n");
        qsort(arr,n,sizeof(int),compare);
        PrintArray(arr,n);
    }

    int index = interpolationSearch(arr,n,x);
    if (index != -1)
        printf("Element found at index %d, arr=%d ", index,arr[index]);
    else
        printf("Element not found.");
    return 0;
}