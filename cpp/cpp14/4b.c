#include <stdio.h>
#include <string.h>
#define LEN 20
struct names {
    char first[LEN];
    char center[LEN];
    char last[LEN];
};
struct guy {
    unsigned int sty;
    struct names handle;
};
void Print(const struct guy *p);
int main() {
    struct guy ifm[5] = {{
                             114514,
                             {.first = "si", .last = "li"},
                         },
                         {
                             415411,
                             {"san", .last = "zhang"},
                         },
                         {
                             1919810,
                             {"Zi", "Zheng", "Cai"},
                         },
                         {
                             189191,
                             {"Yi", "Xin", "Wang"},
                         },
                         {
                             1145141919,
                             {"Y", .last = "L"},
                         }};

    Print(ifm);
    return 0;
}
void Print(const struct guy p[]) // 传递个值 这是个副本
{
    int i;
    for (i = 0; i < 5; i++) {
        if (strlen((p + i)->handle.center) == 0)
            printf("%s.%s -- %d\n", (p + i)->handle.last, (p + i)->handle.first,
                   (p + i)->sty);
        else
            printf("%s.%s %c. -- %d\n", (p + i)->handle.last,
                   (p + i)->handle.first, (p + i)->handle.center[0],
                   (p + i)->sty);
    }
}