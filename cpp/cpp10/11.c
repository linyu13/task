#include<stdio.h>
void double_arr(int arr[][5]);
void print_arr(int arr[][5]);
int main()
{
    int arr[3][5]={1,1,4,5,1,4,1,9,1,9,8,1,0,1,1};
    print_arr(arr);
    double_arr(arr);
    print_arr(arr);
    return 0;
}

void double_arr(int arr[][5])
{
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            arr[i][j]*=2;
        }
    }
    return;
}

void print_arr(int arr[][5])
{
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            printf("%d\t",arr[i][j]);
        }
        putchar('\n');
    }
}