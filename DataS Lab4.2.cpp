/*
#include<iostream>
using namespace std;
static int gEightQueen[8] = { 0 }, gCount = 0;
void print()//输出每一种情况下棋盘中皇后的摆放情况
{
    for (int i = 0; i < 8; i++)
    {   
        int inner;
        for (inner = 0; inner < gEightQueen[i]; inner++)
            cout << "□";
            cout <<"■";
        for (inner = gEightQueen[i] + 1; inner < 8; inner++)
            cout << "□";
        cout << endl;
    }
    cout << "==========================\n";
}
int check_pos_valid(int loop, int value)//检查是否存在有多个皇后在同一行/列/对角线的情况
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = gEightQueen[index];
        if (value == data)
            return 0;
        if ((index + data) == (loop + value))
            return 0;
        if ((index - data) == (loop - value))
            return 0;
    }
    return 1;
}
void eight_queen(int index)
{
    int loop;
    for (loop = 0; loop < 8; loop++)
    {
        if (check_pos_valid(index, loop))
        {
            gEightQueen[index] = loop;
            if (7 == index)
            {
				cout<<gCount;
                gCount++, print();
                gEightQueen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            gEightQueen[index] = 0;
        }
    }
}
int main(int argc, char*argv[])
{
    eight_queen(0);
    cout << "total=" << gCount << endl;
    return 0;
}
*/




///*
#include<stdio.h>
#include<math.h>
#define N 5

int res=0;
int top=-1;
int q[N];

void push(int n){
	top++;
	q[top]=n;
}

void pop(){
	top--;
}

void FindQy(int x){
	bool check();
	void Output();
	for(int y=0;y<N;y++){
		push(y);
		if(check()){
			if(x<N-1){
				FindQy(x+1);
			} else{
				res++;
				Output();
			}
		}
		pop();
	}
}

bool check(){
	for(int x=0;x<top;x++)
		if((q[top]==q[x])||(abs(q[top]-q[x]))==(top-x))
			return false;
		return true;
}

void Output(){
	/*
	printf("No.%d: ",res);
	for(int x=0;x<N;x++){
		printf("(%d,%d)  ",x+1, q[x]+1);
	}
	printf("\n");
	*/
	///*
	printf("No.%d: \n",res);
	for(int x=0;x<N;x++){
		for(int inner=0;inner<q[x];inner++) 
			printf("□");
		printf("■");
		inner++;
		for(;inner<N;inner++) 
			printf("□");
		printf("\n");
	}
	//*/
}

main(){
	printf("begin\n");
	FindQy(0);
	printf("the number of solutions is: %d \n",res);
}
//*/