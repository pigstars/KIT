#include <iostream>

using namespace std;
int cnt[1000] = {0};
int maxlevel = 0;
int level = 0;
class Tree
{
public:
	int adj[200];
	int num;	
};
void DFS(Tree * t,int v,int level)
{
	++level;
	if(t[v].num == 0)
	{
		cnt[level]++;
		if(level > maxlevel)
		{
			maxlevel = level;
		}
	}
	
	for(int i = 0;i < t[v].num;i++)
	{	
		DFS(t,t[v].adj[i],level);
	}
	
}
int main(int argc, char *argv[]) {
	int N,M;
	Tree t[1000];
	cin >> N >> M;
	for(int i = 0;i < 300;i++)
	{
		t[i].num = 0;
	}
	for(int i = 0;i < M;i++)
	{
		int x;
		int num;
		cin >> x >> num;
		t[x].num = num;
		for(int j = 0;j < num;j++)
		{
			cin >> t[x].adj[j];
			//cout << t[i].adj[j]<<endl;
		}
	}
	DFS(t,1,0);
	
	for(int i = 1;i < maxlevel;i++)
	{
		cout<<cnt[i]<<" ";
	}
	cout<< cnt[maxlevel]<<endl;
}