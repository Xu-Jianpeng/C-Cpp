///*
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 100
#define LISTINCREMENT 20

typedef struct {
	int coef;
	int exp;
}ElemType;

typedef struct {
	ElemType *elems;
	int len;
	int size;
}ArrayList;

void init(ArrayList & list){
	list.elems = (ElemType*) malloc(sizeof(int)*INIT_SIZE);
	list.size = INIT_SIZE;
	list.len = 0;
}

void insert(ArrayList &list,int i,ElemType e){
	ElemType *q,*p;
	if(list.len>=list.size){
		list.elems  = (ElemType *)realloc
			(list.elems,(list.size+LISTINCREMENT)*sizeof(ElemType));
		list.size += LISTINCREMENT;
	}
	q = &(list.elems[i-1]);
	for(p = &(list.elems[list.len-1]);p>=q;--p)	
		*(p+1) = *p;
	*q = e;
	++list.len;
}

void print(ArrayList & list){
	for(int i = 0;i<list.len;i++){
		printf("%d*x^%d",list.elems[i].coef,list.elems[i].exp);
		if(i==list.len-1)break;
		printf(" + ");
	}
	printf("\n");
}

void inputelems(ArrayList& list,int n){
	int i;
	init(list);
	ElemType e;
	for(i=0;i<n;i++){
		scanf("%d",&e.coef);
		scanf("%d",&e.exp);
		insert(list,i+1,e);
	}
}
	

ArrayList sorted(ArrayList list1){
	int i=0,j=0,k=0;
	ArrayList list2;
	list2.size=INIT_SIZE;
	list2.len=0;
	list2.elems=(ElemType*) malloc(list2.size*sizeof(ElemType));
	
	while(k < list1.len){
		for(i=0;i<list1.len;i++){
			if(list1.elems[i].exp>list1.elems[j].exp){
				j=i;
			}
		}
		list2.elems[k]=list1.elems[j];
		list1.elems[j].exp=-1;
		k++;list2.len++;
	}

	return list2;
}

void merge(ArrayList list1,ArrayList list2,ArrayList&list3){
	int i=0,j=0,k=0;
	list3.size=list3.len=0;
	list3.elems=(ElemType*) malloc(list3.size*sizeof(ElemType));
	while(i<list1.len&&j<list2.len){
		if(list1.elems[i].exp==list2.elems[j].exp) {
			list3.elems[k].coef=
				list1.elems[i].coef+list2.elems[j].coef;
			list3.elems[k].exp = list1.elems[i].exp;
			k++;i++;j++;list3.len++;
		} else if(list1.elems[i].exp>list2.elems[j].exp) {
			list3.elems[k].coef = list1.elems[i].coef;
			list3.elems[k].exp = list1.elems[i].exp;
			k++;i++;list3.len++;
		} else {
			list3.elems[k].coef = list2.elems[j].coef;
			list3.elems[k].exp = list2.elems[j].exp;
			k++;j++;list3.len++;
		}
	}
	while(i<list1.len) {
		list3.elems[k].coef = list1.elems[i].coef;
		list3.elems[k].exp = list1.elems[i].exp;
		k++;i++;
	}
	while(j<list2.len) {
		list3.elems[k].coef = list2.elems[j].coef;
		list3.elems[k].exp = list2.elems[j].exp;
		k++;j++;
	}
}

main(){
	int n;
	ArrayList a;
	init(a);
	ArrayList b;
	init(b);
	ArrayList c;
	init(c);

	printf("请输入a的项数:");
	scanf("%d",&n);
	printf("请按组输入a的系数和幂:\n");
	inputelems(a,n);
	a=sorted(a);
	printf("a=");
	print(a);
	
	printf("请输入b的项数:");
	scanf("%d",&n);
	printf("请按组输入b的系数和幂:\n");
	inputelems(b,n);
	b=sorted(b);
	printf("b=");
	print(b);

	print(a);

	merge(a,b,c);
	printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\na+b=");
	print(c);
	printf("\n");
	return 0;
}
//*/
/*#include<stdio.h>  
#include<stdlib.h>  
#include<malloc.h>  
typedef int ElemType;  
   
//单项链表的声明
typedef struct PolynNode{  
    int coef; // 系数  
    int expn; // 指数  
    struct PolynNode *next;  
}PolynNode,*PolynList;  
   
//正位序(插在表尾)输入n个元素的值，建立带表头结构的单链线性表
//指数系数一对一对输入
void CreatePolyn(PolynList &L,int n)  
{  
    int i;  
    PolynList p,q;  
    L=(PolynList)malloc(sizeof(PolynNode)); // 生成头结点  
    L->next=NULL;  
    q=L;  
    printf("成对输入%d个数据\n",n);  
    for(i=1;i<=n;i++)  
    {  
        p=(PolynList)malloc(sizeof(PolynNode));  
        scanf("%d%d",&p->coef,&p->expn);    //指数和系数成对输入  
        q->next=p;  
        q=q->next;  
    }  
    p->next=NULL;  
}  
   
// 初始条件：单链表L已存在  
// 操作结果: 依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败  
void PolynTraverse(PolynList L,void(*vi)(ElemType, ElemType))  
{  
    PolynList p=L->next;  
    while(p)  
    {  
        vi(p->coef, p->expn);  
        if(p->next)  
        {  
            printf(" + ");   //“+”号的输出，最后一项后面没有“+”  
        }  
        p=p->next;  
    }  
    printf("\n");  
}  
   
//ListTraverse()调用的函数(类型要一致)
void visit(ElemType c, ElemType e)   
{  
    if(c != 0)  
    {  
        printf("%dX^%d",c,e);   //格式化输出多项式每一项  
    }  
}  
   
///*    多项式相加，原理：归并          
///* 参数：两个已经存在的多项式       
///* 返回值：归并后新的多项式的头结点   
PolynList MergeList(PolynList La, PolynList Lb)  
{  
    PolynList pa, pb, pc, Lc;  
    pa = La->next;  
    pb = Lb->next;  
    Lc = pc = La;   // 用La的头结点作为Lc的头结点  
    while(pa&&pb)  
    {  
        if(pa->expn < pb->expn)          
        {                                
            pc->next = pa;             //如果指数不相等，pc指针连上指数小的结点，  
            pc = pa;  
            pa = pa->next;             //指向该结点的指针后移  
        }  
        else if (pa ->expn > pb->expn )      
        {  
            pc->next = pb;               //pc指针连上指数小的结点，  
            pc = pb;  
            pb = pb->next;               //指向该结点的指针后移  
        }  
        else   //(pa ->expn = pb->expn )  
        {  
            pa->coef = pa->coef + pb->coef;     //指数相等时，系数相加  
            pc->next = pa;  
            pc = pa;  
            pa = pa->next;             //两指针都往后移  
            pb = pb->next;  
        }  
    }  
   
    pc->next = pa ? pa:pb;  // 插入剩余段  
   
    return Lc;  
}  
   
void main()  
{  
    PolynList a,b,c;  
	int n;
    printf("a的项数为:");
	scanf("%d",&n);  
    CreatePolyn(a,n);   // 正位序输入n个元素的值  
   
    printf("b的项数为:");
	scanf("%d",&n);
    CreatePolyn(b,n);   // 正位序输入n个元素的值  
   
    printf("多项式a :");  
    PolynTraverse(a, visit);  
    printf("\n");  
    printf("多项式b :");  
    PolynTraverse(b, visit);  
    printf("\n");  
   
    c = MergeList(a,b);  
    PolynTraverse(c, visit);  
}
*/