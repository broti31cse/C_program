 /*
 wap in c to take input number in A(2*2) and B(2*2) matrix.Find the sum of A & B and store in  C(2*2)
matrix.Print A,B,C

 */
 #include<stdio.h>
void input( int D[2][2]){
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    scanf("%d",&D[i][j]);
}
void add(int A[2][2], int B[2][2], int C[2][2]){
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    C[i][j]=A[i][j]+B[i][j];
}
void display(int D[2][2]){
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    printf("%d",D[i][j]);
    printf("\n");
}
int main(){
    int A[2][2],B[2][2],C[2][2];
    printf("Enter elements of A\n");
    input(A);
    printf("Enter elements of B\n");
    input(B);
    add(A,B,C);
        printf("\n Matrix A:\n");
        display(A);
         printf("\n Matrix B :\n");
         display(B);
         printf("\n Matrix C :\n");
         display(C);
    return 0;  
}