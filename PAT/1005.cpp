#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
int main(int argc, char *argv[]) {
	char c[2000];
	cin >> c;
	int len = strlen(c);
	int sum = 0;
	for(int i = 0;i < len;i++)
	{
		sum += c[i] - '0';
	}
	stack<string> s;
	if(sum == 0)
	{
		cout << "zero" << endl;
		return 0;
	}
	while (sum > 0)
	{
		int c = sum % 10;
		sum = sum / 10;
		switch (c) {
			case 0:
				s.push("zero");
				break;
			case 1:
				s.push("one");
				break;
			case 2:
				s.push("two");
				break;
			case 3:
				s.push("three");
				break;
			case 4:
				s.push("four");
				break;
			case 5:
				s.push("five");
				break;
			case 6:
				s.push("six");
				break;
			case 7:
				s.push("seven");
				break;
			case 8:
				s.push("eight");
				break;
			case 9:
				s.push("nine");
				break;
			default:
				break;	
		}
	}
	int size = s.size();
	for(int i = 0;i < size - 1;i++)
	{
		string temp = s.top();
		cout <<temp<<" ";
		s.pop();
	}
	string temp = s.top();
	cout <<temp<<endl;
	return 0;
}