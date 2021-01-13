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
	cout<<n<<"年后乙的投资开始超过甲\n"<<"此时甲的利润为   "<<i<<"   ,   乙的利润为   "<<j<<endl;
}
