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

	printf("������a������:");
	scanf("%d",&n);
	printf("�밴������a��ϵ������:\n");
	inputelems(a,n);
	a=sorted(a);
	printf("a=");
	print(a);
	
	printf("������b������:");
	scanf("%d",&n);
	printf("�밴������b��ϵ������:\n");
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
   
//�������������
typedef struct PolynNode{  
    int coef; // ϵ��  
    int expn; // ָ��  
    struct PolynNode *next;  
}PolynNode,*PolynList;  
   
//��λ��(���ڱ�β)����n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�
//ָ��ϵ��һ��һ������
void CreatePolyn(PolynList &L,int n)  
{  
    int i;  
    PolynList p,q;  
    L=(PolynList)malloc(sizeof(PolynNode)); // ����ͷ���  
    L->next=NULL;  
    q=L;  
    printf("�ɶ�����%d������\n",n);  
    for(i=1;i<=n;i++)  
    {  
        p=(PolynList)malloc(sizeof(PolynNode));  
        scanf("%d%d",&p->coef,&p->expn);    //ָ����ϵ���ɶ�����  
        q->next=p;  
        q=q->next;  
    }  
    p->next=NULL;  
}  
   
// ��ʼ������������L�Ѵ���  
// �������: ���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ��  
void PolynTraverse(PolynList L,void(*vi)(ElemType, ElemType))  
{  
    PolynList p=L->next;  
    while(p)  
    {  
        vi(p->coef, p->expn);  
        if(p->next)  
        {  
            printf(" + ");   //��+���ŵ���������һ�����û�С�+��  
        }  
        p=p->next;  
    }  
    printf("\n");  
}  
   
//ListTraverse()���õĺ���(����Ҫһ��)
void visit(ElemType c, ElemType e)   
{  
    if(c != 0)  
    {  
        printf("%dX^%d",c,e);   //��ʽ���������ʽÿһ��  
    }  
}  
   
///*    ����ʽ��ӣ�ԭ���鲢          
///* �����������Ѿ����ڵĶ���ʽ       
///* ����ֵ���鲢���µĶ���ʽ��ͷ���   
PolynList MergeList(PolynList La, PolynList Lb)  
{  
    PolynList pa, pb, pc, Lc;  
    pa = La->next;  
    pb = Lb->next;  
    Lc = pc = La;   // ��La��ͷ�����ΪLc��ͷ���  
    while(pa&&pb)  
    {  
        if(pa->expn < pb->expn)          
        {                                
            pc->next = pa;             //���ָ������ȣ�pcָ������ָ��С�Ľ�㣬  
            pc = pa;  
            pa = pa->next;             //ָ��ý���ָ�����  
        }  
        else if (pa ->expn > pb->expn )      
        {  
            pc->next = pb;               //pcָ������ָ��С�Ľ�㣬  
            pc = pb;  
            pb = pb->next;               //ָ��ý���ָ�����  
        }  
        else   //(pa ->expn = pb->expn )  
        {  
            pa->coef = pa->coef + pb->coef;     //ָ�����ʱ��ϵ�����  
            pc->next = pa;  
            pc = pa;  
            pa = pa->next;             //��ָ�붼������  
            pb = pb->next;  
        }  
    }  
   
    pc->next = pa ? pa:pb;  // ����ʣ���  
   
    return Lc;  
}  
   
void main()  
{  
    PolynList a,b,c;  
	int n;
    printf("a������Ϊ:");
	scanf("%d",&n);  
    CreatePolyn(a,n);   // ��λ������n��Ԫ�ص�ֵ  
   
    printf("b������Ϊ:");
	scanf("%d",&n);
    CreatePolyn(b,n);   // ��λ������n��Ԫ�ص�ֵ  
   
    printf("����ʽa :");  
    PolynTraverse(a, visit);  
    printf("\n");  
    printf("����ʽb :");  
    PolynTraverse(b, visit);  
    printf("\n");  
   
    c = MergeList(a,b);  
    PolynTraverse(c, visit);  
}
*/