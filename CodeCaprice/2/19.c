#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    // 用于记录head位置
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    // 定义 fast slow 双指针
    struct ListNode *fast = head;
    struct ListNode *slow = dummy;

    for (int i = 0; i < n; ++i) { // 记录正序第n个的位置
        fast = fast->next;
    }
    while (
        fast) { // 总数为x,已经记录了第n个当fast遍历到最后时走了x-n步，倒叙来看就是倒数第n个
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; // 删除倒数第n个节点
    head = dummy->next;
    free(dummy); // 删除虚拟节点dummy
    return head;
}