#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head_l1 = l1;
    struct ListNode *head_l2 = l2;
    struct ListNode *pre_l1 = l1;
    struct ListNode *pre_l2 = l2;
    int cnt = 0;
    int sum = 0;
    int le_l1 = 0, le_l2 = 0;
    while (head_l1 != NULL) {
        le_l1++;
        head_l1 = head_l1->next;
    }
    while (head_l2 != NULL) {
        le_l2++;
        head_l2 = head_l2->next;
    }
    head_l1 = l1;
    head_l2 = l2;
    while (head_l1 != NULL && head_l2 != NULL) {
        if (le_l1 >= le_l2) {
            sum = head_l1->val + head_l2->val + cnt;
            head_l1->val = (head_l1->val + head_l2->val + cnt) % 10;
        } else {
            sum = head_l1->val + head_l2->val + cnt;
            head_l2->val = (head_l1->val + head_l2->val + cnt) % 10;
        }

        if (sum > 9) {
            cnt = 1;
        } else {
            cnt = 0;
        }
        pre_l1 = head_l1;
        pre_l2 = head_l2;
        head_l1 = head_l1->next;
        head_l2 = head_l2->next;
    }
    while (head_l1 != NULL) {
        sum = head_l1->val + cnt;
        head_l1->val = (head_l1->val + cnt) % 10;
        if (sum > 9) {
            cnt = 1;
        } else {
            cnt = 0;
        }
        pre_l1 = head_l1;
        head_l1 = head_l1->next;
    }
    while (head_l2 != NULL) {
        sum = head_l2->val + cnt;
        head_l2->val = (head_l2->val + cnt) % 10;
        if (sum > 9) {
            cnt = 1;
        } else {
            cnt = 0;
        }
        pre_l2 = head_l2;
        head_l2 = head_l2->next;
    }
    if (cnt == 1 && sum >= 10) {
        struct ListNode *new =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = cnt;
        new->next = NULL;
        if (le_l1 >= le_l2) {
            pre_l1->next = new;
        } else {
            pre_l2->next = new;
        }
    }
    if (le_l1 >= le_l2) {
        return l1;
    } else {
        return l2;
    }
    return NULL;
}
int main() {
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l1 = NULL;
    l2 = NULL;
    struct ListNode *pre_l1 = l1;
    struct ListNode *pre_l2 = l2;
    for (int i = 0; i < 3; i++) {
        struct ListNode *new = malloc(sizeof(struct ListNode));
        scanf("%d", &new->val);
        if (l1 == NULL) {
            l1 = new;
        }
        pre_l1 = l1;
        if (pre_l1->next != NULL) {
            pre_l1 = pre_l1->next;
        }
        pre_l1->next = new;
    }
    
    for (int i = 0; i < 3; i++) {
        struct ListNode *new = malloc(sizeof(struct ListNode));
        scanf("%d", &new->val);
        if (l2 == NULL) {
            l2 = new;
        }
        pre_l2 = l2;
        if (pre_l2->next != NULL) {
            pre_l2 = pre_l2->next;
        }
        pre_l2->next = new;
    }
}