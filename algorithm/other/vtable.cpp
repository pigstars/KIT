#include <iostream>
using namespace std;
class base
{
protected: 
	int n = 5;
public:
	virtual void  f1();
	void f2();
};
void base::f1()
{
	cout<<"I am base f1"<<endl;
}

void base::f2()
{
	cout<<"I am base f2"<<endl;
}


class derive : private  base
{

public:
	void f1();
	void f2();
	void f3();
		
};
void derive::f1()
{
	cout<<"I am derive f1"<<endl;
}
void derive::f2()
{
	cout<<"I am derive f2"<<endl;
}
void derive::f3()
{
	cout<<"I am derive f3"<<endl;
	cout << n;
}

int main(int argc, char *argv[]) {
	derive * p = new derive();
	p->f1();
	p->f2();
	p->f3();
	
}