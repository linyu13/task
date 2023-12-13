# 单向链表的实现及详解

## 一.链表是什么
>定义：链表是一种物理存储单元上非连续、非顺序的存储结构，由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。
> 在链表的储存上，每个结点不仅包含所存的元素信息，还包含元素间的逻辑信息。
### 1.链表的组成
> 单向链表一般由数据域和指针域两部分组成
```c
typedef struct students {
    int num;
    char name[20];
    int grade;
    //数据域
    struct students *next;
    //指针域
} stu;
```
> 数据域存储需要用的内容
指针域存储能够指向下一个节点的指针

### 2.链表的意义
链表最大的租用就是通过指针域当中的指针将散乱的数据连接在一起,组成一个有序的表

### 3.链表与数组的区别
数组是通过开辟一块连续的内存来存储数据,链表是先创建空间来储存数据,再用指针连接每一块储存着数据的空间.

## 二.有关链表的操作
### 1.链表的创建
大体思路如下:
> 首先创建一个节点,将该节点定义为头节点
创建第二个节点,将头节点中指针域中的指针指向第二各节点,并以此类推

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void link_creat(stu **head,stu *next);
typedef struct students {
    int num;
    char name[20];
    int grade;
    //数据域
    struct students *next;
    //指针域
} stu;
int main()
{
    stu *head=NULL,*next=NULL;//创建两个类型为stu *的指针,并赋为NULL防止指针乱指
    int n=0;
    scanf("%d",&n);//n代指想要创建链表的个数
    for(int i=0;i<n;i++){
        next=(stu *)malloc(sizeof(stu));//为每个节点创建一份空间用于储存数据
        scanf("%d%s%d", &next->num, next->name, &next->grade);//写入数据
        link_creat(&head,next);/*进入创建链表的函数进行链表的串联,
        传输head时传地址的原因是在该函数中
        需要改变head的地址*/
    }
    return 0;
}

void link_creat(stu **head,stu *next)
{
    stu *body=NULL;//创建一个新的stu *类型的指针用于遍历链表
    body=*head;
    if(*head==NULL){//因为传输head是传的是head的地址,所以需要先解引用再判断head是否为空
    //如果为空,则代表此时是第一个节点
    *head=next;//将新节点的地址赋给head
    (*head)->next=NULL;
    }else{
        while(body->next!=NULL){
            body=body->next;//将body这个指针抵达最后一个节点
        }
        body->next=next;//将新节点连接到原先的最后一个节点之后
        next->next=NULL;
    }
    return ;
}
```

### 2.链表的遍历
```c
void link_print(stu *head)//传进head这个指针本身
{
    stu *body=NULL;
    body=head;
    if(head==NULL){
        return ;//没有数据可以遍历
    }else{
        while(body!=NULL){
            printf("%d %s %d",body->num.body->name,body->grade);//输出数据域
            body=body->next;//遍历到下一个节点
        }
    }
    return ;
}

```

### 3.链表的释放

```c
void link_free(stu **head)
{
    stu *body=NULL;
    body=*head;
    if(*head==NULL){
        return ;//链表为空,无需释放
    }else{
        while(body!=NULL){
        body=body->next;//用body变量储存下一个节点的位置
        free(head);//释放头节点
        head=NULL;//防止野指针
        *head=body;//重新定位头节点
        }
    }
    return ;
}
```

### 4.链表节点的查找
#### 通过num查找
```c
stu * link_search(stu *head,int n)//因为是查找节点,因此需要返回一个stu 类型的指针
{
    stu *body=NULL;
    if(head==NULL){
        return NULL;//链表为空
    }
    body=head;
    while(body->num!=n){
        //当该节点中存储的num不等于n时,进入循环
        body=body->next;
    }
    if(body->num==n){
        return body;
    }else{
        return NULL;
    }//只要是body->num存在时,节点一定不为空
}
```

#### 通过name查找
```c
stu * link_search(stu *head,char *name)
{
    stu *body=NULL;
    if(head==NULL){
        return NULL;
    }
    body=head;
    while(strcmp(body->name,name)!=0){
        //当该节点中存储的name与传入的name不相等的时候,进入循环
        body=body->next;
    }
    if(strcmp(body->name,name)==0){
        return body;
    }else{
        return NULL;
    }
}
```

### 5.链表的删除
#### 通过num查找并删除
```c
void link_delete(stu *head,int n)
{
    stu *before=NULL,*after=NULL;
    if(head==NULL){
        return ;//链表为空
    }
    before=head;
    after=head;//定义两个节点来追踪遍历的位置
    while(after->num!=n){
        before=after;//进入循环,更新两节点位置,使after节点快before节点一步
        after=after->next;
    }
    if(after->num==n){//符合条件的话(说明找到了,没进入就是没找到),进入语句
        before->next=after->next;//跳过找到的节点,即after节点并释放该节点
        free(after);
        after=NULL;
    }
    return ;
}
```

#### 通过name查找并删除
```c
void link_delete(stu *head,char *name)
{
    stu *before=NULL,*after=NULL;
    if(head==NULL){
        return ;
    }
    before=head;
    after=head;
    while(strcmp(after->name,name)!=0){
        before=after;
        after=after->next;
    }
    if(strcmp(after->name,name)==0){
        before->next=after->next;
        free(after);
        after=NULL;
    }
    return ;
}
```

### 6.插入节点
```c
void link_insert(stu **head)
{
    stu *before=NULL,*after=NULL;
    after=*head;
    before=*head;
    stu *new=NULL;
    new=(stu *)malloc(sizeof(stu));
    scanf("%d%s%d",&new->num,new->name,&new->grade);
    while(new->num > after->num){
        before=after;
        after=after->next;
    }//遍历直至找到 比新建立的节点小的 第一个节点
    if(after==(*head)){
        //此时说明新建立的节点想要有序插入原有链表时,
        //要插入的位置是原链表头节点之前
        new->next=(*head);
        (*head)=new;//改变头节点的地址为新节点的地址
    }else if(after!=NULL){
        //此时说明新节点要插入的位置在原链表内部
        before->next=new;
        new->next=after;
    }else if(after==NULL){
        //此时说明新节点要插入的位置在原链表的最后
        before->next=new;
        new->next=NULL;
    }
    return ;
}
```
如果需要用name确定插入的位置的话只需要改变while循环当中的条件为以strcmp函数为基础的判断式就可以了
### 7.链表的排序
```c
void link_sort(stu *head)
{
    if(head==NULL || head->next==NULL){
        //当没有节点或者只有一个节点时无需排序
        return ;
    }
    stu *before=NULL,*after=NULL;
    before=head;
    after=head;
    stu t;
    while(before->next!=NULL){
        after=before->next;//重新规定after的位置
        while(after!=NULL){
            //固定前面的节点,挨个遍历之后的节点,找到比前面节点小的就交换
            if(before->num>after->num){
                t=*before;
                *before=*after;
                *after=t;

                t.next=before->next;
                before->next=after->next;
                after->next=t.next;
            }
            after=after->next;//after指向下一个节点,继续循环
        }//内部循环作用为将num最大的节点放在最后
        before=before->next;//before挪到下一个位置
    }
    return ;
}
```

## 结
夹带私货环节
> 莫道桑榆晚,为霞尚满天.
