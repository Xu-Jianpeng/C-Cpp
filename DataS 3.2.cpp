#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

int InitList(LinkList &L){//初始化带头结点的空链表 
    L = (LinkList)malloc(sizeof(Node));//产生头结点，并使L指向此头结点 
    if(!L)//如果存储分配失败 
        return ERROR;
    L->next = NULL;//指针域为空 
    return OK;
}

int ListLength(LinkList &L){//返回链表L中数据元素个数 
    int i = 0;
    LinkList p;
    p = L->next;
    while(p){
        i++;
        p = p->next;
    }
    return i; 
}

//随机产生n个元素的值，建立带头结点的单链表L（头插法） 
void CreateListHead(LinkList &L, int n){
    LinkList p;
    srand(time(0));
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = L->next;
        L->next = p; 
    }
} 

//随机产生n个元素的值，建立带头结点的单链表L（尾插法） 
void CreateListTail(LinkList &L, int n){
    LinkList r,p;
    r = L;
    srand(time(0));//初始化随机数种子
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;//随机产生100以内的数字
        r->next = p;
        r = p; 
    } 
    r->next = NULL;
    p->next = L->next->next;//成环 
}

//比较步数的方法 
int HasLoop1(LinkList &L)
{
    LinkList cur1 = L;//定义结点cur1 
    int post1 = 0;//cur1的步数
    while(cur1)
    {//cur1结点存在 
        LinkList cur2 = L;//定义结点cur2
        int post2 = 0;//cur2的步数
        while(cur2)
        {//cur2结点存在 
            if(cur2 == cur1)
            {//当cur1和cur2达到相同结点时 
                if(post1 == post2)//走过的步数一样 
                    break;//则没有环 
                else//否则 
                {
                    printf("环的位置在第%d个结点处。",post2);
                    return 1;    
                }
            }
            cur2 = cur2->next;//如果没有发现环，则继续下一个结点
            post2++;//cur2步数自增1     
        }
        cur1 = cur1->next;//cur1继续向后一个结点 
        post1++;//cur2步数自增1    
	}
    return 0; 
}

//利用快慢指针的方法
int HasLoop2(LinkList &L){
    int step1 = 1;
    int step2 = 2;
    LinkList p = L;
    LinkList q = L;
    while(p != NULL && q != NULL && q->next != NULL){
        p = p->next;
        if(p->next != NULL)
            q = q->next->next;
        printf("p:%d，q:%d\n",p->data,q->data);
        if(p == q)
            return 1;
    }
    return 0;
} 

int main(){
    LinkList L;
    InitList(L); 
    int i,e,find,temp;
    char opp;
    i = InitList(L);
    printf("初始化L后，ListLength(L)=%d\n",ListLength(L));
    printf("\n1.创建有环链表（尾插法）\n2.创建无环链表（头插法）\n3.判断链表是否有环 \n0.退出\n\n请选择你要的操作：\n");
    while(opp != '0'){
        scanf("%c",&opp);
        switch(opp){
            case '1':
                CreateListTail(L,10);
                printf("成功创建有环链表L（尾插法）\n");
                printf("\n");
                break;
                
            case '2':
                CreateListHead(L,10);
                printf("成功创建无环链表L（头插法）\n");
                printf("\n");
                break;
            
            case '3':
                printf("方法一：\n\n");
                if(HasLoop1(L)){
                    printf("结论：链表有环\n\n\n");
                }
                else{
                    printf("结论：链表无环\n\n\n");
                }
                printf("方法二：\n\n");
                if(HasLoop2(L)){
                    printf("结论：链表有环\n\n\n");
                }
                else{
                    printf("结论：链表无环\n\n\n");
                }
                printf("\n"); 
                break;
            case '4':
                exit(0);     
        }
    } 
    return 0;
}