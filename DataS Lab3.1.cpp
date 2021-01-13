///*
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;


typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


//void InitList(LinkList& L){
//	L=(LinkList)malloc(sizeof(LNode));
//}

void InitList(LinkList &L){//��ʼ����ͷ���Ŀ����� 
	L = (LinkList)malloc(sizeof(LNode));//����ͷ��㣬��ʹLָ���ͷ��� 
	L->next = NULL;//ָ����Ϊ�� 
}

void creat(LinkList &L,int n){
	int i;
	LinkList r,p;
	r=L;
	for(i=n;i>0;--i){
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		r->next=p;r=p;
	}
	r->next=NULL;
}

void merge(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa,pb,pc;
	pa=La->next;pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			printf("%d<=%d\n",pa->data,pb->data);
			pc->next=pa;pc=pc->next;pa=pa->next;
		}  else {
			printf("%d>%d\n",pa->data,pb->data);
			pc->next=pb;pc=pc->next;pb=pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}

void print(LinkList &L){//��ӡ����ĺ���
	LinkList p=L->next;//����ͷ��㵽 �׽��
	while (p!=NULL)//��㲻Ϊ�գ�����
    {
        printf("%d ",p->data);
        p=p->next;
    }
	printf("\n");
	
}

main(){
	LinkList La;
	InitList(La);
	printf("please input La:");
	creat(La,4);
	print(La);

	LinkList Lb;
	InitList(Lb);
	printf("please input Lb:");
	creat(Lb,4);
	print(Lb);

	LinkList Lc;
	InitList(Lc);
	merge(La,Lb,Lc);
	printf("\nLc:");
	print(Lc);
	return 0;
}
//*/
/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
using namespace std;
typedef struct Node{//����������
    int data;
    struct Node *next;
}List;
 
void Create_List(List *&L,int x){//����������ͨ������L1,L2
    List *s,*r;
    L=(List *)malloc(sizeof(List));
    L->next=NULL;
    r=L;//β�巨����
    for(int i=0;i<x;i++)
    {
        s=(List *)malloc(sizeof(List));
        scanf("%d",&s->data);
        r->next=s;
        r=s;
    }
    r->next=NULL;
}*/
//�����Connect����List��������������L1��L2���뱾���޹�
/*void Connect_List(List *&L,List *&L2,int m,int n){
    List *l=L;
    List *q=L2;
    for(int i=0;i<n;i++)
    {
        l=l->next;
    }
    l->next=q->next;
}*/
/*
void Print(List *&L,int n){//��ӡ����ĺ���
    List *p=L->next;//����ͷ��㵽 �׽��
    while (p!=NULL)//��㲻Ϊ�գ�����
    {
        printf("%d ",p->data);
        p=p->next;
    }
}/*
/*
    ����L1,L2�����µ�����L3
    L1����ΪN,L2����ΪM
    ���ж�L1,l2�������Σ�ȥ����Ϊmini
    ����MΪ�Ľϴ�,NΪ��С�ģ�temp=0����δ����
    �������ڶ���forѭ����ΪL3����L2��ֵ
    ����N�ϴ��򽻻���������
    ��ֵtemp��ʱ�Ͳ�Ϊ0����
    �������ڶ���forѭ����ΪL3����L1��ֵ
*/
/*
void CreatList3(List *&L1,List *&L2,List *&L3,int m,int n){
    List *l=L1->next;
    List *q=L2->next;
    //List *h=L3;
    int mini,temp=0;
    if(m<n){
        temp=m;
        m=n;
        n=temp;
    }
    mini=temp;
    List *s,*r;
    L3=(List *)malloc(sizeof(List));
    L3->next=NULL;
    r=L3;
    for(int i=0;i<mini;i++)
    {
        s=(List *)malloc(sizeof(List));
        s->data=l->data;
        l=l->next;
        r->next=s;
        r=s;
        s=(List *)malloc(sizeof(List));
        s->data=q->data;
        q=q->next;
        r->next=s;
        r=s;
    }
    for(int j=0;j<(m-mini);j++){
        if(temp!=0){
            s=(List *)malloc(sizeof(List));
            s->data=l->data;
            l=l->next;
            r->next=s;
            r=s;
        }else{
            s=(List *)malloc(sizeof(List));
            s->data=q->data;
            q=q->next;
            r->next=s;
            r=s;
        }
 
    }
    r->next=NULL;
}
 
int main(){
    List *L1,*L2,*L3;
    int n,m;
    L1=(List *)malloc(sizeof(List));
    L2=(List *)malloc(sizeof(List));
    L3=(List *)malloc(sizeof(List));
    cin>>n;
    Create_List(L1,n);
    cin>>m;
    Create_List(L2,m);
    CreatList3(L1,L2,L3,m,n);
    Print(L3,n);
    free(L3);
    //Connect_List(L1,L2,m,n);
    //Print(L1,n);
    //free(L1);
    return 0;
}
*/