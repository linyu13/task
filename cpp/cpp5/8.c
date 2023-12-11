#include <stdio.h>
int main() {
    int n = 0, m = 0;
    int a = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    while (m > 0) {
        a = m % n;
        printf("%d\n", a);
        scanf("%d", &m);
    }
    return 0;
}