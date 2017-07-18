#include <iostream>
#include <stdio.h>
using namespace std;
long long max(long long a,long long b)
{
	return a < b?a : b;
}
long long getZ(long long a,long long b)
{
	if(b > a) return getZ(b,a);
	while (b != 0)
	{
		long long k = a % b;
		a = b;
		b = k;
	}
	return a;
}
int main(int argc, char *argv[]) {
	int n ;
	long long a[200][2];
	long long fz,fm ;
	scanf("%d",&n);
	if(n == 0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i = 0;i < n;i++)
	{
		scanf("%lld",&a[i][0]);
		getchar();
		scanf("%lld",&a[i][1]);
		
		if(i == 0)
			fm = a[i][1];
		else {
			fm = fm / getZ(fm,a[i][1]) * a[i][1];
		}
	}
	fz = 0;
	for(int i = 0;i < n;i++)
	{
		fz += a[i][0] * (fm / a[i][1]); 
	}
	long long Interger ,littleNum;
	bool flag = true;
	if (fz < 0)
	{
		flag = false;
		fz = -1 * fz;
	}
	if(fz == 0)
	{
		cout<< 0;
	}	
	else {
		if(fz / fm == 0)
		{
			if(!flag)
			cout<<"-";
			cout<<fz/(getZ(fz,fm))<<"/"<<fm/(getZ(fz,fm))<<endl;
			return 0;
		}
		if(!flag)
		cout<<"-";
		cout<<fz/fm;
		fz = fz - (fz/fm) * fm;
		if(fz == 0)
			return 0;
		cout<<" "<<fz/(getZ(fz,fm))<<"/"<<fm/(getZ(fz,fm))<<endl;
		}
	return 0;
}