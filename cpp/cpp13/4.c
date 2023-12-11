#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    int i;
    char ch;
    if (argc == 1) {
        fprintf(stderr, "输入文件名\n");
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "无法打开文件 %s", argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("文件 %s 内容为:\n", argv[i]);
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        printf("\n");
        fclose(fp);
    }
    printf("结束");
    return 0;
}