#include <stdio.h>
#include <math.h>

int main(){
	char *a=new char[];
	int i=0,j=0,k=0,mark;
	while((a[i]=getchar())!='\n'){
		if(a[i]==' '&&i==0) continue;
		if(a[i]>='a'&&a[i]<='z') a[i]=a[i]-'a'+'A';
		if(a[i]!=' '&&(a[i]<'A'||a[i]>'Z')) mark=1;
		if(a[i]==' '&&a[i-1]!=' '){
			k++;
			if(mark==1){
				j++;
				mark=0;
			}
		}
		i++;
	}
	if(a[i-1]!=' ') k++;
	if(mark==1)	j++;
	printf("%d",k-j);

	return 0;
}
/*
#include <stdio.h>
#include <math.h>

int main(){
	char *a=new char[];
	int i=0,j=0,k=0,mark,length=0;
	while(a[length-1]!='\n'){
		a[length]=getchar();
		if(a[length]>='a'&&a[length]<='z') a[length]=a[length]-'a'+'A';
		length++;
	}
	length-=1;
	while(i<length){
		while(a[i]==' ') i++;
		while(a[i]!=' '&&a[i]!='\n'){
			if(a[i]<'A'||a[i]>'Z') mark=1;
			i++;
		}
		if(mark==1){
			j++;
			mark=0;
		}
		k++;
		i++;
	}
	printf("%d",k-j);
	return 0;
}
*/

/*
#include <stdio.h>
#include <math.h>

int check(int n){
	for(int i=2;i<=n/2;i++)
		if(n%i==0) return 1;
	return 0;
}

int main(){
	int m,n;
	scanf("%d",&m);
	for(n=pow(10,m)-1;n>=pow(10,m-1);n--)
		if(!check(n)) break;
	printf("%d",n);
	return 0;
}
*/

/*
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a=0;
	int b;
	cin>>b;
	for(int i=3;i>=0;i--){
		a+=(b%10+5)%10*pow(10,i);
		b/=10;
	}
	//b=1000*a[0]+100*a[1]+10*a[2]+a[3];
	cout<<a;
	return 0;
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define N 10

int main(){
	double a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	int min=0,max=0;
	for(i=0;i<N;i++){
		if(a[i]<a[min]) min=i;
		if(a[i]>a[max]) max=i;
	}
	a[min]=0;
	a[max]=0;
	for(i=1;i<N;i++) a[0]+=a[i];
	cout<<a[0]/(N-2)<<endl;
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int check(int a){
	int i=2;
	while(i<=a/2){
		if(a%i==0) return 1;
		i++;
	}
	return 0;
}

int main(){
	int a;
	while(a!=0){
		cin>>a;
		//bool b=check(a)==1?true:false;
		cout<<(check(a)==1?"true":"false")<<endl;
	}
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
	int i;
	char *a=new char[];
	char *b=new char[];
	cin>>a;
	cin>>b;
	int j=strlen(a);
	for(i=0;i<strlen(b);i++)
		a[j+i]=b[i];
	for(i=0;i<j+strlen(b);i++)
		cout<<a[i];
	return 0;
}
*/
/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
	double left=-2;
	double right=-1;
	double x=(left+right)/2;
	while(right-left>0.000001){
		if(x*x*x*x*x+3*x*x*x+7>0)
			right=x;
		else if(x*x*x*x*x+3*x*x*x+7<0)
			left=x;
		x=(left+right)/2;
		cout<<left<<" "<<right<<"\n";
	}
	cout<<"result is:"<<x;
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int match(char *a,char *b){
	int i=0,j=0,k=-1;
	while(i<strlen(a)){
		if(j>=strlen(b)){
			k=i-j;
			break;
		}
		while(j<strlen(b)){
			if(b[j]==a[i]){
				i++;
				j++;
			}
			else{
				i=i-j+1;
				j=0;
				break;
			}
		}
	}
	return k;
}

int main(){
	char* a=new char[];
	char* b=new char[];
	cin>>a;
	cin>>b;
	cout<<match(a,b);
	return 0;
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define N 3

int main(){
	int a[N][N]={1,2,4,9,7,5,10,11,12};
	int b[N*N];
	int k=0;
	for(int i=0;i<N;i++){
		if(i%2==0) 
			for(int j=0;j<N;j++){
				b[k]=a[i][j];
				k++;
			}
		else 
			for(int j=N-1;j>=0;j--){
				b[k]=a[i][j];
				k++;
			}
	}
	for(i=0;i<k;i++)
		cout<<b[i]<<" ";
	return 0;
}
*/

/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
	char* a=new char[];
	int j=0;
	cout<<"please input the string:";
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]<'0'||a[i]>'9'){
			a[j]=a[i];
			j++;
		}
	}
	for(i=0;i<j;i++)
		cout<<a[i];
	cout<<endl;
