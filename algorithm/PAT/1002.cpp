// 求两数之后，两数有不同的指数和系数

#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	double hash[2000] = {0};
	int zhishu,cnt=0;
	double xishu;
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>zhishu>>xishu;
		hash[zhishu] += xishu;
	}
	
	cin>>n;
	for(int i = 0;i < n;i++)
	{
	cin>>zhishu>>xishu;
	hash[zhishu] += xishu;
	}
	
	for(int i = 0;i<1001;i++)
	{
		if(hash[i] != 0)
			cnt++;	
	}
	printf("%d",cnt);
	for(int i = 1001;i >= 0&&cnt > 0;i--)
	{
		if(hash[i] != 0)
		{
			printf(" %d %.1lf",i,hash[i]);
			cnt--;
		}
	}
	return 0;
		
	
}