#include <stdio.h>
int search(double a[], int n);
void print_arr(double a[], int n);

int main()
{
    double t;
    int max;
    double array[] = {1.0, 4.0, 3.0, 2.0, 5.0};

    printf("数组内容是:\n");
    print_arr(array, 5);
    max = search(array, 5);
    printf("最大为%.2lf\n", array[max]);

    return 0;
}

int search(double a[], int n)
{
    int x = 0;
    double max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i], x = i;
        }
    }
    return x;
}

void print_arr(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-5.2lf", a[i]);
    }
    putchar('\n');
}
