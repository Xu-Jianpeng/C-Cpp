#include <iostream>
#include <string>

using namespace std;

class Database{
public:
    string author,name;
    int year;
    Database(string a,string n,int y)/*:author(a),name(n),year(y)*/{
        author = a;
        name = n;
        year = y;
    }
    virtual void disp();
};

class Painting:public Database{
public:
    int heigth,width;
    Painting(string a,string n,int y,int h,int w):Database(a,n,y),heigth(h),width(w){}
    void disp (){
        cout << endl;
        cout << "This is a Painting." << endl;
        cout << "author:" << author << "\tname:" << name << "\tyear:" << year << endl;
        cout << "heigth:" << heigth << "\twidth:" << width << endl;
    }
};

class Music:public Database{
public:
    string tune;
    Music(string a,string n,int y,string t):Database(a,n,y),tune(t){}
    void disp (){
        cout << endl;
        cout << "This is a Music." << endl;
        cout << "author:" << author << "\tname:" << name << "\tyear:" << year << endl;
        cout << "tune:" << tune << endl;
    }
};

class Chamber:public Music{
public:
    int ChamberNo;
    Chamber(string a,string n,int y,string t,int chn):Music(a,n,y,t),ChamberNo(chn){}
    void disp (){
        Music::disp();
        cout << "number of Chameber:" << ChamberNo << endl;
    }
};

int main()
{
    Database* p=NULL;
    Database database("Alan","fresher",2007);
    *p = database;
    p->disp();
    Painting painting("张择端","清明上河图",1000,200,1600);
    *p = painting;
    p->disp();
    Music music("李荣浩","年少有为",2017,"pop");
    *p = music;
    p->disp();
    Chamber chamber("unkown author","let it go",2010,"classical",5);
    *p = chamber;
    p->disp();
    return 0;
}