#include<stdio.h>
double power(double num,int n);
int main()
{
    int num=0;
    int n=0;
    scanf("%d%d",&num,&n);
    double sum=(num,n);
    printf("%lf\n",sum);
    return 0;
}

double power(double num,int n)
{
    if(n==1){
        return num;
    }
    double sum=1;
    sum*=power(num,n-1);

}