//	delete []a;
	return 0;
}
*/
/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define N 2

void merge(int x[][N],int y[][N]){
	int z[N][N];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j) z[i][j]=(x[i][j]<y[i][j]?x[i][j]:y[i][j]);
			else z[i][j]=x[i][j]*y[i][j];
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			cout<<z[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int i,j;
	int x[N][N]={1,2,3,4};
	int y[N][N]={2,5,77,17};
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			cout<<x[i][j]<<" ";
		cout<<endl;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			cout<<y[i][j]<<" ";
		cout<<endl;
	}
	merge(x,y);

	return 0;
}
*/
/*
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void add(char *a,char *b){
	char *c=new char[strlen(a)+strlen(b)];
	int i=0,j=0,k=0;
	while(i<strlen(a)){
		if(j>=strlen(b)) break;
		while(j<strlen(b)){
			if(i>=strlen(a)) break;
			c[k]=a[i];
			c[k+1]=b[j];
			k+=2;
			i++;
			j++;
		}
	}
	cout<<i<<" "<<j<<endl;
	cout<<strlen(a)<<" "<<strlen(b)<<endl;
	while(i<strlen(a)) {c[k]=a[i];k++;i++;}
	while(j<strlen(b)) {c[k]=b[j];k++;j++;}
	for(i=0;i<k;i++) cout<<c[i];
	cout<<endl;
	cout<<k<<endl;

}

int main(){
	char *a=new char[];
	char *b=new char[];
	cout<<"please input string1:";
	cin>>a;
	cout<<"please input string2:";
	cin>>b;
	add(a,b);

	return 0;
}
*/

/*
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int j;
	double a;
	cout<<"π/4=";
	for(double i=1;;i++){
		a=1/(2*i-1);
		//cout<<a;
		j=i;
		if(a<0.0001) break;
		else if(j==1) cout<<"1";
		else if(j%2!=0&&j<=4) cout<<"+1/"<<2*i-1;
		else if(j%2==0&&j<=4)cout<<"-1/"<<2*i-1;
	}
	if((j-1)%2!=0) cout<<"+...+1/"<<2*i-3<<endl;
	else cout<<"...-1/"<<2*i-3<<endl;
}
*/
/*
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double a=rand(),b=rand(),c=rand(),d=rand()%10,e=rand()%2;
	double x,y;
	cout<<a<<"+"<<b<<"-"<<c<<"*"<<d<<"/"<<e<<"=?"<<endl;
	cout<<"your answer is:";
	cin>>x;
	y=a+b-c*d/e;
	cout<<"right answer is:"<<y<<endl;
	if(x==y) cout<<"your answer is true"<<endl;
	else cout<<"your answer is false"<<endl;
}
*/
/*
#include <iostream>
using namespace std;

int main(){
	char a[4]={'A','B','C','D'};
	char b[4]={'W','X','Y','Z'};
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			if(a[i]=='A'&&b[j]=='W') continue;
			else if(a[i]=='B'&&(b[j]=='W'||b[j]=='X')) continue;
			else if(a[i]=='C'&&b[j]=='Z') continue;
			cout<<a[i]<<"vs"<<b[j]<<" ";
		}
	cout<<endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main(){
	int year,month,day,date=0;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	cout<<"please input the date(like 2020 12 19):";
	cin>>year>>month>>day;
	if(year%4==0)
		a[1]=29;
	for(int i=0;i<month-1;i++){
		date+=a[i];
	}
	date+=day;
	cout<<date;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

void change(long int x){
	int n=0;
	if(x!=0) n=1;
	while((x/10)!=0){
		cout<<(x%10);
		x=(x-x%10)/10;
		n++;
	}

	cout<<x<<endl<<n<<endl;
}

int main(){
	long int x;
	cout<<"please input a number:";
	cin>>x;
	change(x);
	return 0;
}
*/

