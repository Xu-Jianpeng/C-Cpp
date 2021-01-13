/*#include<stdio.h>

int count(int n){
	if (n==0||n==1||n==2) return n;
	int i,a=1,b=2;
	int temp=0;
	for (i=3;i<n+1;i++){
		temp=a+b;
		a=b;
		b=temp;
	}
	return temp;
}

main(){
	int n;
	printf("please input the number of the stairs : ");
	scanf("%d",&n);
	printf("number of the solution : %d\n",count(n));

}*/

#include<stdio.h>

int count(int n){
	if (n==0||n==1||n==2) return n;
	else{
		return count(n-1)+count(n-2);
	}
}

void main(){
	int n;
	printf("please input the number of the stairs : ");
	scanf("%d",&n);
	printf("number of the solution : %d\n", count(n));
}