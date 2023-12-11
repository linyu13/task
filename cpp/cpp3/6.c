#include <stdio.h>
int main() {
    float quart = 0;
    scanf("%f", &quart);
    printf("%e\n", quart * 950 / (3e-23));
    return 0;
}