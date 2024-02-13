#include <stdio.h>

int maxSubArray(int *nums, int numsSize) {
    int re = -100000;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > re) {
            re = sum;
        }
        if (sum <= 0) {
            sum = 0;
        }
    }
    return re;
}

int main() {
    int nums[]={-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n",maxSubArray(nums,9));
}