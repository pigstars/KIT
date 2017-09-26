#include <iostream>

using namespace std;

class A
{
public:
	virtual void func1()
	{
		
	}
	virtual void func2()
	{
		
	}	
};

class B : public A
{
public:
	virtual void func3()
	{
		
	}
	virtual void func4()
	{
		
	}
private:
	//struct hhh
	//{
		//char c;
		float fl;
		//enum{a,b};
		enum{a,b,c,dd,e};
		char d;
		//int d;
		//int e;
	//};
	
	//struct hhh test;
};

int main(int argc, char *argv[]) {
	B testB;
	float fl;
	char ad;
	char *pad;
	enum{x,y}ww;
	std::cout << "test: " <<sizeof(ad)<< " " << sizeof(pad) << " " << sizeof(ww) <<" "<<sizeof(testB);
	return 0;
		
}