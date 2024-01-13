#include <stdio.h>
// int minSubArrayLen(int target, int *nums, int numsSize) {
//     // 初始化最小长度为INT_MAX
//     int minLength = 0;
//     int sum;

//     int left, right;
//     for (left = 0; left < numsSize; ++left) {
//         // 每次遍历都清零sum，计算当前位置后和>=target的子数组的长度
//         sum = 0;
//         // 从left开始，sum中添加元素
//         for (right = left; right < numsSize; ++right) {
//             sum += nums[right];
//             // 若加入当前元素后，和大于target，则更新minLength
//             if (sum >= target) {
//                 int subLength = right - left + 1;
//                 minLength = minLength < subLength ? minLength : subLength;
//             }
//         }
//     }
//     // 若minLength不为INT_MAX，则返回minLnegth
//     return minLength;
// }

int minSubArrayLen(int target, int *nums, int numsSize) {
    // 初始化最小长度为100000
    int minLength = 100000;
    int sum = 0;

    int left = 0, right = 0;
    // 右边界向右扩展
    for (; right < numsSize; ++right) {
        sum += nums[right];
        // 当sum的值大于等于target时，保存长度，并且收缩左边界
        while (sum >= target) {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }
    // 若minLength不为100000，则返回minLnegth
    return minLength == 100000 ? 0 : minLength;
}

int main()
{
    int nums[]={2,3,1,2,4,3};
    minSubArrayLen(7,nums,6);
}