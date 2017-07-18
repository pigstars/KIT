#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
class BSTNode
{
public:
	BSTNode(const T & e,BSTNode * a = nullptr ,BSTNode * b =nullptr){
		member = e;
		left = a;
		right = b;
	}
	T member;
	BSTNode * left, *right;
			
};

template <class T>
class BST
{
public:
	BST(){root = nullptr;};
	//~BST();
	bool clear();
	bool isEmpty();
	void breadSearch(BSTNode<T> *);
	bool setRoot( BSTNode<T> * tt )
	{
		root = tt;
	};
	void inorder(BSTNode<T> * );
	void preorder(BSTNode<T> *);
	void postorder(BSTNode<T> *);
	void iterativeInorder(BSTNode<T> *);
	void iterativePreorder(BSTNode<T> *);
	void iterativePostorder(BSTNode<T> *);
	void iterativePostorder2(BSTNode<T> *);
	void MorrisInorder(BSTNode<T> *);
	void iterativeInorder_test(BSTNode<T> *);
	void iterativePostorder_test(BSTNode<T> *);
	void mirros_test(BSTNode<T> *);
	void bfs2(BSTNode<T> *root);
	BSTNode<T> *retRoot(){return root;}
	
protected:
	BSTNode<T> * root;		
};

template <class T>
bool BST<T>::clear()
{
	root = nullptr;
}

template <class T>
bool BST<T>::isEmpty()
{
return root == nullptr; 
}

template<class T>
void BST<T>::breadSearch(BSTNode<T> * root)
{
	 if(root == nullptr)
			return ;
		queue<BSTNode <T> *> que;
		BSTNode<T> * last,*nlast;
		last = nlast = root ;
		que.push(root);
		while(!que.empty())
		{
			BSTNode<T> * temp = que.front();
			que.pop();
			cout<<temp->member;
			if(temp -> left)
				que.push(temp -> left);
			if(temp -> right)
				que.push(temp -> right);
			nlast = que.back();
			if(temp == last)
			{
				last = nlast;
				cout<<endl;
			}
			else
			{
				cout<<" ";
			}
		}
}

// 中序遍历
template <class T>
void BST<T>::inorder(BSTNode<T> * p)
{
	if(p->left)
		inorder(p->left);
	std::cout<<p->member<<" ";
	if(p->right)
		inorder(p->right);
}

// 先序遍历
template <class T>
void BST<T>::preorder(BSTNode<T> *p)
{
	std::cout<<p->member<<" ";
	if(p->left)
		preorder(p->left);
	if(p->right)
		preorder(p->right);
}

template <class T>
void BST<T>::postorder(BSTNode<T> *p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		std::cout<<p->member<<" ";
	}
}

template <class T>
void BST<T>::iterativePreorder(BSTNode<T> * p)
{
	stack<BSTNode<T> *> stk;
	if(p)
		stk.push(p);
	else 
		return ;
	while(stk.size() > 0)
	{
		BSTNode<T> * temp = stk.top();
		stk.pop();
		cout<<temp->member<<" ";
		if(temp->right)
			stk.push(temp->right);
		if(temp->left)
			stk.push(temp->left);
		
	}
}

template <class T>
void BST<T>::iterativePostorder(BSTNode<T> *rt)
{
	stack<BSTNode<T> *> stk;
	BSTNode<T> * p,*hasChecked;
	p = hasChecked = rt;
	while (p)
	{
		for(;p->left != nullptr;p = p->left)
		{
			stk.push(p);
		}
		
		while(p->right == nullptr || p->right == hasChecked)
		{
			cout<<p->member <<" ";
			hasChecked = p;
			if (stk.empty())
			return ;
			p = stk.top();
			stk.pop();
		}
		stk.push(p);
		p = p->right;
	}
	
}

