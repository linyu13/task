#include <stdio.h>
#include <stdlib.h>
#define MAX 81
int main() {
    FILE *fp;
    char words[MAX];
    int n = 1;
    if ((fp = fopen("wordy.txt", "a+")) == NULL) {
        fprintf(stderr, "无法打开 wordy.txt\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(words, MAX, fp) != NULL)
        ++n;
    puts("输入要添加的内容,按'#'结束");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d %s\n", n++, words);
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        printf("%s", words);
    puts("结束!");
    if (fclose(fp) != 0)
        fprintf(stderr, "打开错误\n");
    return 0;
}