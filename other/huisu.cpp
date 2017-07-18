#include <iostream>
#include <stack>
#include <string>
using namespace std;

class cell
{
	
public:
	int x,y;
	cell(int i,int j){x = i;y = j;};
	cell() = default;
	bool operator == (const cell & );
	int showX() const;
	int showY() const;
};

bool cell::operator==(const cell & Y)
{
	if(showX() == Y.showX() && showY() == Y.showY())
	return true;
	else {
		return false;
	}
}


inline int cell::showX() const
{
	return x;
}

inline int cell::showY() const
{
	return y;
}


class Maze
{
private:
	const char exitMarker,entryMarker,visited,passage,wall;
	cell currentCell,exitCell,entryCell;
	stack<cell> mazeStack;
	char **store;
	
public:
	Maze();
	void exitMaze();
	int rows,cols;
	void pushUnvisited(int ,int );
};

Maze::Maze():exitMarker('c'),entryMarker('m'),passage('0'),wall('1'),visited(',')
{
	int row,cols;
	row = cols = 0;
	stack <char *> stk;
	char * middle ;
	char c[100];
	bool first_flag = true;
	while(cin >> c)
	{
		row++;
		cols = strlen(c);
		if(first_flag)
		{
			middle = new char[cols+3];
			for(int j = 0;j<cols+2;j++)
			{
				middle[j] = wall;
			}
			middle[cols+1] = wall;
			middle[cols+2] = '\0';
		    stk.push(middle);
			first_flag = false;
		}
		
		middle = new char [cols+3];
		middle[0] = wall;
		strcpy(&middle[1],c);
		middle[cols+1] = wall;
		middle[cols+2] = '\0';
		stk.push(middle);
		if(strchr(middle,exitMarker) != 0)
			{exitCell.y = strchr(middle,exitMarker) - middle;exitCell.x = row;
			cout<<"*********"<<exitCell.x<<exitCell.y<<endl;
			}
		if(strchr(middle,entryMarker) != 0)
		{entryCell.y = strchr(middle,entryMarker) - middle;entryCell.x = row;
		}
	}
	row++;
	middle = new char[cols+3];
	for(int j = 0;j<cols+2;j++)
		middle[j] = wall;
	middle[cols+1] = wall;
	middle[cols+2] = '\0';
	stk.push(middle);
	
	store = new char * [cols];
	cout<<stk.size()<<endl;
	for(int i=row;i >=0;i--)
	{
		store[i] = stk.top();
		stk.pop();
		//cout<<"i:"<<i<<" size:"<<stk.size()<<endl;
	}
	
	for(int i = 0;i <= row;i++)
	{
		cout<<store[i]<<endl;
	}
}

void Maze::exitMaze()
{
	int row;
	int cols;
	currentCell = entryCell;
	while(!(currentCell == exitCell))
	{
		cout<<"curren"<<currentCell.x<<". "<<currentCell.y<<endl;
		row = currentCell.x;
		cols = currentCell.y;
		if(!(currentCell == entryCell))
			store[row][cols] = visited;
		pushUnvisited(row, cols-1);
		pushUnvisited(row, cols+1);
		pushUnvisited(row+1,cols);
		pushUnvisited(row-1, cols);
		
		if(mazeStack.empty())
			cout<<"false"<<endl;
			
		else {
			currentCell = mazeStack.top();
			mazeStack.pop();
		}		
	}
	
	cout<<"Success"<<endl;
}

void Maze::pushUnvisited(int x,int y)
{
	cout<<x<<y<<endl;
	cout<<store[x][y]<<endl;
	if(store[x][y] != wall && store[x][y] != visited)
	{
		mazeStack.push(cell(x,y));
		cout<<"size:"<<mazeStack.size()<<endl;
		cout<<"mazeStack:"<<mazeStack.top().x<<mazeStack.top().y<<endl;
	}
}
int main(int argc, char *argv[]) {
	Maze().exitMaze(); 
}

/*
0000
c000
m000
0000
*/