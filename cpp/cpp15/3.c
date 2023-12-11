#include <stdio.h>
int ope_num(int x) {
    int num = 1;
    int cnt = 0;
    while (x != 0) {
        if (x & num == 1) {
            cnt++;
        }
        x>>=1;
    }
    return cnt;
}
int main() { 
    int x = -1;
    int num=ope_num(x);
    printf("%d\n",num);
    return 0;
}