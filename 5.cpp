#include <iostream>
#include <stdlib.h>

using namespace std;

class Child{
	int num;//编号 
	bool gaming;// = true;//记录游戏状态，即是否在游戏中，默认为是 
	string name;//姓名 
public:
	void child(int n,string na){//初始化角色 
		if(n<=0){
			cout << "编号错误！" << endl; 
			exit(1);
		}
		num = n;
		name = na;
		cout << "child No:" << num << "\tname:" << name << "\tinitialized successfully!" << endl;
	}
	
	int getNo(){//返回角色编号 
		return num;
	}
	
	void disp(){//输出角色属性 
		cout << "child No:" << num << "\tname:" << name;
	}
	
	bool in(){//返回角色游戏状态 
		return gaming;
	}
	
	void out(){//修改角色游戏状态，出局 
		gaming = false;
		disp();
		cout << "\tout" << endl;
	}
};

class Play{
	int n;//共n个小孩 
	int s;//从第s个开始 
	int m;//第m个出局 
public:
	Play(int n,int s,int m){//初始化游戏 
		if(n>=s && s>0 && m>0){
			this->n = n;
			this->s = s;
			this->m = m;
		}else{
			cout << "不符合游戏规则！" << endl;
			exit(1);
		}
		start();
	}
	
	void start(){//开始游戏并返回胜利者编号 
		Child c[n];
		string name;
		int i,j=0,k;
		cout << n << " children in all." << endl;
		for(int i=0;i<n;i++){
			cout << "please input name:";
			cin >> name;
			c[i].child(i+1,name);
		}
		cout << endl;
		for(i=0;i<n-1;i++){//n=6,s=3,m=2
			for(k=0;k<m;){
				if(s+j-1==n) j=1-s;
				if(c[s+j-1].in()) j++,k++;
				else j++;
			}
			c[s+j-1].out();
		}
		int winner = s+j-1;
		cout << endl << "winner:" << endl;
		c[s+j-1].disp();
	}
};

int main(){
	
	bool gaming = true;
	Play play(6,3,2);
	return 0;
}
