
// 模版类实现的双向列表
#include <iostream>
using namespace std;

template <typename T>
class linklist
{


public:
	linklist<T>* next ;
	linklist<T> * last ;
	T member;
	linklist();
	bool setmember(T);
	~linklist();
};

template <typename T>
linklist<T>::linklist()
{
	next = nullptr;
	last = nullptr;
}
template <typename T>
bool linklist<T>::setmember(T a)
{
	member = a;
	return true;
}
template <typename T>
bool search(linklist<T>  * head, linklist<T>  *tail, T num)
{
	if(head == nullptr || tail == nullptr)
	{
		return false;
	}
	else 
	{
		while(head != nullptr || tail != nullptr)
		{
			if (head->member == num)
			{
				return true;
			}
			else if (tail->member == num)
			{
				return true;
			}
			head = head->next;
			tail = tail->last;
		}
		return false;
	}
}

template <typename T>
bool add()
{
	
}

int main(int argc, char const *argv[])
{
	
	linklist<long> * head;
	linklist<long> * tail;
	cout<<"hhh"<<endl;
	for(int i = 0;i < 10;i++)
	{
		cout<<"输入一个数保存到双向链表:";
		linklist<long> * temp = new linklist<long>();
		if (i == 0)
		{
			head = temp;
			tail = temp;
			long tt = 0;
			cin>>tt;
			temp->setmember(tt);
		}
		else
		{
			tail->next = temp;
			temp->last = tail;
			tail= tail->next;
			long tt = 0;
			cin>>tt;
			temp->setmember(tt);
		}
		cout<<endl;

	}
	
	
	if(search(head,tail,long(5)))
	{
		cout<<"uyes"<<endl;
	}
	else {
		cout<<"false"<<endl;
	}
	

	return 0;
}