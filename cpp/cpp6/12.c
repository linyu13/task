#include <stdio.h>

int main() {
    int n = 0;
    double sum1 = 0;
    double sum2 = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        sum1 += 1.0 / (i + 1);
        sum2 += (i % 2 == 0 ? 1 : -1) * 1.0 / (i + 1);
    }
    
    printf("%.2lf\n%.2lf\n", sum1, sum2);
    
    return 0;
}
