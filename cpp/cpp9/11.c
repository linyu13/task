#include <stdio.h>
int Fibonacci(int n);
int main() {
    int n = 0;
    scanf("%d", &n);
    int sum = Fibonacci(n);
    printf("%d\n", sum);
    return 0;
}

int Fibonacci(int n) {
    int num = 0;
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        Fibonacci(n - 1);
        return 1;
    }
    if (n > 2) {
        num = Fibonacci(n - 1) + Fibonacci(n - 2);
    }
    return num;
}