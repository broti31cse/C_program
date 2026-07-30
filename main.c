#include<stdio.h>
int main(){
    int num, temp, rem,sum=0;
    printf("Enter a num:\n");
    scanf("%d",&num);
    temp=num;
    while(temp!=0){
        rem=temp%10;
        sum=sum+(rem*rem*rem);
        temp=temp/10;
    }
    if(sum==num)
        printf("%d is Armstrong",num);
    else
        printf("%d is not armstrong",num);
    return 0;
}