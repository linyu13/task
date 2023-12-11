#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int main() {
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char name[SIZE];
    printf("输入文件名:");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL) {
        printf("无法打开该文件\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        ++count;
    }
    fclose(fp);
    printf("\n文件 %s 有 %lu 个用户.", name, count);
    return 0;
}