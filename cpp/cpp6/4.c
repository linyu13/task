#include <stdio.h>
int main() {
    int i = 0;
    int j = 0;
    char a = 'A';
    int cnt = 0;
    for (i = 1; i <= 6; i++) {
        for (j = 0; j <= cnt; j++) {
            printf("%c", a);
            a++;
        }
        printf("\n");
        cnt++;
    }
}