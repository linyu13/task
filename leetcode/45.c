#include <stdio.h>
int jump(int *nums, int numsSize) {
    int start = 0;
    int end = 1;
    int ans = 0;
    while (end < numsSize) {
        int maxpos = 0;
        for (int i = start; i < end; i++) {
            if (i + nums[i] > maxpos) {
                maxpos = i + nums[i];
            }
        }
        start = end;
        end = maxpos + 1;
        ans++;
    }
    return ans;
}
int main() {
    int nums[]={2,3,1,1,4};
    jump(nums,5);
}