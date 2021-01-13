#include <stdio.h>
#include <stdlib.h>


typedef char ElemType;
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
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//中序遍历
void middleorder(Node *root) {
	if (root != NULL) {
		middleorder(root->left);
		printf("%c ", root->data);
		middleorder(root->right);
	}
}
//后序遍历
void postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

//计算结点数
void count(Node *root,int &sum) {
	if (root != NULL) {
		count(root->left,sum);
		count(root->right,sum);
		sum++;
	}
}

//将左右子树反过来
void chagTree(Node *root){
	Node *temp = (Node*)malloc(sizeof(Node));
	if(root != NULL){
		chagTree(root->left);
		chagTree(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}

//后序遍历查找数element
bool find(Node *root,int element){
	if(root != NULL){
		if(find(root->left,element)||find(root->right,element)||root->data==element+48){
			return true;
		}
		else 
			return false;
	}
	else 
		return false;
}

int main() {
	int sum=0;
	Node* root;
	crtTree(root);
	/*preorder(root);
	printf("\n");
	middleorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	chagTree(root);
	printf("将左右子树反过来：\n");
	preorder(root);
	printf("\n");
	middleorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("\n");
	count(root,sum);
	printf("结点数为：%d",sum);*/
	printf("please input the element you want to search:\n");
	int element;
	scanf("%d",&element);
	if(find(root,element))
		printf("true");
	else 
		printf("false");
	printf("\n");
	printf("\n");
}
/*
//设计程序，能够接受用户前序输入，构造对应二叉树，并对其进行前序和中序遍历。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node* left;
	struct Node* right; 
} Node;

//用户前序输入  创建二叉树

void crtTree(Node *&root){
	char c;
	scanf("%c",&c);
	if( c == ' '){
		root = NULL;
	} else{
		root = (Node* )malloc(sizeof(Node));
		root->data = c;
		crtTree (root->left);
		crtTree (root->right);
	}
	
} 


//前序遍历  递归算法 
void preorderTraverse(Node *root){
	if(root != NULL){
		printf("%c ", root->data);
		preorderTraverse(root->left);
		preorderTraverse(root->right); 
	}
} 

//中序遍历 递归算法
void inorderTraverse(Node* root){
	
	if(root != NULL){
		preorderTraverse(root->left);
		printf("%c ", root->data);
		preorderTraverse(root->right); 
	}
}

int main(){
	
	Node* root;
	crtTree(root);
	preorderTraverse(root);
	printf("\n");
	inorderTraverse(root);
	printf("\n");
	
	return 0;
	
}
*/