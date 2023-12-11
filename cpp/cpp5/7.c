#include <stdio.h>
double cube(double n);
int main() {
    double num = 0;
    scanf("%lf", &num);
    double num_cube = 0;
    num_cube = num * num * num;
    printf("num_cube=%.2lf\n", num_cube);
    cube(num);
    return 0;
}

double cube(double n) {
    double cube = 0;
    cube = n * n * n;
    printf("cube=%.2lf\n", cube);
}