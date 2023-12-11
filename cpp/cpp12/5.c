#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sort(int a[], int n);
void printarray(const int a[], int n);
int main()
{
    int i, a[101];
    srand((unsigned int)time(0));//重置随机数
    for (i = 0; i < 101; i++)
    {
        a[i] = rand() % 10 + 1;
    }
    printf("数组:\n");
    printarray(a, 101);
    sort(a, 101);
    printf("排序后的数组:\n");
    printarray(a, 101);
    return 0;
}

void sort(int a[], int n)//冒泡
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
    return;
}

void printarray(const int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%-3d ", a[i]);
        if (0 == (i + 1) % 10)
        {
            putchar('\n');
        }
    }
    putchar('\n');
    return;
}