/*
//给n个数从小到大排序
#include<iostream>
using namespace std;
int temp;
//冒泡
void bubble(int p[],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(p[j]<p[i]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
}
//快速
void quick(int p[],int low,int high){
	temp=p[low];
	int i=low,j=high;
	if(i<j){
		while(i<j){
			while(i<j&&p[j]>=temp) j--;
			p[i]=p[j];
			while(i<j&&p[i]<=temp) i++;
			p[j]=p[i];
		}
		p[i]=temp;
		quick(p,low,j-1);
		quick(p,i+1,high);
	}
}
//直插
void insert(int p[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		temp=p[i];
	//	int k=i;
	//	while(k>0&&temp<p[k-1]){
	//		p[k]=p[k-1];
	//		k--;
	//	}
	//	p[k]=temp;
		for(k=i;temp<p[k-1];k--)
			p[k]=p[k-1];
		p[k]=temp;
		for(j=0;j<n;j++){
			cout<<p[j]<<" ";
		}
		cout<<endl;
	}
}
//折插
void insert1(int p[],int n){
	int i,j,low,high,mid;
	for(i=1;i<n;i++){
		temp=p[i];
		low=0;
		high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(p[mid]>temp) high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>high;j--)
			p[j+1]=p[j];
		p[high+1]=temp;
	}	
}
//选排
void select(int p[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i;j<n;j++){
			if(p[j]<p[min]) min=j;
		}
		temp=p[i];
		p[i]=p[min];
		p[min]=temp;
		for(j=0;j<n;j++)
			cout<<p[j]<<" ";
		cout<<endl;
	}
}

int main(){
	int i,n;
	cout<<"how many numbers do you want to sort:"<<endl;
	cin>>n;
	int *p=new int[n];
	cout<<"please input the numbers:"<<endl;
	for(i=0;i<n;i++){
		cin>>p[i];
	}
	//bubble(p,n);
	//quick(p,0,n-1);
	//insert(p,n);
	//insert1(p,n);
	select(p,n);
	cout<<"sorted:";
	for(i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete []p;

	return 0;
}
*/




/*#include<iostream>
using namespace std;

void fun(char *s);
int main(){
	char a[]="12345";
	printf("*a=%p\n",&a);
	printf("&a[0]=%p\n",&a[0]);
	printf("a[0]=%c\n",a[0]);
	printf("*a=%c\n",*a);
	printf("a[1]=%c\n",a[1]);
	printf("*a+1=%c\n",*a+1);

//	fun(a);
	printf("%s\n",a);
}

void fun(char *s){
	//s=s+2;
	*(s+2)=*s+4;
}*/
/*
#include<stdio.h>
#include<string.h>
#define Maxsize 255

typedef struct{
	char ch[Maxsize];
	int Length;
}String;

int main(){
	String Input();//函数可直接传回结构体 
	void Output(String *mr);
	void Parex(String p1,String p2);
	int i;
	String S,s1,*p,*q;
	S=Input();
	s1=Input();
	p=&S;
	q=&s1;
	Output(p);
	Output(q);
	Parex(S,s1);
	return 0;
}

String Input(){
	String SS;
	printf("please input number:\n");
	//SS.ch[0]=NULL;
	for(int i=1;i<=Maxsize;i++){
		scanf("%c",&SS.ch[i]);
		if(SS.ch[i]=='\n')
		{
			SS.Length=i-1;
			break;
		}
	}
	return SS;
}

void Output(String *mr){
	int i; 
	printf("the string is :\n");
	for(i=1;i<(mr->Length);i++){
	printf("%c ",mr->ch[i]);//注意是mr->ch[i],而不是*mr->ch[i] 
	}
	printf("\nthe sum is: %d\n",mr->Length);
}

void Parex(String p1,String p2){
	int i=1,j=1;	
	printf("%d\n",p2.Length);
	while(i<=p1.Length&&j<=p2.Length){
		if(p1.ch[i]==p2.ch[j]){
			printf("%c %c\n",p1.ch[i],p2.ch[j]);
			++i;
			++j;
		}
		else{
			i=i-j+2;
			j=1;
		}
	}
	if(j>p2.Length)
	printf("true\n");
	else
	printf("false\n");
	
	
	
	
}*/


