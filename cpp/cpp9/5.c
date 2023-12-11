#include<stdio.h>
void larger_of(double *x,double *y)
{
    if(*x>*y){
        *y=*x;
    }else{
        *x=*y;
    }
    return ;
}
int main()
{
    double x=0,y=0;
    scanf("%lf%lf",&x,&y);
    larger_of(&x,&y);
    printf("%lf %lf\n",x,y);
    return 0;
}