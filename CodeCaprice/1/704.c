#include <stdio.h>
int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) / 2;
    int re = -1;
    while (left <= right) {
        if (nums[mid] < target) {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        if (nums[mid] > target) {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        if (nums[mid] == target) {
            re = mid;
            break;
        }
    }
    return re;
}

int binarySearch(int *nums, int target, int left, int right) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[mid] > target) {
        return binarySearch(nums, target, left, mid - 1);
    } else {
        return binarySearch(nums, target, mid + 1, right);
    }
}
int search(int *nums, int numsSize, int target) {
    return binarySearch(nums, target, 0, numsSize - 1);
}