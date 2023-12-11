#include <stdio.h>
static int cnt = 0;
int cnt_cnt();
int main()
{
    int i, j, k;
    scanf("%d", &i);

    for (j = 1; j <= i; j++)
    {
        printf("cnt = %d\n", cnt_cnt());
    }
    printf("调用%d\n", cnt);

    return 0;
}
int cnt_cnt()
{
    cnt++;
    return cnt;
}
