#include <stdio.h>
#include <stdlib.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int right = numsSize - 1;
    int left = 0;
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    int i;
    for (i = numsSize - 1; i >= 0; i--) {
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
            ans[i] = nums[left] * nums[left];
            left++;
        } else {
            ans[i] = nums[right] * nums[right];
            right--;
        }
    }
    return ans;
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