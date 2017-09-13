// PAT 1007 
// 一开始还以为int爆了，后来发现全为负数才输出头和尾
// 简单的迭代

#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	long long  n,start,end;
	int a[10009];
	cin >> n;
	bool flag = false;
	bool restart = true;
	long long  maxsum = 0;
	long long  ans_start,ans_end,sum;
	sum = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i] >= 0)
		{
			flag = true;
		}
		if(restart)
		{
			start = a[i];
			restart = false;
		}
		sum += a[i];
		end = a[i];
		if(sum < 0)
		{
			sum = 0;
			restart = true;
		}
		if(sum > maxsum)
		{
			ans_start = start;
			ans_end = end;
			maxsum = sum;
		}
		
	}
	if(!flag)
	{
		cout << "0 " << a[0] << " " <<a[n-1]<<endl;
	}
	else {
		cout << maxsum <<" " << ans_start <<" "<< ans_end << endl;
	}
	return 0;
}