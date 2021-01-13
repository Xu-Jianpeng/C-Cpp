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

//随机抽取10000以内的数作为被查询数据
cre(keytype keyp[]){
	int i=rand()%N;
	return i;
}

//定义哈希表的结构体
typedef struct
{
	int *elem;
	int count;
}HashTable;
int m=0;
 
//初始化哈希表
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
 //哈希函数
 int Hash(int key)
 {
 	return key%m;
  } 
  //将数据插入哈希表
  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);
  	while(H->elem[addr]!=NULLKEY)
  		addr=(addr+1)%m;
  	H->elem[addr]=key;
   } 
   
//哈希表查找数据
int SearchHash(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr]!=key)
	{
		*addr=(*addr+1)%m;
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key))
		{
			return -1;//查找失败
		}
	}
	return *addr;//查找成功
 } 

//右旋操作
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

//左旋操作
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

//插入数据到红黑树时的调整
void RB_INSERT_FIXUP(int*KEY,int*L,int*R,int*P,bool*C,int z){
    while(z!=Troot && C[P[z]]==RED)
    {
        if(P[z]==L[P[P[z]]]) //父左则叔右
        {
            int y=R[P[P[z]]];//定义y为叔节点
            if(C[y]==BLACK)//如果父左叔黑
            {
                if(z==L[P[z]])//如果父左叔黑插左
                {
                    int x=P[z];
                    y=P[P[z]];//定义父亲节点为x，祖父节点为y
                    RIGHT_ROTATE(L,R,P,y);//右旋
                    C[x]=BLACK;C[y]=RED;//染色
                }
                else //如果父左叔黑插右
                {
                    int x=P[z];
                    y=P[P[z]];//定义父节点为x祖父节点为y
                    LEFT_ROTATE(L,R,P,x);//左旋父节点
                    z=x;//更新插入节点
                }
            }
            else //如果父左叔红
            {
                int x=P[z];y=P[P[z]];
                int B=R[y];//重新设定x,y和B
                C[x]=BLACK;C[B]=BLACK;C[y]=RED;
                z=y;
            }
        }
        else //父右则叔左
        {
            int y=L[P[P[z]]];
            if(C[y]==BLACK)//父右叔黑
            {
                if(z==R[P[z]])//如果父右叔黑插右
                    {
                        int x=P[P[z]];
                        y=P[z];  //按图定义x和y
                        LEFT_ROTATE(L,R,P,x);
                        C[y]=BLACK;C[x]=RED;
                    }
                    else //父右叔黑插左
                    {
                        int x=P[P[z]];
                        y=P[z];
                        RIGHT_ROTATE(L,R,P,y);
                        z=y;
                    }
            }
            else //父右叔红
            {
                int x=P[P[z]];y=P[z];//按图定义x,y
                int D=L[x];
                C[D]=BLACK;C[y]=BLACK;C[x]=RED;
                z=x;
            }
        }
     C[Troot]=BLACK;
    }
}

//插入数据至红黑树中
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

//红黑树查找
int RB_search(int key,int*KEY,int*LEFT,int*RIGHT,int k){
    if(LEFT[k]!=NIL&&key<LEFT[k]) RB_search(key,KEY,LEFT,RIGHT,LEFT[k]);
    if(key==KEY[k]) return k;//查找成功
    if(RIGHT[k]!=NIL&&key>RIGHT[k]) RB_search(key,KEY,LEFT,RIGHT,RIGHT[k]);
	else return -1;//查找失败
}

//二分查找
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
	return -1;//查找失败
}

//顺序查找
int sq_search(keytype keyp[],keytype key){
	int i;
	for(i=0; i<N; i++)
		if(keyp[i] == key)
			return i;//查找成功
		return -1;//查找失败
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
	//顺序查找
//	cout<<"正在进行顺序查找……"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res = sq_search(keyp,key);
	}
	finish = clock();
	total_time_sq = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"顺序查找所耗时间: "<<total_time_sq<<" seconds"<<endl;
	
	//二分查找
//	cout<<"正在进行二分查找……"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res=b_search(keyp,key);
	}
	finish = clock();
	total_time_b = (double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"二分查找所耗时间: "<<total_time_b<<" seconds"<<endl;

	//红黑树
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
//	cout<<"正在进行红黑树查找……"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = rand();//keyp[cre(keyp)];
		res = RB_search(key,KEY,LEFT,RIGHT,Troot);
	}
	finish = clock();
	total_time_rb = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"红黑树查找所耗时间: "<<total_time_rb<<" seconds"<<endl;

	//哈希表
	HashTable H;
	InitHashTable(&H);
	for(i=0;i<m;i++)
		InsertHash(&H,keyp[i]);
	int addr,j;
//	cout<<"正在进行哈希表查找……"<<endl;
	start = clock();
	for(i=0;i<10*N;i++){
		key = keyp[cre(keyp)];
		res = SearchHash(H,key,&addr);
	}
	finish = clock();
	total_time_hash = (double)(finish-start)/CLOCKS_PER_SEC;
//	cout<<"哈希表查找所耗时间: "<<total_time_hash<<" seconds"<<endl;
}
