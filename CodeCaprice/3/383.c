#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool canConstruct(char *ransomNote, char *magazine) {
    if (strlen(ransomNote) > strlen(magazine)) {
        return false;
    }
    int hash[27] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) {
        hash[magazine[i] - 'a']++;
    }
    for (int k = 0; ransomNote[k] != '\0'; k++) {
        hash[ransomNote[k] - 'a']--;
        if (hash[ransomNote[k] - 'a'] == -1) {
            return false;
        }
    }
    return true;
}
int main() { printf("%d\n", canConstruct("aa", "aab")); }