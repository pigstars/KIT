#include <iostream>
#include "binaryTree.hpp"

int main(int argc, char *argv[]) {
	BST<long> bst;
	BSTNode<long> n0(1);
	
	bst.setRoot(&n0);
	BSTNode<long> n1(2);
	BSTNode<long> n2(3);
	n0.left = &n1;
	n0.right = &n2;
	BSTNode<long> n3(4);
	BSTNode<long> n4(5);
	n1.left = &n3;
	n1.right = &n4;
	BSTNode<long> n5(6);
	n2.right = &n5;
	
	cout<<"广度优先搜索：";
	bst.breadSearch(bst.retRoot());
	bst.preorder(bst.retRoot());
	cout<<endl;
	bst.inorder(bst.retRoot());
	cout<<endl;
	bst.postorder(bst.retRoot());
	cout<<endl<<"中序遍历:";
	bst.iterativeInorder(bst.retRoot());
	cout<<endl<<"后续遍历方法1:";
	bst.iterativePostorder(bst.retRoot());
	cout<<endl<<"Morris中序遍历：";
	bst.MorrisInorder(bst.retRoot());
	cout<<endl<<"后续遍历方法2:";
	bst.iterativePostorder2(bst.retRoot());
	cout<<endl<<"中序遍历：";
	bst.iterativeInorder(bst.retRoot());
	cout<<endl<<"test:";
	bst.bfs2(bst.retRoot());
	//void BST<T>::bfs2(BSTNode<T> *root)
	
	
}