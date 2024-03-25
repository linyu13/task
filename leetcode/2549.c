#include <stdio.h>

int distinctIntegers(int n)
{
    int cnt = 1;
    int hash[10000] = { 0 };
    hash[n] = 1;
    int i = n;

    while (i >= 2) {
        for (int j = 2; j < n; j++) {
            if (i % j == 1) {
                if (!hash[j]) {
                    cnt++;
                }
                hash[j] = 1;
            }
        }
        i--;
    }

    return cnt;
}
int main()
{
    printf("%d\n", distinctIntegers(5));
    return 0;
}
