#include<stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ans[1000][3]={0};
int** threeSum(int* nums, int numsSize, int* returnSize){

    if(numsSize<3){
        *returnSize=0;
        // **returnColumnSizes=0;
        return NULL;
    }
    if(numsSize==3){
        if(nums[0]+nums[1]+nums[2]==0){
            ans[0][0]=nums[0];
            ans[0][1]=nums[1];
            ans[0][2]=nums[2];
            *returnSize=1;
            // **returnColumnSizes=3;
            return ans;
        }
    }
    int cnt=0;
    int i=0;
    int j=0;
    int k=numsSize-1;
    while(i<=k-2){
        j=k-1;
        while(j>i){
            if(nums[i]+nums[j]+nums[k]==0){
                ans[cnt][0]=nums[i];
                ans[cnt][1]=nums[j];
                ans[cnt][2]=nums[k];
                cnt++;
            }
            j--;
        }
        k--;
    }
    *returnSize=cnt;
    // **returnColumnSizes=3;
    return ans;
}
int main()
{
    int nums[]={-1,0,1,2,-1,-4};
    int returnSize=0;
    int returnColumnSizes=0;
    threeSum(nums,6,&returnSize);
}