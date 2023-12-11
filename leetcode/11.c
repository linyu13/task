#include<stdio.h>
int maxArea(int* height, int heightSize) {
    int i=0;
    int j=heightSize-1;
    int sumpre=0;
    int sum=0;
    while(i<j){
        if(height[i]<=height[j]){
            sumpre=height[i]*(j-i);
            i++;
        }else{
            sumpre=height[j]*(j-i);
            j--;
        }
        if(sumpre>sum){
            sum=sumpre;
        }
    }
    return sum;
}
int main()
{
    int height[]={1,8,6,2,5,4,8,3,7};
    maxArea(height,9);
    return 0;
}