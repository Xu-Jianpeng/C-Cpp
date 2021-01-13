#include <iostream>
#include <stdlib.h>

using namespace std;

class Child{
	int num;//��� 
	bool gaming;// = true;//��¼��Ϸ״̬�����Ƿ�����Ϸ�У�Ĭ��Ϊ�� 
	string name;//���� 
public:
	void child(int n,string na){//��ʼ����ɫ 
		if(n<=0){
			cout << "��Ŵ���" << endl; 
			exit(1);
		}
		num = n;
		name = na;
		cout << "child No:" << num << "\tname:" << name << "\tinitialized successfully!" << endl;
	}
	
	int getNo(){//���ؽ�ɫ��� 
		return num;
	}
	
	void disp(){//�����ɫ���� 
		cout << "child No:" << num << "\tname:" << name;
	}
	
	bool in(){//���ؽ�ɫ��Ϸ״̬ 
		return gaming;
	}
	
	void out(){//�޸Ľ�ɫ��Ϸ״̬������ 
		gaming = false;
		disp();
		cout << "\tout" << endl;
	}
};

class Play{
	int n;//��n��С�� 
	int s;//�ӵ�s����ʼ 
	int m;//��m������ 
public:
	Play(int n,int s,int m){//��ʼ����Ϸ 
		if(n>=s && s>0 && m>0){
			this->n = n;
			this->s = s;
			this->m = m;
		}else{
			cout << "��������Ϸ����" << endl;
			exit(1);
		}
		start();
	}
	
	void start(){//��ʼ��Ϸ������ʤ���߱�� 
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
