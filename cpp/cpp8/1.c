#include <stdio.h>
int main() {
    int count = 0;
    int ch;
    while ((ch = getchar()) != EOF)
        count++;
    printf("共%d个字符\n", count);
    return 0;
}