#include <stdio.h>
int searchInsert(int *nums, int numsSize, int target) {
    int i = 0;
    for (i = 0; i <= numsSize - 1; i++) {
        if (nums[i] > target) {
            break;
        }
    }
    return i;
}
int main() {
    int nums[] = {1, 3, 5, 6};
    int i=searchInsert(nums, 4, 5);
    printf("%d\n",i);
    return 0;
}