/*求最大公因数的两个算法*/
/*法一：穷举法略*/
/*法二：辗转相除法：
#include<iostream>
using namespace std;

int main(){
	int a,b;
	cout<<"please input a,b(a>b): ";
	cin>>a>>b;
	int c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	cout<<"a,b的最大公因数为："<<b<<endl;
}
*/
/*在给定数组中找到某个数是否在数组中(两种方法)*/
/*法一：遍历查找
#include<iostream>
using namespace std;

int main(){
	int m[10]={1,3,7,9,10,12,15,18,20,39};
	int i,n;
	cout<<"please input n: ";
	cin>>n;
	for(i=0;i<10;i++)
		if(m[i]==n){
			cout<<"true"<<endl;
			break;
		}
	if(i==10) cout<<"false"<<endl;

	return 0;
}
*/
/*法二：折半查找
#include<iostream>
using namespace std;
#define N 10

bool tof=false;
void find(int n,int i,int j,int *m){
	if(i<=j){
		int mid=(i+j)/2;
		if(n==m[mid]){
			cout<<"\ntrue:"<<n<<endl;
			tof=true;
		}
		else{
			cout<<"false:"<<m[mid]<<"   ";
			n<m[mid]?find(n,i,mid-1,m):find(n,mid+1,j,m);
		}
	}
}

int main(){
	int m[N]={1,3,7,9,10,12,15,18,20,39};
	int n;
	cout<<"please input n: ";
	cin>>n;
	find(n,0,N-1,m);
	if(!tof) 
		cout<<"\nfalse"<<endl;

	return 0;
}
*/
/*后序遍历查找数element
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* left;
	struct Node* right;
} Node;

//创建一个存储字符c 的结点，左右子树均设置为空值
Node* crtNode(char c) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = c;
	n->left = NULL;
	n->right = NULL;
	return n;
}
//前序输入构建二叉树
void crtTree(Node* &root) {
	char c;
	scanf("%c", &c);
	if (c == ' ') {
		root = NULL;
	} else {
		root = (Node*)malloc(sizeof(Node));
		root->data = c;
		crtTree(root->left);
		crtTree(root->right);
	}
}

//前序遍历
void preorder(Node *root) {
	if (root != NULL) {
		preorder(root->left);
		preorder(root->right);
		printf("%c ", root->data);
	}
}

bool find(Node *root,int element){
	if(root != NULL){
		if(find(root->left,element)||find(root->right,element)||root->data==element+48){
		//	cout<<(int)root->data-48;
			return true;
		}
		else 
			return false;
	}
	else 
		return false;
}
int main() {
	int sum=0,element;
	Node* root;
	crtTree(root);
	preorder(root);
	printf("\n");
	cout<<"please input the element you want to search:"<<endl;
	cin>>element;
	if(find(root,element))
		cout<<"true"<<endl;
	else 
		cout<<"false"<<endl;

	return 0;
}
*/

/*给n个数从小到大排序
#include<iostream>
using namespace std;

int main(){
	int i,j,n,temp;
	cout<<"how many numbers do you want to sort:"<<endl;
	cin>>n;
	int *p=new int[n];
	cout<<"please input the numbers:"<<endl;
	for(i=0;i<n;i++){
		cin>>p[i];
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(p[j]<p[i]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
	cout<<"sorted:";
	for(i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete []p;

	return 0;
}
*/

/*租船问题
#include<iostream>
using namespace std;

int main(){
	int i=46/6+1,j=46/4+1;
	cout<<i<<","<<j<<endl;
	int big,small;
	int min=i*24+j*20;
	for(i=46/6+1;i>0;i--){
		for(j=46/4+1;j>0;j--){
			if(i*6+j*4>=46&&i*24+j*20<min){
				big=i;
				small=j;
				min=big*24+small*20;
			}
		}
	}
	cout<<"Big boat:"<<big<<endl;
	cout<<"Small boat:"<<small<<endl;
	cout<<"The price:"<<big*24+small*20<<endl;

	return 0;
}
*/
/* 给出两个正整数求最大公因数和最小公倍数 
#include<iostream>
using namespace std;

int i,j;

int find_gys(int a,int b){
	for(i=(a>b?b:a);i>0;i--)
		if(a%i==0&&b%i==0)
			return i;
}

int find_gbs(int a,int b){
	for(j=(a>b?a:b);j<=a*b;j++)
		if(j%a==0&&j%b==0)
			return j;
}


int main(){
	int m,n;
	int gys,gbs;
	cout<<"please input two numbers:"<<endl;
	cin>>m>>n;
	gys=find_gys(m,n);
	gbs=find_gbs(m,n);
	cout<<"最大公因数是："<<gys<<endl;
	cout<<"最小公倍数是："<<gbs<<endl;

	return 0;
}
*/

