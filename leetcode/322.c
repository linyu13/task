#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    // 对coins数组进行排序
    qsort(coins, coinsSize, sizeof(int), compare);

    int i = amount;
    int cnt = 0;
    int index = coinsSize - 1;
    while (index != -1 || i == 0) {
        if (coins[index] < i) {
            cnt++;
            i -= coins[index];
        }
        else if (coins[index] == i) {
            cnt++;
            i -= coins[index];
            break;
        }
        else if (coins[index] > i) {
            if (index == 0) {
                break;
            }
            index--;
        }
    }
    if (i == 0) {
        return cnt;
    }
    else {
        return -1;
    }
}

int main()
{
    int coins[] = {186, 419, 83, 408};
    printf("%d\n", coinChange(coins, 4, 6249));
    return 0;
}
