// PAT 1003 求最短路径的条数，以及所有最短路径中的花费最大值


#include <iostream>
#define MAXSIZE 1000
#define INF 99999999

using namespace std;

struct Graph
{
	int n,e;
	int edges[MAXSIZE][MAXSIZE];
};
void solve(Graph * ,int start,int end,int * save);
int main(int argc, char *argv[]) {
	Graph G;
	int save[MAXSIZE];
	int start,end;
	cin>>G.n>>G.e>>start>>end;
	for(int i = 0;i < G.n;i++)
	{
		cin>>save[i];
		for(int j = 0;j < G.n;j++)
		{
			G.edges[i][j] = INF;
		}
	}
	for(int i = 0;i < G.e;i++)
	{
		int x;
		int y;
		cin >> x >> y;
		cin >> G.edges[x][y];
		G.edges[y][x] = G.edges[x][y];
		
	}
	solve(&G,start,end,save);
}

void solve(Graph * G,int start,int end ,int * save)
{
	int visited[MAXSIZE] = {0};
	int dict[MAXSIZE];
	int father[MAXSIZE] = {-1};
	int cnt[MAXSIZE] = {0};
	int cost[MAXSIZE] = {0};
	int sum = 0;

	for(int i = 0;i < G->n;i++)
	{
		dict[i] = G->edges[start][i];
		cost[i] = save[i];
		if(dict[i] < INF)
		{
			father[i] = start;
			cnt[i] = 1;
			cost[i] = save[i] + save[start];
		}
		else
		{
			father[i] = -1;
		}	
	}
	visited[start] = 1;
	cnt[start] = 1;
	cost[start] = save[start];
	for(int i = 0;i < G->n - 1;i++)
	{
		int min = INF;
		int loc = 0;
		for(int j = 0;j < G->n;j++)
		{
			if(visited[j] == 0 && dict[j] < min)
			{
				min = dict[j];
				loc = j;
			}
		}
		visited[loc] = 1;
		for(int j = 0;j < G->n;j++)
		{
			if(visited[j] == 0 && dict[j] == dict[loc] + G->edges[loc][j])
			{
				cnt[j] += cnt[loc];
				if(cost[loc] + save[j] > cost[j])
				{
					cost[j] = (cost[loc] + save[j]);
				}
				father[j] = loc;
			}
			if(visited[j] == 0 && dict[j] > dict[loc] + G->edges[loc][j])
			{
				cnt[j] = cnt[loc];
				dict[j] = dict[loc] + G->edges[loc][j];
				cost[j] = cost[loc] + save[j];
				father[j] = loc;
			}
			
		}
	}
	
	cout << cnt[end] <<" "<< cost[end];
	
}
/*
6 15 2 0
2 2 1 8 4 5
0 1 8
0 2 10
0 3 5
0 4 1
0 5 3
1 2 1
1 3 6/Users/pigstars/project/leveldb
1 4 3
1 5 8
2 3 6
2 4 8
2 5 8
3 4 4
3 5 1
4 5 9
*/