/*
利用两个栈计算一位数的+ - * / 和 () 的简单方式
#include<iostream>
#include<string>
#include<Cmath>
using namespace std;

int num[100],a=0;
void push(char *s,char n){
	s[a]=n;
	a++;
}
void pushnum(int *u,int p){
	u[a]=p;
	a++;
}
void pop(){
	a--;
}

int main(){
	int i,j=0,sum=0;
	int x,y,z;
	char s1[100],s2[100],m[100];
	int num[100];
	char temp;
	//输入算式
	cout<<"please input your formula:"<<endl;
	while(m[sum-1]!='='){
		m[sum]=getchar();
		sum++;
	}
	sum--;
	//解析算式并处理成后缀表达式
	for(i=0;i<sum;i++){
		if(m[i]>=48&&m[i]<=57){
			s1[j]=m[i];
			j++;
		}
		else if(m[i]=='+'||m[i]=='-'){
			if(a==0)
				push(s2,m[i]);
			else if(s2[a-1]=='+'||s2[a-1]=='-'||s2[a-1]=='*'||s2[a-1]=='/'){
				s1[j]=s2[a-1];
				j++;
				pop();
				push(s2,m[i]);
			}
			else 
				push(s2,m[i]);
		}
		else if(m[i]=='*'||m[i]=='/'){
			if(a==0)
				push(s2,m[i]);
			else if(s2[a-1]=='*'||s2[a-1]=='/'){
				s1[j]=s2[a-1];
				j++;
				pop();
				push(s2,m[i]);
			}
			else 
				push(s2,m[i]);
		}
		else if(m[i]=='(')
			push(s2,m[i]);
		else if(m[i]==')'){
			while(s2[a-1]!='('){
				s1[j]=s2[a-1];
				j++;
				pop();
			}
			pop();
		}
	}
	//储存后缀表达式
	while(a>=0){
		s1[j]=s2[a-1];
		j++;
		pop();
	}
	for(i=0;i<j-1;i++)
		cout<<s1[i];
	sum=j-1;
	a=0;
	cout<<endl;
	//进行计算
	for(i=0;i<sum;i++){
		if(s1[i]>=48&&s1[i]<=57){
			pushnum(num,(int)(s1[i]-48));
		}
		else {
			if (s1[i]=='+'){
				y=num[a-1];
				pop();
				x=num[a-1];
				pop();
				z=x+y;
				cout<<x<<"+"<<y<<"="<<z<<endl;
				pushnum(num,z);
			}
			else if (s1[i]=='-'){
				y=num[a-1];
				pop();
				x=num[a-1];
				pop();
				z=x-y;
				cout<<x<<"-"<<y<<"="<<z<<endl;
				pushnum(num,z);
			}
			else if (s1[i]=='*'){
				y=num[a-1];
				pop();
				x=num[a-1];
				pop();
				z=x*y;
				cout<<x<<"*"<<y<<"="<<z<<endl;
				pushnum(num,z);
			}
			else if (s1[i]=='/'){
				y=num[a-1];
				pop();
				x=num[a-1];
				pop();
				z=x/y;
				cout<<x<<"/"<<y<<"="<<z<<endl;
				pushnum(num,z);
			}
		}
	}
	cout<<"the result is:"<<num[a-1]<<endl;
	pop();
	return 0;
}
*/
/*
#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

int main(){
	int i,j,k,b1,b2,n=0;
	int order[8],score[9],pb[9],b[9],result[9][9];
	for(i=0;i<9;i++){
		score[i]=0;
		pb[i]=0;
		b[i]=0;
	}
	srand((unsigned)time(NULL));
	for(i=1;i<8;i++){
		for(j=i+1;j<9;j++){
			b1=rand()%6;//i队的进球数
			b2=rand()%6;//j队的进球数
			while(b1==b2){
				b1=rand()%6;
				b2=rand()%6;
			}
			result[i][j]=(b1>b2?i:j);
			cout<<i<<"vs"<<j<<" ";
			cout<<b1<<":"<<b2<<" ";
			b[i]+=b1;
			b[j]+=b2;
			pb[i]+=(b1-b2);
			pb[j]+=(b2-b1);
			score[result[i][j]]+=3;
		}
		cout<<endl;
	}
	for(i=1;i<9;i++) 
		cout<<"第"<<i<<"队的积分:"<<score[i]<<"\t净胜分:"<<pb[i]<<"\t进球数:"<<b[i]<<endl;
	for(i=1;i<9;i++){
		k=i;
		for(j=1;j<9;j++){
			if(score[k]<score[j])
				k=j;
			else if(score[k]==score[j]){
				if(pb[k]<pb[j]) k=j;
				else if(b[k]<b[j]) k=j;
				else if(result[k][j]==j) k=j;
			}
		}
		order[n]=k;
		n++;
		score[k]=0;
	}
	cout<<"小组名次排序"<<endl;
	for(i=0;i<8;i++)
		cout<<"第"<<i+1<<"名:"<<order[i]<<endl;
	
	return 0;
}
*/


