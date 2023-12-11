#include<stdio.h>
#define harm_average(a,b) 1.0/(1.0/a+1.0/b)
int main()
{
    int a=0,b=0;
    scanf("%d%d",&a,&b);
    double harm_aver=0;
    harm_aver=harm_average(a,b);
    printf("%.2lf\n",harm_aver);
    return 0;
}