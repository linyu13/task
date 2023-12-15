#include <stdio.h>
void QuickSort(int arr[], int start, int end)// 快速排序(递归)
{
	if (start >= end)
		return;
	int i = start;
	int j = end;
	// 基准数
	int baseval = arr[start];
	while (i < j)
	{
		// 从右向左找比基准数小的数
		while (i < j && arr[j] >= baseval)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		// 从左向右找比基准数大的数
		while (i < j && arr[i] < baseval)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	// 把基准数放到i的位置
	arr[i] = baseval;
	QuickSort(arr, start, i - 1);//再次递归该基准数下标之前的数据
	QuickSort(arr, i + 1, end);//再次递归该基准数下标之后的数据
}

int triangleNumber(int *nums, int numsSize) {
    int i = 0, j = 0, k = 0;
    int cnt = 0;
    // for (i = 0; i <= numsSize - 3; i++) {
    //     for (j = i + 1; j <= numsSize - 2; j++) {
    //         for (k = j + 1; k <= numsSize - 1; k++) {
    //             if ((nums[i] + nums[j] > nums[k]) &&
    //                 (nums[i] + nums[k] > nums[j]) &&
    //                 (nums[k] + nums[j] > nums[i])) {
    //                 cnt++;
    //             }
    //         }
    //     }
    // }
    // 时间复杂度未免有些过高
    // 使用排序的思想，双指针指向两个相邻的数，每当遇到大于等于这两数之和的数就更新两数的下标
    QuickSort(nums,0,numsSize);
    for(i=0;i<=numsSize-3;i++){
        for(j=i+1;j<=numsSize-2;j++){
            for(k=j+1;nums[i]+nums[j]<nums[k];k++){
                    cnt++;
            }goto re;
        }
        re:
    }
    return cnt;
}
int main() {
    int nums[] = {2, 2, 3, 4};
    int a = triangleNumber(nums, 4);
    printf("%d\n", a);
    return 0;
}