/*#include<iostream>
#include<string>
using namespace std;

int num[100],a=0;
void push(int n){
	num[a]=n;
	a++;
}
void pop(int n){
	a--;
}

int main(){
	int i=0,j;
	char m[100];
	cout<<"please input your formula:"<<endl;
	while(m[i-1]!='\n'){
		m[i]=getchar();
		i++;
	}
	//cout<<m;
	for(j=0;j<i;j++){
		cout<<m[j];
	}

	return 0;
}
*/
/*#include<iostream>
#include<cmath>
using namespace std;

double root(double a,double b,double eps,double(*f)(double)){
	double f0,f1,c;
	f0=(*f)(a);
	while(fabs(a-b)>=eps){
		c=(a+b)/2;
		f1=(*f)(c);
		if(f1+1==1) return c;
		if(f0*f1>0) a=c;
		else b=c;
	}
	c=(a+b)/2;
	return c;
}

int main(){
	double a=0,b=3;
	double f(double);
	cout<<root(a,b,0.00001,f)<<endl;
	return 0;
}

double f(double x){
	return x*x*x-x*x-1;
}*/

/*#include<iostream>
using namespace std;

int fun(int a[],int m,int n){
	int maxm,maxn,max;
	if(m==n) return a[m-1];
	else{
		maxm=fun(a,m,(m+n)/2);
		maxn=fun(a,(m+n)/2+1,n);
		//max=maxm>maxn?maxm:maxn;
		cout<<maxm<<"  "<<maxn<<endl;
		return maxm>maxn?maxm:maxn;
	}
}

int main(){
	int a[16]={2,5,4,8,6,3,2,1,4,7,9,1,5,8,6,0};
	cout<<"m="<<fun(a,1,16)<<endl;
	return 0;
}*/

/*#include<iostream>
using namespace std;

int fun(int a,int b,int c){
	if(a>b){
		return c>a?a:(c>b?c:b);
	}
	else{
		return c>b?b:(c>a?c:a);
	}
}

int main(){
	int a,b,c;
	cout<<"input a b c:"<<endl;
	cin>>a>>b>>c;
	cout<<"m="<<fun(a,b,c)<<endl;
	return 0;
}*/


/*#include<stdio.h>

main(){
	int i=0,sum=0,n=10;
	while(sum<n) {i++;sum+=i;printf("%d\t",sum);}
	printf("\n%d",i);
}
*/


/*#include<stdio.h>

main(){
	int a=1,b=1;
	//printf("%d",a^b);
	printf("%d",a&b<<1);
}
*/


/*#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

main(){
	srand(time(0));
	int i,j,k;
	string a[3][17];
	string b[3];
	string poker[54]={"A","A","A","A","2","2","2","2",
		"3","3","3","3","4","4","4","4","5","5","5","5",
		"6","6","6","6","7","7","7","7","8","8","8","8",
		"9","9","9","9","10","10","10","10",
		"J","J","J","J","Q","Q","Q","Q","K","K","K","K",
		"MAXJOKER","minjoker"};
	for(i=0;i<3;i++)
		for(j=0;j<17;){
			k=rand()%54;
			if(poker[k]!="NULL"){
				a[i][j]=poker[k];
				poker[k]="NULL";
				j++;
			}
		}
		for(i=0;i<3;i++){
			cout<<"第"<<i+1<<"位玩家的牌为:"<<' ';
			for(j=0;j<17;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
		j=0;
		for(i=0;i<54;i++)
			if(poker[i]!="NULL"){
				b[j]=poker[i];
				j++;
			}
			
		cout<<"地主牌为:"<<' ';
		for(j=0;j<3;j++)
			cout<<b[j]<<' ';
		cout<<endl;
}*/












/*#include<stdio.h>
#include<string.h>

main(){
	char s1[32];
	char s2[32];
	strcpy(s1, "1234567");
	strcpy(s2, "abcdefg");
	printf("%s, %s\n", s1, s2);
	strcpy(s2, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	printf("%s, %s\n", s1, s2);
	
	char students[10000];
	strcpy(students, "Student List:\n");
	char student[100];
	while (true)
	{
	scanf("%99s", student);
	if (strcmp(student, "\0") == 0)
		break;
	strcat(students, student);
	strcat(students, "\n");
	}
	printf("%s\n", students);
}*/








/*#include<stdio.h>
#include<stdlib.h>
 
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct
{
	int *elem;
	int count;
}HashTable;
int m=0;
 
//初始化散列表
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
 //散列函数
 int Hash(int key)
 {
 	return key%m;
  } 
  //插入关键字进入散列表
  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);
  	while(H->elem[addr]!=NULLKEY)
  		addr=(addr+1)%m;
  	H->elem[addr]=key;
   } 
   
//散列表查找关键字
int SearchHash(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr]!=key)
	{
		*addr=(*addr+1)%m;
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key))
		{
			return -1;
		}
	}
	return *addr;
 } 
  
int main()
{
	int a[12]={12,67,56,16,25,37,22,29,15,47,48,34};
	HashTable H;
	int i;
	InitHashTable(&H);
	for(i=0;i<m;i++)
		InsertHash(&H,a[i]);
	printf("插入之后的哈希表为：");
	for(i=0;i<m;i++)
		printf("%d,",H.elem[i]);
	int addr,j;
	j=SearchHash(H,25,&addr);
	printf("搜索到25的地址是：%d",j);
}*/

