#include<stdio.h>
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
void main(){
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int y=fact(x);
    printf("Factorial of %d is %d",x,y);
}