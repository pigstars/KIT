#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	double a[2005] = {0};
	double ans[2005] = {0};
	double b[2005] = {0};
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		cin >> a[x];
	}
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		cin >> b[x];
	}
	
	for(int i = 0;i <= 1000;i++)
	{
		if(a[i] != 0)
		{
			for(int j = 0;j <= 1000;j++)
			{
				if(b[j] != 0)
				{
				//	cout<<"i:"<<i<<"j:"<<j<<"ans:"<<a[i]*b[j]<<endl;
					ans[i+j] += (a[i] * b[j]);
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i <= 2000;i++)
	{
		if(ans[i] != 0)
			cnt++;
	}
	cout<<cnt;
	for(int i = 2000;i >= 0;i--)
	{
		if(ans[i] != 0)
		printf(" %d %.1lf",i,ans[i]);
	}
	cout<<endl;
	return 0;
	
}