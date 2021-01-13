#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define INIT_SIZE 100	
#define LISTINCREMENT 10

typedef int ElemType;
typedef struct {
	int* elems;
	int len;
	int size;
}ArrayList;

void init(ArrayList & list){
	list.elems = (int*) malloc(sizeof(int)*INIT_SIZE);
	list.size = INIT_SIZE;
	list.len = 0;
}

void print(ArrayList & list){
	for(int i = 0;i<list.len;i++){
		printf("%d  ",list.elems[i]);
	}
	printf("\n");
}

void merge(ArrayList list1,ArrayList list2,ArrayList&list3){
	int* p1,* p2,* p3,* p1_last,*p2_last;
	p1=list1.elems;
	p2=list2.elems;
	list3.size=list3.len=list1.len+list2.len;
	p3=list3.elems=(int*) malloc(list3.size*sizeof(int));
	p1_last=list1.elems+list1.len-1;
	p2_last=list2.elems+list2.len-1;
	while(p1<=p1_last&&p2<=p2_last){
		if(*p1<=*p2) *p3++=*p1++;
		else *p3++=*p2++;
	}
	while(p1<=p1_last) *p3++=*p1++;
	while(p2<=p2_last) *p3++=*p2++;
}

void insert(ArrayList &list,int i,ElemType e){
	int *q,*p;
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

void inputlist(ArrayList &list){
	int i,e;
	for(i=0;;i++){
		scanf("%d",&e);
		insert(list,i+1,e);
		if(getchar()=='\n') break;
	}
}

void main(){
	ArrayList list1;
	init(list1);
	ArrayList list2;
	init(list2);
	ArrayList list3;
	init(list3);
 	
	printf("please input list1:");
	inputlist(list1);
	printf("please input list2:");
	inputlist(list2);

	printf("list1:\n");
	print(list1);
	printf("list2:\n");
	print(list2);
	
	merge(list1,list2,list3);
	printf("list3:\n");	
	print(list3);
}

