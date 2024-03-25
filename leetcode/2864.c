#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* maximumOddBinaryNumber(char* s){
    int len = strlen(s);
    int num_1 = 0;
    for (int i= 0; i < len; i++) {
        if(s[i] == '1') {
            num_1++;
        }
    }
    int index = 0;
    char* ans = calloc(len + 1, sizeof(char));
    for (int i = 0; i < num_1 - 1; i++) {
        ans[index] = '1';
        index++;
    }
    for (int i = 0; i < len - num_1; i++) {
        ans[index] = '0';
        index++;
    }
    if (num_1) {
        ans[index] = '1';
    }
    return ans;
}

int main() {
    puts(maximumOddBinaryNumber("001111111101"));
}