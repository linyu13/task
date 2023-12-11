#include <stdio.h>
#include <string.h>
#define CSIZE 4
#define NLEN 10
struct name {
    char first[NLEN];
    char last[NLEN];
};
struct student {
    struct name hm;
    float grade[3];
    float avg;
};
char *s_gets(char *st, int n);
void Print_ifm(const struct student *p, int n);
int main() {
    struct student guy[CSIZE];
    int count = 0;
    int i;
    puts("输入学生姓名:");
    while (count < CSIZE && s_gets(guy[count].hm.last, NLEN) != NULL &&
           guy[count].hm.last[0] != '\0') {
        puts("输入学生的名:");
        s_gets(guy[count].hm.first, NLEN);

        puts("输入他的三科成绩:");
        for (i = 0; i < 3; i++)
            scanf("%f", &guy[count].grade[i]);
        guy[count].avg =
            (guy[count].grade[0] + guy[count].grade[1] + guy[count].grade[2]) /
            3;
        while (getchar() != '\n')
            continue;
        puts("输入下一个学生的姓名1:");
        count++;
    }
    Print_ifm(guy, count);
    printf("总成绩:%-8.2f.", (guy[0].avg + guy[1].avg + guy[2].avg) / 3);
    return 0;
}
char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void Print_ifm(const struct student *p, int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%s %s:  exam1:%-8.2f exam2:%-8.2f exam3:%-8.2f  avg:%-5.2f.\n",
               (p + i)->hm.first, (p + i)->hm.last, (p + i)->grade[0],
               (p + i)->grade[1], (p + i)->grade[2], (p + i)->avg);
}