#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	static int hhh;
	int a[1000] = {0};
	cin >> s;
	int len = s.length();
	for(int i = 0;i < len;i++)
	{
		//cout << s[i] - 'a' << endl;
		a[s[i]-'a']++;
	}
	
	int cnt = 0;
	for(int i = 0;i < 26;i++)
	{
		//cout << a[i] << endl;
		if(a[i] % 2 == 1)
			cnt++;
	}
	cout << cnt << endl;
}