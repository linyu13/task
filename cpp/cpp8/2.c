#include <stdio.h>
int main() {
    char ch = 0;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        if (ch < ' ') {
            if (ch == '\n')
                printf("\\n:%d ", ch);
            else if (ch == '\t')
                printf("\\t:%d ", ch);
            else
                printf("^%c:%d ", ch + 64, ch);
        } else {
            printf("%c:%d ", ch, ch);
        }
        count++;
        if (count % 10 == 0) {
            printf("\n");
        }
    }
    return 0;
}