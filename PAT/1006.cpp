// PAT 1006 
// 免去排序，直接记录最小值，代码写的很普通
#include <iostream>
#include <string>
using namespace std;
class Time
{
public:
	int hh;
	int mm;
	int ss;
};
class Record
{
public:
	string s;
	Time start;
	Time end;
};

bool cmp_start(Record a , Record b)
{
	if(a.start.hh > b.start.hh)
		return true;
	else 
		return false;
	
	if(a.start.mm > b.start.mm)
		return true;
	else 
		return false;
	
	if(a.start.ss > b.start.ss)
		return true;
	else 
		return false;
	
}
bool cmp_end(Record a , Record b)
{
	if(a.end.hh > b.end.hh)
		return true;
	else 
		return false;
	
	if(a.end.mm > b.end.mm)
		return true;
	else 
		return false;
	
	if(a.end.ss > b.end.ss)
		return true;
	else 
		return false;
	
}
int main(int argc, char *argv[]) {
	int n;
	Record rec[1000];
	Record start,end;
	cin >> n;
	
	cin >> rec[0].s;
	cin >> rec[0].start.hh;
	getchar();
	cin >> rec[0].start.mm;
	getchar();
	cin >> rec[0].start.ss;
	getchar();
	
	cin >> rec[0].end.hh;
	getchar();
	cin >> rec[0].end.mm;
	getchar();
	cin >> rec[0].end.ss;
	getchar();
	
	start = rec[0];
	end = rec[0];
	for(int i = 1;i < n;i++)
	{
		cin >> rec[i].s;
		cin >> rec[i].start.hh;
		getchar();
		cin >> rec[i].start.mm;
		getchar();
		cin >> rec[i].start.ss;
		getchar();
		
		cin >> rec[i].end.hh;
		getchar();
		cin >> rec[i].end.mm;
		getchar();
		cin >> rec[i].end.ss;
		getchar();
		
		if(cmp_start(start,rec[i]))
			start = rec[i];
		if(!cmp_end(end,rec[i]))
			end = rec[i];
	}
	cout << start.s << " " << end.s << endl;
	return 0;
	
}