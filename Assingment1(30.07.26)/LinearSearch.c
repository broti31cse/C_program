#include <stdio.h>
void linearSearch(int arr[], int n, int key)
{
    int count=0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            count++;
    }
    if(count==1){
        printf("The book is avilable");
    }
    else{
        printf("The book is not avilable");
    }
}

int main()
{
    int arr[] = {101,20,49,385,210,620,85,921,12,206};
    int key;

    printf("Enter access number: ");
    scanf("%d",&key);

     linearSearch(arr,10,key);

    return 0;
}