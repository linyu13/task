#include <stdbool.h>
#include <stdio.h>
bool isValid(char* s)
{
    int i = 0;
    int cnt = 0;
    char str[10000] = { 0 };
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            str[cnt] = s[i];
            cnt++;
        }
        else {
            if (str[cnt] == '(' && s[i] == ')') {
                str[cnt] = 0;
                cnt--;
            }
            else if (str[cnt] == '[' && s[i] == ']') {
                str[cnt] = 0;
                cnt--;
            }
            else if (str[cnt] == '{' && s[i] == '}') {
                str[cnt] = 0;
                cnt--;
            }
        }
    }
    if (cnt == 0) {
        return true;
    }
    return false;
}
int main()
{
}
