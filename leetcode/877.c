#include<stdio.h>
#include<stdbool.h>
bool stoneGame(int* piles, int pilesSize) {
    int i=0,j=pilesSize-1;
    int A=0;
    int B=0;
    while(i<=j){
        if(piles[i]>=piles[j]){
            A+=piles[i];
            i++;
        }else{
            A+=piles[j];
            j--;
        }
        if(piles[i]>=piles[j]){
            B+=piles[i];
            i++;
        }else{
            B+=piles[j];
            j--;
        }
    }
    if(A>B){
        return true;
    }
    return false;
}
int main()
{
    int nums[]={5,3,4,5};
    stoneGame(nums,4);
    return 0;
}