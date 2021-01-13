#include <stdio.h>
#include <stdlib.h>


typedef char ElemType;
typedef struct Node {
	ElemType data;
	struct Node* left;
	struct Node* right;
} Node;

//����һ���洢�ַ�c �Ľ�㣬��������������Ϊ��ֵ
Node* crtNode(char c) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = c;
	n->left = NULL;
	n->right = NULL;
	return n;
}
//ǰ�����빹��������
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
//ǰ�����
void preorder(Node *root) {
	if (root != NULL) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//�������
void middleorder(Node *root) {
	if (root != NULL) {
		middleorder(root->left);
		printf("%c ", root->data);
		middleorder(root->right);
	}
}
//�������
void postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

//��������
void count(Node *root,int &sum) {
	if (root != NULL) {
		count(root->left,sum);
		count(root->right,sum);
		sum++;
	}
}

//����������������
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

//�������������element
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
	printf("������������������\n");
	preorder(root);
	printf("\n");
	middleorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("\n");
	count(root,sum);
	printf("�����Ϊ��%d",sum);*/
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
//��Ƴ����ܹ������û�ǰ�����룬�����Ӧ�����������������ǰ������������
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

//�û�ǰ������  ����������

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


//ǰ�����  �ݹ��㷨 
void preorderTraverse(Node *root){
	if(root != NULL){
		printf("%c ", root->data);
		preorderTraverse(root->left);
		preorderTraverse(root->right); 
	}
} 

//������� �ݹ��㷨
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