#include <stdio.h>
#include <stdlib.h>
typedef struct student {
    int num;
    char name[20];
    int grade;

    struct student *next;
} STU;
void link(STU **head, STU *next);
void link_print(STU *head);
void add(STU **head);
void delete(STU *head);
STU *search(STU *head, int n);
void sort_link(STU *head);
void free_link(STU **head);
int main() {
    STU *head = NULL, *next = NULL;
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        next = (STU *)malloc(sizeof(STU));
        scanf("%d %s %d", &next->num, next->name, &next->grade);
        link(&head, next);
    }
    link_print(head);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        add(&head);
    }
    link_print(head);
    delete (head);
    link_print(head);
    int x = 0;
    scanf("%d", &x);
    STU *a = search(head, x);
    printf("%d %s %d", &a->num, a->name, &a->grade);
    sort_link(head);
    link_print(head);
    free_link(&head);
    return 0;
}

void link(STU **head, STU *next) {
    STU *body = NULL;
    *head = body;
    if (*head == NULL) {
        *head = next;
        (*head)->next = NULL;
    } else {
        while (body->next != NULL) {
            body = body->next;
        }
        body->next = next;
        next->next = NULL;
    }
    return;
}

void link_print(STU *head) {
    if (head == NULL) {
        return;
    }
    STU *body = NULL;
    body = head;
    while (body != NULL) {
        printf("%d %s %d\n", body->num, body->name, body->grade);
        body = body->next;
    }
    return;
}

void add(STU **head) {
    STU *after = NULL, *next = NULL, *before = NULL;
    *head = before;
    *head = after;
    int n = 0;
    scanf("%d", &n);
    next = (STU *)malloc(sizeof(STU));
    scanf("%d %s %d", &next->num, next->name, &next->grade);
    if (*head == NULL) {
        *head = next;
        next->next = NULL;
    } else {
        while (before->num < n) {
            before = after;
            after = after->next;
        }
        if ((*head) == after) {
            next->next = *head;
            (*head) = next;
        } else if (after->next != NULL) {
            before->next = next;
            next->next = after;
        } else {
            after->next = next;
            next->next = NULL;
        }
    }
    return;
}

void delete(STU *head) {
    int n = 0;
    scanf("%d", &n);
    if (head == NULL) {
        return;
    }
    STU *after = NULL, *before = NULL;
    after = head;
    before = head;
    while (after->num != n) {
        before = after;
        after = after->next;
    }
    if (after == NULL) {
        return;
    } else {
        before->next = after->next;
    }
    free(after);
    after = NULL;
}

STU *search(STU *head, int n) {
    STU *body = NULL;
    body = head;
    if (head == NULL) {
        return NULL;
    }
    while (body->num != n) {
        body = body->next;
    }
    if (body == NULL) {
        return NULL;
    } else {
        return body;
    }
}

void sort_link(STU *head) {
    STU *before = NULL, *after = NULL;
    STU t;
    if (head == NULL) {
        return;
    } else if (head->next == NULL) {
        return;
    } else {
        while (before->next != NULL) {
            after = before->next;
            while (after != NULL) {
                if ((before->num) > (after->num)) {
                    t = *after;
                    *after = *before;
                    *before = t;

                    t.next = after->next;
                    after->next = before->next;
                    before->next = t.next;
                }
                after = after->next;
            }
            before = before->next;
        }
    }
    return;
}

void free_link(STU **head) {
    if (*head == NULL) {
        return;
    }
    STU *body = NULL;
    body = *head;
    while (body != NULL) {
        body = body->next;
        free(head);
        head = NULL;
        *head = body;
    }
    return;
}