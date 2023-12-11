#include <stdio.h>
int main(void) {
    int high = 100;
    int low = 1;
    int guess = (high + low) / 2;
    char n;
    printf("你想的数是%d吗?\n", guess);
    while ((n = getchar()) != 'y') {
        if (n == '\n')
            continue;
        if ((n != 'h') && (n != 'l')) {
            printf("??????????????\n");
            continue;
        }
        if ((low >= 1) && (high <= 100) && (high >= low)) {
            if (n == 'h') {
                high = guess - 1;
            }
            if (n == 'l') {
                low = guess + 1;
            }
        }
        guess = (high + low) / 2;
        if ((guess >= 1) && (guess <= 100)) {
            printf("所以你想的数是%d吗?\n", guess);
        }
    }
    return 0;
}