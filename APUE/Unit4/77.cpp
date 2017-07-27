#include <apue.h>

using namespace std;
int main(int argc, char *argv[]) {
	int i;
	struct stat buf;
	char * ptr;
	for(i = 1;i < argc;i++)
	{
		printf("%s: \n",argv[i]);
		if(lstat(argv[i], &buf) < 0)
		{
			err_sys("lstat error");
			continue;
		}
		if(S_ISREG(buf.st_mode))
		{
			ptr = "regular";
		}
		else if(S_ISDIR(buf.st_mode))
		{
			ptr = "directory";
		}
		else if(S_ISCHR(buf.st_mode))
		{
			ptr = "character special";
		}
		else if(S_ISBLK(buf.st_mode))
		{
			ptr = "BLK";
		}
		else 
		{
			ptr = "default";
		}
		printf("%s\n",ptr);		
		
	}
	return 0;
}