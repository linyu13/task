#include <stdio.h>
int removeElement(int *nums, int numsSize, int val) {
    int size = numsSize;
    for (int i = 0; i < size; i++) {
        if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动⼀位
            for (int j = i + 1; j < size; j++) {
                nums[j - 1] = nums[j];
            }
            i--; // 因为下标i以后的数值都向前移动了⼀位，所以i也向前移动⼀位
            size--; // 此时数组的⼤⼩-1
        }
    }
    return size;
}
int removeElement(int *nums, int numsSize, int val) {
    int slow = 0;
    int fast = 0;
    for (fast = 0; fast < numsSize; fast++) {
        if (val != nums[fast]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int removeElement(int *nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        while (left <= right && nums[left] != val) {
            left++;
        }
        while (left <= right && nums[right] == val) {
            right--;
        }
        if (left <= right) {
            nums[left++] = nums[right--];
        }
    }
    return left;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    removeElement(nums, 4, 2);
}