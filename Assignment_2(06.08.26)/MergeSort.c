/* Write a program to take input marks of 10 student randomly in an array .Sort the array using mergeSort and show the highest and 
lowest marks
input:size of array:10
[80,73,59,92,86,47,92,58,91,48]*/
#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[10];

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[10] = {80, 73, 59, 92, 86, 47, 92, 58, 91, 48};
    int i;

    printf("Original Marks:\n");
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, 9);

    printf("\n\nSorted Marks:\n");
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n\nLowest Marks = %d", arr[0]);
    printf("\nHighest Marks = %d", arr[9]);

    return 0;
}