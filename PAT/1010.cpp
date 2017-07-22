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
long long  calc(char *x,long long  rradix)
{
	long long sumB = 0;
	for(int i = 0;i < strlen(x);i++)
	{
		if(x[i] >= '0' && x[i] <= '9')
		{
			if(x[i] - '0' >= rradix)
				break;
			sumB = sumB * rradix + x[i] - '0';
		}
		else if(x[i] >= 'a' && x[i] <= 'z')
		{
			if(x[i] - 'a' + 10 >= rradix)
				break;
			sumB = sumB * rradix + (x[i] - 'a' + 10);
		}
		
		if(sumB < 0)
		return -1;
	}
	return sumB;

}
int main(int argc, char *argv[]) {
	char a[1000],b[1000];
	int tag;
	long long radix;
	long long sumA;
	bool flag = false;
	sumA = 0;
	cin >> a >> b >> tag >> radix;
	
	if(tag == 2)
	{
		swap(a,b);
	}
	if(strcmp(a,b) == 0)
	{
		cout << radix <<endl;
		return 0;
	}
	sumA = calc(a,radix);
	//cout << sumA << endl;
	long long left,right,ans;
	left = 0;
	for(int i = 0;i < strlen(b);i++)
	{
		if(getC(b[i]) > left)
		left = getC(b[i])+ 1;
	}
//	cout << "left" << left<<endl; 
	right = sumA + 1;
	
	while(right >= left)
	{
		long long mid = left + (right - left) / 2;
		if(calc(b, mid) > sumA || calc(b,mid) == -1)
		{
			right = mid - 1; 
		}
		else if(calc(b,mid) == sumA)
		{
			flag = true;
			ans = mid;
			right = mid - 1;
		}
		else if (calc(b,mid) < sumA)
		{
			left = mid + 1;
		}
	}
	if(flag)
	{
		cout<<ans<<endl;
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}


