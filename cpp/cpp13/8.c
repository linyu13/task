#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
int main(int argc, char *argv[]) {
    FILE *fs;
    int files = 0;
    char ch;
    int count = 0;
    int i;
    if (argc == 2) {
        while ((ch = getchar()) != '\n')
            if (*argv[1] == ch) // 记得他是个指针类型 要解引用
                ++count;
        printf("出现了 %d 次", count);
    } else if (argc > 2) {
        for (i = 2; i < argc; i++, count = 0) // 重置count
        {
            if ((fs = fopen(argv[i], "r")) == NULL)
                fprintf(stderr, "无法打开 %s \n", argv[i]);
            else {
                while ((ch = getc(fs)) != EOF)
                    if (*argv[1] == ch)
                        ++count;
                if (ferror(fs) != 0)
                    fprintf(stderr, "读取时发生错误 %s.\n", argv[i]);
                fclose(fs);
                files++;
                printf("在文件 %s 中, '%c' 出现了 %d 次.\n", argv[i], *argv[1],
                       count);
            }
        }
        printf("结束");
    } else {
        fprintf(stderr, "请输入字符串和文件名\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}