/*#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 7  //哈希函数的除数 跟数据的个数相关（取素数）
#define NULLKEY -32768//进行数组的初始化
#define OK 1
#define ERROR 0
typedef int  Statu;//返回值的数据类型
typedef struct hashtable
{
    int *elem;//哈希表的数据域（类似于一维数组）
    int count;//哈希表的数据元素点的个数
}HashTable;//哈希表的结构体
void test();//测试函数
void insert_hashtable(HashTable**hashtable,int data);//在哈希表中插入数据元素（创建过程）
Statu search_hashtable(HashTable*hashtable,int data);//数据元素的查找 返回状态值
void Display_hashtable(HashTable*hashtable);//遍历哈希表的数据
void Init(HashTable**hashtable);//对哈希表进行初始化
int Hash_fun(int data);//哈希表函数
void main()
{
    test();//测试函数

}
int Hash_fun(int data)//哈希表函数
{
    return (data%HASHSIZE);//利用hash函数计算元素所在的位置

}

void Init(HashTable**hashtable)//对哈希表进行初始化
{
    int m=HASHSIZE;
    int i;
    (*hashtable)->elem=(int *)malloc(sizeof(int )*m);//动态赋值存储空间
    (*hashtable)->count=m;//哈希表中数据元素的个数
    for(i=0;i<m;i++)
    {
        (*hashtable)->elem[i]=NULLKEY;//对哈希表的数据域进行初始化

    }
}
void insert_hashtable(HashTable**hashtable,int data)
{
    int hashaddress;//元素的插入位置
    hashaddress=Hash_fun(data);
      while((*hashtable)->elem[hashaddress]!=NULLKEY)
      {
          hashaddress=(++hashaddress)%HASHSIZE;
    }
         (*hashtable)->elem[hashaddress]=data;//对元素进行插入
}
Statu search_hashtable(HashTable*hashtable,int data)
{
    int hashaddress=Hash_fun(data);
  while(hashtable->elem[hashaddress]!=data)
  {
      hashaddress=(++hashaddress)%HASHSIZE;
        if(hashtable->elem[hashaddress]==NULLKEY||hashaddress==Hash_fun(data))
            return -1;//表明查找失败
            //hashaddress==Hash_fun(data)说明查找元素的位置处在数据的中间
            //表明已经结束回到哈希函数计算的位置 说明要查询的数据没有找到 查询失败
            //hashtable->elem[hashaddress]==NULLKEY 表明查找的元素的位置处在数据域的两端
             //此时条件表明查找的范围已经超出了数据域的范围  查找失败
}
  return hashaddress;//返回数据所在的位置
}
void Display_hashtable(HashTable*hashtable)
{
    //对哈希表的元素进行遍历
    int i;
    for(i=0;i<hashtable->count;i++)
    {
        printf("%d\t",hashtable->elem[i]);
    }
}
void test()//测试函数
{
    HashTable*hashtable;
    int i;
    int data;//待查询的数据
    hashtable=(HashTable*)malloc(sizeof(HashTable));//创建哈希表指针变量  并附存储空间
     Init(&hashtable);//对法哈希表进行初始化
     int hash_array[HASHSIZE];
     printf("请输入哈希表的元素:\n");
       for(i=0;i<HASHSIZE;i++)
        scanf("%d",&hash_array[i]);
         //哈希表元素的插入
         for(i=0;i<HASHSIZE;i++)
         insert_hashtable(&hashtable,hash_array[i]);
         printf("哈希表遍历结果为:\n");
          Display_hashtable(hashtable);
          printf("\n");//换行
           printf("请输入要查询的数据:\n");
             scanf("%d",&data);
             int result=search_hashtable(hashtable,data);
             if(result==-1)
             {
                 printf("查询失败！\n");
             }
             else
             {
                 printf("带查询数据%d在哈希表的位置为%d",data,result);
             }
}
*/

