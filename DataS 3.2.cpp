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

int InitList(LinkList &L){//��ʼ����ͷ���Ŀ����� 
    L = (LinkList)malloc(sizeof(Node));//����ͷ��㣬��ʹLָ���ͷ��� 
    if(!L)//����洢����ʧ�� 
        return ERROR;
    L->next = NULL;//ָ����Ϊ�� 
    return OK;
}

int ListLength(LinkList &L){//��������L������Ԫ�ظ��� 
    int i = 0;
    LinkList p;
    p = L->next;
    while(p){
        i++;
        p = p->next;
    }
    return i; 
}

//�������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L��ͷ�巨�� 
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

//�������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L��β�巨�� 
void CreateListTail(LinkList &L, int n){
    LinkList r,p;
    r = L;
    srand(time(0));//��ʼ�����������
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;//�������100���ڵ�����
        r->next = p;
        r = p; 
    } 
    r->next = NULL;
    p->next = L->next->next;//�ɻ� 
}

//�Ƚϲ����ķ��� 
int HasLoop1(LinkList &L)
{
    LinkList cur1 = L;//������cur1 
    int post1 = 0;//cur1�Ĳ���
    while(cur1)
    {//cur1������ 
        LinkList cur2 = L;//������cur2
        int post2 = 0;//cur2�Ĳ���
        while(cur2)
        {//cur2������ 
            if(cur2 == cur1)
            {//��cur1��cur2�ﵽ��ͬ���ʱ 
                if(post1 == post2)//�߹��Ĳ���һ�� 
                    break;//��û�л� 
                else//���� 
                {
                    printf("����λ���ڵ�%d����㴦��",post2);
                    return 1;    
                }
            }
            cur2 = cur2->next;//���û�з��ֻ����������һ�����
            post2++;//cur2��������1     
        }
        cur1 = cur1->next;//cur1�������һ����� 
        post1++;//cur2��������1    
	}
    return 0; 
}

//���ÿ���ָ��ķ���
int HasLoop2(LinkList &L){
    int step1 = 1;
    int step2 = 2;
    LinkList p = L;
    LinkList q = L;
    while(p != NULL && q != NULL && q->next != NULL){
        p = p->next;
        if(p->next != NULL)
            q = q->next->next;
        printf("p:%d��q:%d\n",p->data,q->data);
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
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    printf("\n1.�����л�����β�巨��\n2.�����޻�����ͷ�巨��\n3.�ж������Ƿ��л� \n0.�˳�\n\n��ѡ����Ҫ�Ĳ�����\n");
    while(opp != '0'){
        scanf("%c",&opp);
        switch(opp){
            case '1':
                CreateListTail(L,10);
                printf("�ɹ������л�����L��β�巨��\n");
                printf("\n");
                break;
                
            case '2':
                CreateListHead(L,10);
                printf("�ɹ������޻�����L��ͷ�巨��\n");
                printf("\n");
                break;
            
            case '3':
                printf("����һ��\n\n");
                if(HasLoop1(L)){
                    printf("���ۣ������л�\n\n\n");
                }
                else{
                    printf("���ۣ������޻�\n\n\n");
                }
                printf("��������\n\n");
                if(HasLoop2(L)){
                    printf("���ۣ������л�\n\n\n");
                }
                else{
                    printf("���ۣ������޻�\n\n\n");
                }
                printf("\n"); 
                break;
            case '4':
                exit(0);     
        }
    } 
    return 0;
}