#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<queue>
#include<cstdlib>
#include<cstdio>
#include<cstring>
//#include <hash_map>
#define N 10000
#define NIL 10000
#define RED 0
#define BLACK 1
int Troot=1; 
#define HASHSIZE 10000
#define NULLKEY -32768

using namespace std;
//using namespace __gnu_cxx;
//using namespace stdext;


typedef long keytype;
typedef long valuetype;

//�����ȡ10000���ڵ�����Ϊ����ѯ����
cre(keytype keyp[]){
	int i=rand()%N;
	return i;
}

//�����ϣ��Ľṹ��
typedef struct
{
	int *elem;
	int count;
}HashTable;
int m=0;
 
//��ʼ����ϣ��
int InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int*)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY;
	return 1;
 }
 //��ϣ����
 int Hash(int key)
 {
 	return key%m;
  } 
  //�����ݲ����ϣ��
  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);
  	while(H->elem[addr]!=NULLKEY)
  		addr=(addr+1)%m;
  	H->elem[addr]=key;
   } 
   
//��ϣ���������
int SearchHash(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr]!=key)
	{
		*addr=(*addr+1)%m;
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key))
		{
			return -1;//����ʧ��
		}
	}
	return *addr;//���ҳɹ�
 } 

//��������
void RIGHT_ROTATE(int*L,int*R,int*P,int y){//y!=NIL && L[y]!=NIL
    int x=L[y];int A=P[y],D=R[x];
    if(D!=NIL) P[D]=y;
    P[x]=A;
    P[y]=x;
    R[x]=y;
    L[y]=D;
    if(A!=NIL)
    {
        if(L[A]==y) L[A]=x;
        else R[A]=x;
    }
    else Troot=x;
}

//��������
void LEFT_ROTATE(int*L,int*R,int*P,int x){//x!=NIL && R[x]!=NIL
    int y=R[x];int A=P[x],D=L[y];
    if(D!=NIL) P[D]=x;
    P[y]=A;
    P[x]=y;
    L[y]=x;
    R[x]=D;
    if(A!=NIL)
    {
        if(L[A]==x) L[A]=y;
        else R[A]=y;
    }
    else Troot=y;
}

//�������ݵ������ʱ�ĵ���
void RB_INSERT_FIXUP(int*KEY,int*L,int*R,int*P,bool*C,int z){
    while(z!=Troot && C[P[z]]==RED)
    {
        if(P[z]==L[P[P[z]]]) //����������
        {
            int y=R[P[P[z]]];//����yΪ��ڵ�
            if(C[y]==BLACK)//����������
            {
                if(z==L[P[z]])//���������ڲ���
                {
                    int x=P[z];
                    y=P[P[z]];//���常�׽ڵ�Ϊx���游�ڵ�Ϊy
                    RIGHT_ROTATE(L,R,P,y);//����
                    C[x]=BLACK;C[y]=RED;//Ⱦɫ
                }
                else //���������ڲ���
                {
                    int x=P[z];
                    y=P[P[z]];//���常�ڵ�Ϊx�游�ڵ�Ϊy
                    LEFT_ROTATE(L,R,P,x);//�������ڵ�
                    z=x;//���²���ڵ�
                }
            }
            else //����������
            {
                int x=P[z];y=P[P[z]];
                int B=R[y];//�����趨x,y��B
                C[x]=BLACK;C[B]=BLACK;C[y]=RED;
                z=y;
            }
        }
        else //����������
        {
            int y=L[P[P[z]]];
            if(C[y]==BLACK)//�������
            {
                if(z==R[P[z]])//���������ڲ���
                    {
                        int x=P[P[z]];
                        y=P[z];  //��ͼ����x��y
                        LEFT_ROTATE(L,R,P,x);
                        C[y]=BLACK;C[x]=RED;
                    }
                    else //������ڲ���
                    {
                        int x=P[P[z]];
                        y=P[z];
                        RIGHT_ROTATE(L,R,P,y);
                        z=y;
                    }
            }
            else //�������
            {
                int x=P[P[z]];y=P[z];//��ͼ����x,y
                int D=L[x];
                C[D]=BLACK;C[y]=BLACK;C[x]=RED;
                z=x;
            }
        }
     C[Troot]=BLACK;
    }
}

