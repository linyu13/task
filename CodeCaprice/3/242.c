#include <stdbool.h>
#include <stdio.h>
bool isAnagram(char *s, char *t) {
    char hash[100] = {0};
    
    for (int i = 0; s[i] != '\0'; i++) {
        hash[i] = s[i];
    }

    for (int j = 0; t[j] != '\0'; j++) {
        for (int k = 0; hash[k] != '\0'; k++) {
            if (t[j] == hash[k]) {
                hash[k] = 0;
                break;
            }
            if (t[j] != hash[k] && hash[k + 1] == '\0') {
                return false;
            }
        }
    }

    return true;
}
int main() {
    int i=isAnagram("anagram","nagaram");
    printf("%d\n",i);
}