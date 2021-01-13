//求三个数的平均值，演示C++的简单I/O

#include<iostream>
using namespace std;
int main()
{
	float num1,num2,num3;
	cout<<"Please input three numbers:"<<endl;
	cin>>num1>>num2>>num3;
	cout<<endl<<"The average of"<<num1<<","<<num2<<"and"<<num3;
	cout<<" is "<<(num1+num2+num3)/3<<endl;
	return 0;
 } 
