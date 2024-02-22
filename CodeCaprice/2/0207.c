#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    struct ListNode *l = NULL, *s = NULL;
    int lenA = 0, lenB = 0, gap = 0;
    s = headA;
    while (s) {
        lenA++;
        s = s->next;
    }
    s = headB;
    while (s) {
        lenB++;
        s = s->next;
    }
    if (lenA > lenB) {
        l = headA, s = headB;
        gap = lenA - lenB;
    } else {
        l = headB, s = headA;
        gap = lenB - lenA;
    }
    while (gap--)
        l = l->next;
    while (l) {
        if (l == s)
            return l;
        l = l->next, s = s->next;
    }

    return NULL;
}