//�����������������
void RB_INSERT(int*KEY,int*L,int*R,int*P,bool*C){
    for(int k=2;k<=N;k++)
    {
        int y=NIL,x=Troot;
        while(x!=NIL)
        {
            y=x;
            if(KEY[k]<KEY[x]) x=L[x];
            else x=R[x];
        }
        P[k]=y;
        if(KEY[k]<KEY[y]) L[y]=k;
        else R[y]=k;
        C[k]=RED;
        RB_INSERT_FIXUP(KEY,L,R,P,C,k);
    }
}

//���������
int RB_search(int key,int*KEY,int*LEFT,int*RIGHT,int k){
    if(LEFT[k]!=NIL&&key<LEFT[k]) RB_search(key,KEY,LEFT,RIGHT,LEFT[k]);
    if(key==KEY[k]) return k;//���ҳɹ�
    if(RIGHT[k]!=NIL&&key>RIGHT[k]) RB_search(key,KEY,LEFT,RIGHT,RIGHT[k]);
	else return -1;//����ʧ��
}

//���ֲ���
int b_search(keytype keyp[],keytype key) {
	int low, mid, high;
	low = 0;
	high = N - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == keyp[mid]) {
			return mid;
		} else if (key < keyp[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;//����ʧ��
}

//˳�����
int sq_search(keytype keyp[],keytype key){
	int i;
	for(i=0; i<N; i++)
		if(keyp[i] == key)
			return i;//���ҳɹ�
		return -1;//����ʧ��
}

main(){
	keytype key;
	keytype keyp[N];
	int i,res;
	clock_t start, finish;
	double total_time_sq,total_time_b,total_time_rb,total_time_hash;
	for(i=0;i<N;i++){
		keyp[i]=rand();
	}
	//˳�����
//	cout<<"���ڽ���˳����ҡ���"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res = sq_search(keyp,key);
	}
	finish = clock();
	total_time_sq = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"˳���������ʱ��: "<<total_time_sq<<" seconds"<<endl;
	
	//���ֲ���
//	cout<<"���ڽ��ж��ֲ��ҡ���"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res=b_search(keyp,key);
	}
	finish = clock();
	total_time_b = (double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"���ֲ�������ʱ��: "<<total_time_b<<" seconds"<<endl;

	//�����
	queue<int>import;
	int *KEY=(int*)malloc(sizeof(int)*(N+2));
	fill(KEY,KEY+(N+2),NIL);
	for(i=1;i<=N;i++)
	{
		KEY[i]=keyp[i];
	}

	int *LEFT=(int*)malloc(sizeof(int)*(N+2));
	fill(LEFT,LEFT+(N+2),NIL);
	int *RIGHT=(int*)malloc(sizeof(int)*(N+2));
	fill(RIGHT,RIGHT+(N+2),NIL);
	int *PARENT=(int*)malloc(sizeof(int)*(N+2));
	fill(PARENT,PARENT+(N+2),NIL);
	bool*COLOR=(bool*)malloc(sizeof(bool)*(NIL+10));
	fill(COLOR,COLOR+(NIL+10),BLACK);
	RB_INSERT(KEY,LEFT,RIGHT,PARENT,COLOR);
//	cout<<"���ڽ��к�������ҡ���"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res = RB_search(key,KEY,LEFT,RIGHT,Troot);
	}
	finish = clock();
	total_time_rb = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"�������������ʱ��: "<<total_time_rb<<" seconds"<<endl;

	//��ϣ��
	HashTable H;
	InitHashTable(&H);
	for(i=0;i<m;i++)
		InsertHash(&H,keyp[i]);
	int addr,j;
//	cout<<"���ڽ��й�ϣ����ҡ���"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = keyp[cre(keyp)];
		res = SearchHash(H,key,&addr);
	}
	finish = clock();
	total_time_hash = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"��ϣ���������ʱ��: "<<total_time_hash<<" seconds"<<endl;
}
