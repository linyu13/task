#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, temp, a[11];
    int seeds;

    for (seeds = 1; seeds < 11; seeds++)
    {
        printf("第%d次随机:\n", seeds);
        srand(seeds);//另一种随机函数
        for (i = 0; i < 11; i++)
        {
            a[i] = 0;
        }
        for (i = 0; i < 1000; i++)
        {
            temp = rand() % 10 + 1;
            a[temp]++;
        }
        for (i = 1; i < 11; i++)
        {
            printf("%d出现了%d次\n", i, a[i]);
        }
    }

    return 0;
}
