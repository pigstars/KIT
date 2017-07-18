// X皇后问题
#define  X 8
#include <iostream>
#include <math.h>
using namespace std;
int solv[1000][100];
int solvCnt = 0;
int temp[100];

bool OK(int curx,int cury)
{
	int i;
	for( i = 0;i < curx;i++)
	{
		if(temp[i] == cury)
			return false;
	}
	
	for(i = 0;i < curx;i++)
	{
		if(fabs(i - curx) == fabs(temp[i] - cury) )
		return false;
	}
	//cout<<"curx"<<curx<<"cury"<<cury<<endl;
	return true;
}
void go(int rows,int cols)
{
	int i;
	if(rows == (X-1))
	{
		solvCnt++;
		for(i = 0;i < X;i++)
		{
			solv[solvCnt][i] = temp[i]+1;
			cout<<temp[i]+1<<" ";
		}
		cout<<endl;
		return ;
	}
	
	for(i = 0;i < X;i++)
	{
		if(OK(rows+1,i))
		{	
			temp[rows+1] = i;
			go(rows+1,i);
		}
	}
}

int main(int argc, char *argv[]) {
	int i;
	int n;
	for(i = 0;i < X;i++)
	{
		temp[0] = i;
		go(0,i);
	}
	cin>>n;
	for(i =0;i < X;i++)
	{
		cout<<solv[n][i];
	}
	cout<<endl;	
	return true;
}