#include <stdio.h>
#include <string.h>
int main() {
    char ch = 0;
    char prech = 0;
    int n = 0;
    while ((ch = getchar()) != '#') {
        if ((prech == 'e') && (ch == 'i')) {
            n++;
        }
        prech = ch;
    }
    printf("ei出现次数:%d\n", n);
    return 0;
}