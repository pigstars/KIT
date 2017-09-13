#include <iostream>
#include <string.h>
using namespace std;
void swap(char *a, char *b)
{
	char temp[1000];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
long long getC(char c)
{
	if(c >= '0' && c <= '9')
		return c - '0';
	else if(c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
}
long long  calc(char *x,long long  radix)
{
	long long sum = 0;
	int len = strlen(x);
	for(int i = 0;i < len;i++)
	{
		sum *= radix;
		sum += getC(x[i]);
		if(sum < 0)
		{
			return -1;
		} 
	}
	return sum;

}
int main(int argc, char *argv[]) {
	char a[1000],b[1000];
	int tag;
	long long radix;
	long long sumA;

	cin >> a >> b >> tag >> radix;
	
	if(tag == 2)
	{
		swap(a,b);
	}
	sumA = calc(a,radix);
	long long left,right,ans;
	left = 2;
	for(int i = 0;i < strlen(b);i++)
	{
		if(getC(b[i]) > left)
		left = getC(b[i])+ 1;
	}
 	
		right = sumA + 1;
	
	bool flag = false;
	long long mid;
	while(right >= left)
	{
		mid = (right + left) / 2;
		
		if(calc(b, mid) > sumA || calc(b,mid) == -1)
		{
			right = mid - 1; 
		}
		else if(calc(b,mid) == sumA)
		{
			flag = true;
			break;
		}
		else if (calc(b,mid) < sumA)
		{
			left = mid + 1;
		}
	}
	if(flag)
	{
		cout<<mid<<endl;
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}

