// #include <stdio.h>
// #include <stdlib.h>
// typedef struct reverseLink {
//     int num;
//     char name[20];
//     int grade;

//     struct reverseLink *next;
// } Linknode;

// Linknode *ReverseList_Recursion(Linknode *head) {
//     Linknode *pre = NULL;

//     if (head == NULL)
//         return NULL;
//     if (head->next == NULL)
//         head->next = pre;
//     return head;

//     pre = head;
//     head = ReverseList_Recursion(head->next);
//     head->next = pre;

//     return head;
// }

// void link_creat(Linknode **head, Linknode *next) {
//     Linknode *body = NULL; // 创建一个新的stu *类型的指针用于遍历链表
//     body = *head;
//     if (*head ==
//         NULL) { // 因为传输head是传的是head的地址,所以需要先解引用再判断head是否为空
//         // 如果为空,则代表此时是第一个节点
//         *head = next; // 将新节点的地址赋给head
//         (*head)->next = NULL;
//     } else {
//         while (body->next != NULL) {
//             body = body->next; // 将body这个指针抵达最后一个节点
//         }
//         body->next = next; // 将新节点连接到原先的最后一个节点之后
//         next->next = NULL;
//     }
//     return;
// }

// void link_print(Linknode *head) {
//     if (head == NULL) {
//         return;
//     }
//     Linknode *body = NULL;
//     body = head;
//     while (body != NULL) {
//         printf("%d %s %d\n", body->num, body->name, body->grade);
//         body = body->next;
//     }
//     return;
// }

// int main() {
//     Linknode *head = NULL, *next = NULL;
//     int n = 0;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         next = (Linknode *)malloc(sizeof(Linknode));
//         scanf("%d%s%d", &next->num, next->name, &next->grade);
//         link_creat(&head, next);
//     }
//     link_print(head);
//     ReverseList_Recursion(head);
//     link_print(head);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int elem;
	struct Node *next;
}node;
node *initNode(){
	node *end=NULL;
	node *p=(node *)malloc(sizeof(node));
	p->next=NULL;
	p->elem=1;
	end=p;
	for(int i=2;i<3;i++){
		node *newnode=(node *)malloc(sizeof(node));
		newnode->next=NULL;
		newnode->elem=i;
		end->next=newnode;
		end=newnode;
	}
	return p;
}
void show(node *p){
	node *temp=p;
	while(temp){
		printf("%d ",temp->elem);
		temp=temp->next;
	}
	printf("\n");
}
node *recursion(node *p){
	if(p==NULL||p->next==NULL){
		return p;
	}else{
		node *newnode = recursion(p->next);
		p->next->next=p;
		p->next=NULL;
		return newnode;
	}
}
int main(void){
	node *p=initNode();
	show(p);
	p=recursion(p);
	show(p);
	return 0;
}
