#include <stdio.h>
#include <stdlib.h>
/*整体思想：
先对数组进行排序
排序之后定义两个连续的下标指针
对后续的所有数组内容进行比较
使用二分法查找能够组成有效三角形的极限下标
计算有效的个数并更新之前的连续下标的位置
*/
int cmp(int *a, int *b) { return *a - *b; }
int triangleNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int left = j + 1;
            int right = numsSize - 1;
            int k = j;
            while (left <= right) {
                int mid = (left + right) /
                          2; // 二分实现快速查找排序后的能实现三角形的个数
                if (nums[mid] < nums[i] + nums[j]) {
                    k = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            cnt += k - j;
        }
    }
    return cnt;
}
int main() {
    int nums[] = {2, 2, 3, 4};
    int a = triangleNumber(nums, 4);
    printf("%d\n", a);
    return 0;
}