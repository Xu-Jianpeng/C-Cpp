#include<iostream>

using namespace std;

int main()
{
	double i,j,n=0;
	i=100,j=100;
	while(i>=j)
	{
		i+=10;
		j+=j*0.05;
		n++;
	}
	cout<<n<<"����ҵ�Ͷ�ʿ�ʼ������\n"<<"��ʱ�׵�����Ϊ   "<<i<<"   ,   �ҵ�����Ϊ   "<<j<<endl;
}
