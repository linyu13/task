#include <stdio.h>
int cmp(int *a, int *b) { // 计算数组前后的地址偏移差值
    return *a - *b;
}
int findContentChildren(int *g, int gSize, int *s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp); // 排序
    qsort(s, sSize, sizeof(int), cmp);
    int m = gSize, n = sSize;
    int cnt = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && g[i] > s[j]) { // 如果胃口不满足，遍历下一个
            j++;
        }
        if (j < n) { // 当j < n时，说明能找到满足胃口的饼干
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    findContentChildren(g, 3, s, 2);
    return 0;
}