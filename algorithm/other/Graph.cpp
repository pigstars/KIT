#include <iostream>
#include <queue>
#define MAXSIZE 100
#define INF 99999
static int cnt = 0;
using namespace std;
// 邻接矩阵
typedef struct
{
	int no;
	char info;
}VertexType;

class MGraph
{
	
public:
	int n;
	int edges[MAXSIZE][MAXSIZE];
	VertexType node[MAXSIZE];
};

//邻接表
struct ArcNode
{
	int no;
	ArcNode *nextarc;
};

typedef struct 
{
	int no;
	ArcNode * firstarc;
}VNode;

class AGraph
{
public:
	VNode adjlist[MAXSIZE];
	int n,e;	// 节点个数和边的数量
	AGraph()
	{
		n = 0;
		e = 0;
	}
};


void BFS (AGraph *,int );
void test(AGraph * G,int v);
void Prim(MGraph * G);
void shortPath(MGraph * G,int v);
void visit(int n)
{
	
	cout<<n<<" "<<endl;
}
int main(int argc, char *argv[]) {
	/*
	AGraph G;
	int first,second;
	cout<<"输入节点数:";
	cin>>G.n;
	for(int i = 0;i < G.n;i++)
	{
		G.adjlist[i].no = i;
	}	
	cout<<"输入边的信息:";
	while (cin>>first>>second)
	{
		G.e++;
		ArcNode * temp = new ArcNode;
		temp->no = second;
		temp->nextarc = G.adjlist[first].firstarc;
		G.adjlist[first].firstarc = temp;
		
		temp = new ArcNode;
		temp->no = first;
		temp->nextarc = G.adjlist[second].firstarc;
		G.adjlist[second].firstarc = temp;
	}
	test(&G,0);
	*/
	
	MGraph G;
	int first,second,power;
	cout<<"请输入节点数：";
	cin >> G.n;
	for(int i = 0;i < G.n;i++)
	{
		G.node[i].no = i;
	}
	for(int i = 0;i < G.n;i++)
	{
			for(int j = 0;j < G.n;j++)
			{
				G.edges[i][j] = INF;
			}
	}
		
	while (cin>>first>>second>>power)
	{
		G.edges[first][second] = power;
		G.edges[second][first] = power;
	}
	
	shortPath(&G,0);
	
}


void shortPath(MGraph * G,int v)
{
	int visited[MAXSIZE] = {0}; 
	int dist[MAXSIZE],cnt[MAXSIZE]={0};
	int father[MAXSIZE];
	for(int i = 0;i < G->n;i++)
	{
		dist[i] = G->edges[v][i];
	    if(dist[i] < (INF))
		{
			father[i] = v;
		}
		else 
		{
			father[i] = -1;
		}
	}


	father[v] = -1;
	visited[v] = 1;
	for(int j = 0;j<G->n - 1;j++)
	{
		int min = INF;
		int loc = 0;
		for(int i = 0;i<G->n;i++)
		{
			if(visited[i] == 0 && dist[i] < min)
			{
			min = dist[i];
			loc = i;	
			}
		}
		visited[loc] = 1; 
		for(int i = 0;i < G->n;i++)
		{
			if(visited[i] == 0 && dist[i] ==  G->edges[loc][i]+dist[loc])
			{
				cnt[i] += cnt[loc]; 
			}
			if(visited[i] == 0 && dist[i] > G->edges[loc][i]+dist[loc])
			{
				dist[i] = G->edges[loc][i] + dist[loc];
				father[i] = loc;
			}
		}
	}
	
	for(int i = 0;i < G->n;i++)
	{
		cout<<" "<<i<<" "<<dist[i]<<endl;
		cout<<"father"<<i<<" "<<father[i]<<endl;
		cout<<"cnt:"<<i<<" "<<cnt[i]<<endl;
	}
	
	
		
}

/*
void Prim(MGraph * G)
{
	int sum = 0;
	int vset[MAXSIZE] = {0};
	int lowcost[MAXSIZE];
	vset[0] = 1;
	for(int i = 0;i < G->n;i++)
	{
		lowcost[i] = G->edges[0][i];
	}
	
	for(int i = 1;i < G->n;i++)
	{
		// 找寻其中最小的值
		int min = INF;
		int loc = 0;
		for(int j = 0;j < G->n;j++)
		{
			if(vset[j] == 0 && lowcost[j] < min)
			{
				loc = j;
				min = lowcost[j];
			}
		}
		vset[loc] = 1;
		sum += min;
		for(int j = 0;j< G->n;j++)
		{
			if(vset[j] == 0 && lowcost[j] > G->edges[loc][j])
			{
				lowcost[j] = G->edges[loc][j];
			}
		}
	}
	cout<<"sum:"<<sum;
	
}

void BFS(AGraph * G,int v,int * visited)
{
	queue<int> que;
	visit(v);
	visited[v] = 1;
	que.push(v);
	while(!que.empty())
	{
		ArcNode * p = G->adjlist[que.front()].firstarc;
		que.pop();
		while(p != nullptr)
		{
			if(visited[p->no] == 0)
			{
				visit(p->no);
				visited[p->no] = 1;;
				que.push(p->no);
			}
			p = p->nextarc;
	
		}	

	}
	
}

void DFS(AGraph * G,int v,int * visited)
{
	visit(v);
	visited[v] = 1;
	ArcNode * p = G->adjlist[v].firstarc;
	while (p != nullptr) 
	{
	if(visited[p -> no] == 0)
		DFS(G,p->no,visited);
	p = p -> nextarc;
	}	
		
}

void DFS2(AGraph *G ,int v,int * visited)
{
	visit(v);
	cnt++;
	visited[v] = 1;
	ArcNode * p = G->adjlist[v].firstarc;
	while (p != nullptr) 
	{
		if(visited[p -> no] == 0)
			DFS2(G,p->no,visited);
		p = p -> nextarc;
	}	
	
}
void test(AGraph * G,int v = 0)
{	
	int visited[MAXSIZE] = {0};
	for (int i = 0; i < G->n; i++)
	{
		if(visited[i] == 0)
			DFS2(G,i,visited);
	}
	cout<<"dfs所得的节点数:"<<cnt;
}


// Kru
struct Node 
{
	int a,b;
	int w;
}Node;
Node node[MAXSIZE]; // 在主函数内已经输出完毕
void Kruskal(AGraph * G,int &sum ,Road road[])
{
	// 初始化操作
	int visited[MAXSIZE] = {0};
	int v[MAXSIZE]; 
	sum = 0;
	int a,b;
	for(int i = 0;i < G->n;i++)
	{
		v[i] = i;
	}
	sort(node,G->e);
	int loc;
	for(int i = 0;i < G -> e;i++)
	{
		a = getRoot(node[i].a);
		b = getRoot(node[i].b);
		if(a != b)
		{
			v[a] = b;
			sum += node[i].w;	// 找到新的路径，为第i条边
		}
	}
}





void 




queue<int> que;
	que.push(v);
	visit(v);
	visited[v] = 1;
	int ans ;
	while(!que.empty())
	{
		 int v = que.front();
		 ans = que.back();
		 que.pop();
		 ArcNode * p = G->adjlist[v].firstarc;
		 while(p != nullptr)
		{
			if(visited[p->no] == 0)
			{
				visit(p->no);
				visited[p->no] = 1;
				que.push(p->no);
			}
			p = p->nextarc;
		}
	}
	cout<<"ans:";
	visit(ans);
	*/
