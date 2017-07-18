// PAT 1001
// 求两数之后，按欧式格式输出
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	long long a,b,c;
	bool flag =false;
	cin>>a>>b;
	c = a + b;
	char ans[1000];
	int cnt = 0;
	int in = 0;
	if(c < 0)
	{
			flag = true;
			c = -c;
	}
	if(c == 0)
	{
		cout<<0<<endl;
		return 0;
	}
	while( c != 0 )
	{
		ans[cnt++] = c % 10 +'0';
		c = c/10;
		in++;
		if(in == 3)
		{
		ans[cnt++] = ',';
		in = 0;
		}
	}
	bool first = true;
	if(flag == true)
	cout<<'-';
	for(int i = cnt-1;i >= 0;i--)
	{
		if(first && ans[cnt-1] == ',')
		{
			first = false;
			continue;
		}
		cout<<ans[i];
	}
	cout<<endl;
	
}