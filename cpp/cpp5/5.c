#include <stdio.h>
int main() {
    int count = 0, sum = 0;
    int n = 0;
    scanf("%d", &n);
    while (count++ < n) {
        sum += count;
    }
    printf("sum = %d\n", sum);
    return 0;
}