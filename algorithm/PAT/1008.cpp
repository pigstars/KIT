#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n,cnt;
	int temp,now;
	cin >> n;
	now = 0;
	cnt = 0;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		if(now < temp)
		{
			cnt += (temp - now) * 6 + 5;
			now = temp;
		}
		else if (now == temp)
		{
			cnt += 5;
			now = temp;
		}
		else if(now > temp)
		{
			cnt += (now - temp) * 4 + 5;
			now = temp;
		}
	}
	cout << cnt << endl;
	return 0;
}