/*#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
#define NIL 500
#define RED 0
#define BLACK 1
int Troot=1;

void RIGHT_ROTATE(int*L,int*R,int*P,int y)//y!=NIL && L[y]!=NIL
{
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
void LEFT_ROTATE(int*L,int*R,int*P,int x)//x!=NIL && R[x]!=NIL
{
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

void RB_INSERT_FIXUP(int*KEY,int*L,int*R,int*P,bool*C,int z)
{
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

void RB_INSERT(int*KEY,int*L,int*R,int*P,bool*C,int N)
{
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

void OUT_PUT(int*KEY,int*LEFT,int*RIGHT,int k)
{
    if(LEFT[k]!=NIL) OUT_PUT(KEY,LEFT,RIGHT,LEFT[k]);
    printf("%d  ",KEY[k]);
    if(RIGHT[k]!=NIL) OUT_PUT(KEY,LEFT,RIGHT,RIGHT[k]);
}

int main()
{
	int key,N=0;
	queue<int>import;
	while(scanf("%d",&key)!=EOF)
	{
		N++;
		import.push(key);
	}
	int *KEY=(int*)malloc(sizeof(int)*(N+2));fill(KEY,KEY+(N+2),NIL);
	for(int i=1;i<=N;i++)
	{
		KEY[i]=import.front();
		import.pop();
	}

	int *LEFT=(int*)malloc(sizeof(int)*(N+2));
	fill(LEFT,LEFT+(N+2),NIL);
	int *RIGHT=(int*)malloc(sizeof(int)*(N+2));
	fill(RIGHT,RIGHT+(N+2),NIL);
	int *PARENT=(int*)malloc(sizeof(int)*(N+2));
	fill(PARENT,PARENT+(N+2),NIL);
	bool*COLOR=(bool*)malloc(sizeof(bool)*(NIL+10));
	fill(COLOR,COLOR+(NIL+10),BLACK);
	RB_INSERT(KEY,LEFT,RIGHT,PARENT,COLOR,N);
	OUT_PUT(KEY,LEFT,RIGHT,Troot);
	return 0;
}*/



/*#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;


typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


//void InitList(LinkList& L){
//	L=(LinkList)malloc(sizeof(LNode));
//}

void creat(LinkList &L,int n){
	int i;
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i){
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		L->next=p;p->next=L->next;
	}
	
}

void merge(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa;
	LinkList pb;
	LinkList pc;
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

void print(LinkList &L){//打印链表的函数
    LinkList p=L->next;//跳过头结点到 首结点
    while (p!=NULL)//结点不为空，继续
    {
        printf("%d ",p->data);
        p=p->next;
    }
	printf("\n");
}

main(){
	LinkList La;
	printf("please input La:");
	creat(La,4);
	print(La);

	LinkList Lb;
	printf("please input Lb:");
	creat(Lb,4);
	print(Lb);

	LinkList Lc;
	merge(La,Lb,Lc);
	printf("\nLc:");
	print(Lc);
	return 0;
}*/
/*#include<iostream>

using namespace std;
void fun(char,float)
{
}
void main(void)
{
	fun(8,3.1);
	int x=3,y;
	y=x++-1;
	cout<<x<<','<<y<<endl;
	x=3;
	y=++x-1;
	cout<<x<<','<<y<<endl;
	x=3;
	y=x--+1;
	cout<<x<<','<<y<<endl;
}
*/
/*	
	int n;
	cin>>n;
	switch(n)
	{
	case 1:
	case 2:cout<<'1';
	case 3:
	case 4:cout<<'2';break;
	default:cout<<'3';
	}
	int i(0);
	while(i<10)
	{
		if(i<1)continue;
		if(i==5)break;
		i++;
		cout<<'*'<<endl;
	}
	int a(1),b(1);
	for(;a<=100;a++)
	{
		if(b>=10)break;
		if(b%3==1){b+=3;continue;}
	}
	cout<<a;
unsigned char c(135),d(43);
	d=d<<1;
	cout<<(int)d;
	return 0;
	signed int i=10,j=20,k=0;
//	for(;k<10;k++)
	++k=i;
	cout<<k;
	signed int a(15),b(21),x(100),y;
	switch(a%100)
	{
	case 0:x++;
	case 1:x++;
		switch(b%2)
		{
		case 0:x++;break;
		case 2:x--;break;
		default:x++;break;
		}
	default:break;
	}
	for(int i=2;i!=0;)cout<<i--;
	y=(x>0?1:x<0?-1:0);
//	cout<<y;
	int a(1),b(10);
	do
	{b-=a;a++;}while(b--<0);
	cout<<"a="<<a<<",b="<<b;
	int k=10,i;
//	while(k=3){k=k-1;cout<<'*'<<endl;}
	for (int x=1,y=0;x>y++;x=i++) {i=x;cout<<'*'<<endl;}*/