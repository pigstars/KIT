#include <iostream>
using namespace std;
struct bet
{
	double 	value;
	int i,j;
};

const int MAXSIZE = 3;
int main()
{
	double num[MAXSIZE][MAXSIZE];
	bet max;
	bet b[3];
	for (int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			cin >> num[i][j];
			if(num[i][j] > max.value)
			{
				max.value = num[i][j];
				max.i = i;
				max.j = j;
			}
			
		}
		b[i] = max;
		max.value = 0;
	}
	double sum = (b[0].value * b[1].value * b[2].value * 0.65 - 1)*2;
	for(int i = 0;i < 3;i++)
	{
		if(b[i].j == 0)
			cout << 'W' << " ";
		else if (b[i].j == 1)
				cout << "T" << " ";
		else if(b[i].j == 2)
				cout << 'L' << " ";
	}
	printf("%.2lf",sum);
}