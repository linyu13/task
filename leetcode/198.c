#include <stdio.h>
int rob(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int n = numsSize;
    int dp[200] = {0};
    dp[0] = nums[0];
    if (nums[0] > nums[1]) {
        dp[1] = nums[0]; // 记录前两个比较大的金额
    } else {
        dp[1] = nums[1];
    }
    for (int i = 2; i < n; i++) {
        if (dp[i - 2] + nums[i] >
            dp[i -
               1]) { // 判断该点位的金钱和前两个的金钱和前两个地方所能得到的金钱
            dp[i] = dp[i - 2] + nums[i];
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[n -
              1]; // 动态规划！！！！！！！！！！！！！！！！！！！！！！！！！
}
int main() {
    int nums[] = {1, 2, 3, 1};
    rob(nums, 4);
}