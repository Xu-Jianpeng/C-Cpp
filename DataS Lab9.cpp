#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

main(){
	int i,t;
	//合并两个string字符串
	string s1="hello";
	string s2="world";
	string s3=s1+" "+s2;
	cout<<"s1+s2="<<s3<<endl<<endl;

	//创建一个vector，将一组数字存入，再添加一些数字，输出
	vector<int> v1;
	for(i=0;i<5;i++)
		v1.push_back(i);
	cout<<"vector v1(old): ";
	for(i=0;i<v1.size();i++)
		cout<<v1[i]<<"  ";
	cout<<endl;
	cout<<"please input some numbers to v1:";
	for(i=0;i<2;i++){
		scanf("%d",&t);
		v1.push_back(t);
	}
	cout<<"vector v1(new): ";
	for(i=0;i<v1.size();i++)
		cout<<v1[i]<<"  ";
	cout<<endl<<endl;
	
	//创建一个vector，将一组字符串存入并输出
	vector<string> v2;
	string vs[]={"hi","my","name","is","xjp"};
	for(i=0;i<sizeof(vs)/sizeof(vs[0]);i++)
		v2.push_back(vs[i]);
	cout<<"vector v2: ";
	for(i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
	cout<<endl<<endl;
	
	//创建一个list，将一组数字存入并输出
	list<int> l1;
	int la[]={1,2,3,4,5};
	for(i=0;i<sizeof(la)/sizeof(la[0]);i++)
		l1.push_back(la[i]);
	cout<<"list l1: ";
	for(list<int>::iterator itli = l1.begin();itli!=l1.end(); ++itli)
		cout << *itli <<" ";
	cout<<endl<<endl;
	
	//创建一个set，添加一些重复记录，输出
	set<string> se1;
	string ss;
	string ses[]={"hi","my","name","is","xjp"};//,"my","english","name","is","ken"};
	for(i=0;i<sizeof(ses)/sizeof(ses[0]);i++)
		se1.insert(ses[i]);
	cout<<"set se1: ";
	for(set<string>::iterator itse = se1.begin();itse!=se1.end(); ++itse)
		cout << *itse <<" ";
	for(i=0;i<2;i++){
		scanf("%s",&ss);
		se1.insert(ss);
	}
	for(itse = se1.begin();itse!=se1.end(); ++itse)
		cout << *itse <<" ";
	cout<<endl<<endl;
	
	//创建一个map，存入一些记录并输出
	map<string,int> m1;
	m1["Kobe"]=24;
	m1["LeBron"]=23;
	m1["Dwyane"]=3;
	m1["Jordan"]=23;
	m1["Yao"]=11;
	cout<<"map m1:"<<endl;
	for(map<string,int>::iterator itmp=m1.begin();itmp!=m1.end();itmp++)
		cout<<itmp->first<<"\t"<<itmp->second<<endl;
	cout<<endl;
}
