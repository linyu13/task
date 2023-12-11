#include <stdio.h>
#define Dumnum 150
int main() {
    int num_week = 1;
    int num_friend = 5;
    while (num_friend <= Dumnum) {
        num_friend -= num_week;
        num_friend *= 2;
        printf("%d\n", num_friend);
    }
    return 0;
}