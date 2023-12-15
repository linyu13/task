#include<stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int n=pricesSize;
    int re=0;
    for(int i=1;i<n;i++){
        if(prices[i]-prices[i-1]>0){
            re+=prices[i]-prices[i-1];//每一步都有利润实现贪心
        }
    }
    return re;
}
int main()
{
    int prices[] = {7,1,5,3,6,4};
    maxProfit(prices,6);
}