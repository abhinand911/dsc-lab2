#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
void main(){
    int n1,n2;
    printf("enter two numbers");
    scanf("%d %d",&n1,&n2);
    printf("GCD of %d and %d is %d",n1,n2,gcd(n1,n2));
}