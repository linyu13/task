#include <stdio.h>
int fmax_my(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int lengthOfLongestSubstring(char *s) {
    int max = 0;
    int hash[200] = {0};
    int left = 0;
    for (int i = 0; s[i]; i++) {
        if (hash[s[i]] > left) {
            left = hash[s[i]];
            hash[s[i]] = 1;
        } else {
            hash[s[i]] = i + 1;
            max = fmax_my(max, i + 1 - left);
        }
    }
    return max;
}

int main() {
    char *s = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}