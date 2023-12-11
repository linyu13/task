#include <stdio.h>
int main() {
    const int a = 60;
    int n = 0, m = 0;
    int b = 0;
    scanf("%d", &b);
    while (b > 0) {
        n = b / a;
        m = b % a;
        printf("%02d:%02d", n, m);
        scanf("%d", &b);
    }
    return 0;
}