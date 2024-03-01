#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxConsecutiveChar(const char *answerKey, int k, char ch) {
    int n = strlen(answerKey);
    int ans = 0;
    for (int left = 0, right = 0, sum = 0; right < n; right++) {
        sum += answerKey[right] != ch;
        while (sum > k) {
            sum -= answerKey[left++] != ch;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}
int maxConsecutiveAnswers(char *answerKey, int k) {
    int cnt1 = maxConsecutiveChar(answerKey, k, 'T');
    int cnt2 = maxConsecutiveChar(answerKey, k, 'F');
    return MAX(cnt1, cnt2);
}
int main() {
    const char *answerKey = "TTFF";
    int a = maxConsecutiveAnswers(answerKey, 2);
    printf("%d\n", a);
    return 0;
}