template <typename T>
void BST<T>::MorrisInorder(BSTNode<T> *rt)
{
	BSTNode<T> * tmp,*p;
	p = rt;
	while (p)
	{
		if(p->left == nullptr)
		{
			cout<<p->member<<" ";
			p = p ->right;
		}
		else
		{
			tmp = p->left;
			while(tmp->right != nullptr && tmp-> right != p)
			{
				tmp = tmp -> right;
			}
			if(tmp -> right == nullptr)
			{
				tmp -> right = p;
				p = p -> left;
			}
			else 
			{
				cout<<p->member<<" ";
				tmp -> right = nullptr;
				p = p -> right;
			}	
		}
	}
}

template <class T>
void BST<T>::iterativePostorder2(BSTNode<T> * root)
{
	stack<BSTNode<T> *> st1,st2;
	st1.push(root);
	while (st1.size() > 0)
	{
		BSTNode<T> * temp;
		temp = st1.top();
		st1.pop();
		st2.push(temp);
		if(temp -> left)
		{
			st1.push(temp->left);
		}
		if(temp -> right)
		{
			st1.push(temp->right);
		}

	}
	while(st2.size() >0)
	{
		BSTNode<T> * temp;
		temp = st2.top();
		cout<<temp->member<<" ";
		st2.pop();
	}
}

template <class T>
void BST<T>::iterativeInorder(BSTNode<T> * root)
{
	stack<BSTNode<T>*> stk;
	BSTNode<T> * p;
	p = root;
	while (stk.size()>0 || p != nullptr)
	{
		while(p != nullptr)
		{
			stk.push(p);
			p = p->left;
		}
		
		if(p == nullptr)
		{
			cout<<stk.top()->member<<" ";
			p = stk.top();
			stk.pop();
			p = p->right;
		}
	}
}

















template <class T>
void BST<T>::iterativeInorder_test(BSTNode<T> * root)
{
	BSTNode<T> * p;
	stack<BSTNode<T> *> stk;
	p = root;
	while (stk.size() || p != nullptr)
	{
		while (p != nullptr)
		{
			stk.push(p);
			p = p->left;
		}
		if(p == nullptr)
		{		
			p = stk.top();
			cout<<p->member<<" ";
			stk.pop();
			p = p->right;
		}
	}
}



template <class T>
void BST<T>::mirros_test(BSTNode<T> * root)
{
	BSTNode<T> * p,*tmp;
	p = tmp = root;
	while(p)
	{
		if(p -> left == nullptr)
		{
			cout<<p->member<<" ";
			p = p->right;
		}
		else
		{
			tmp = p -> left;
			while (tmp -> right != nullptr && tmp -> right != p )
			{
				tmp = tmp -> right;
			}
			
			if(tmp -> right == nullptr)
			{
				tmp -> right = p;
				p = p ->left;
			}
			else if(tmp -> right == p)
			{
				tmp -> right = nullptr;
				cout <<p->member<<" ";
				p = p->right;
			}
		}
	}
}

template <class T>
void BST<T>::bfs2(BSTNode <T> * root)
{
	BSTNode <T> * p,*temp;
	p = temp = root;
	while(p)
	{
		if(p -> left == nullptr)
		{
			cout<<p->member<<" ";
			p = p -> right;
		}
		else
		{
			temp = p -> left;
			while (temp -> right != nullptr && temp -> right != p )
			{
				temp = temp -> right;
			}
			if(temp -> right == nullptr)
			{
				temp -> right = p;
				p = p -> left;
			}
			else if(temp -> right == p)
			{
				cout<< p->member<<" ";
				temp -> right = nullptr;
				p = p -> right;
			}
		}
	}
}


temlate <class T>
void BST<<T>::bfr(BSTNode <T> * root)
{
	BSTNode <T> * p;
	queue<BSTNode <T> * > que;
	p == root;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		visit(p);
		if(p->left)
		{
			que.push(p->left);
		}
		if(p->right)
		{
			que.push(p->right);
		}
	}
}

