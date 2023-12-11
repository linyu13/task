#include <stdio.h>
int main() {
    char ch = 0;
    char a = 0;
    while ((ch = getchar()) != '#') {
        switch (ch) {
        case '.':
            ch = '!';
            a++;
        case '!':
            ch = '!!';
            a++;
            break;
        default:
            break;
        }
    }
    printf("%d 次\n", a);
    return 0;
}