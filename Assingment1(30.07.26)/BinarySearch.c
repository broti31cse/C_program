/* An online shop keeps its product catalogue sorted by Product ID (number) in ascending order. When a customer searches for a specific
Product ID, the system returns true if the Product ID is present in the catalogue; otherwise, it returns false. The system should return the Product 
ID quickly from the sorted catalogue. Which searching technique is used to find the Product 
ID quickly from the catalogue? Implement this searching method using a function. The function should take three parameters: Product ID list, size of the product list,
and the Product ID to be searched.
[2,8, 9, 16, 18, 26, 38, 48, 51, 90]*/

Case 1: Search 26
Case 2: Search 49 */
#include <stdio.h>
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(key > arr[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 8, 9, 16, 18, 26, 38, 49, 51, 90};
    int n = 10;
    int key, result;

    printf("Enter Product ID to be searched: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if(result != -1)
        printf("Product ID found at position %d", result + 1);
    else
        printf("Product ID not found");

    return 0;
}
