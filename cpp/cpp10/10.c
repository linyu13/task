#include <stdio.h>
void add_arr(int *arr1, int *arr2, int *arr3);
int main() {
    int arr1[] = {1, 1, 4, 5, 1, 4};
    int arr2[] = {1, 9, 1, 9, 8, 1};
    int arr3[10]={0};
    int i = 0;
    add_arr(arr1, arr2, arr3);
    while (arr3[i] != '\0') {
        printf("%d\n", arr3[i]);
        i++;
    }
    return 0;
}

void add_arr(int *arr1, int *arr2, int *arr3) {
    int i = 0;
    while (arr1[i] != '\0' && arr2[i] != '\0') {
        arr3[i] = arr1[i] + arr2[i];
        i++;
    }
    return;
}