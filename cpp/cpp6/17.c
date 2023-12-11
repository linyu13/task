#include <stdio.h>
int main() {
    double total = 100;
    int cnt = 0;
    while (total > 0) {
        total = total * (1 + 0.08);
        total -= 10;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}