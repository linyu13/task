#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于指定数组元素的比较规则
int compare(const void *a, const void *b) {
    // 返回值为负数表示a在b之前，为正数表示a在b之后，为零表示a和b相等
    return (*(int *)a - *(int *)b);
}

int compare(const void *a, const void *b) {
    // 返回值为负数表示a在b之前，为正数表示a在b之后，为零表示a和b相等
    return (*(int *)a - *(int *)b);
}
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int k = numsSize - 1;
    for (int i = 0, j = numsSize - 1; i <= j;) { 
        // 注意这⾥要i <= j，因为最后要处理两个元素
        if (nums[i] * nums[i] < nums[j] * nums[j]) {
            returnSize[k--] = nums[j] * nums[j];
            j--;
        } else {
            returnSize[k--] = nums[i] * nums[i];
            i++;
        }
    }
    return returnSize;
}
int main() {
    int array[] = {-4, -1, 0, 3, 10};
    int *arr;
    sortedSquares(array, 4, arr);

    // 排序后的数组
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}