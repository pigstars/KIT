#include <apue.h>
#include <string.h>
#include <fcntl.h>

#define BUFFSIZE 4096
int main(void)
{
	int n;
	int fd;
	char buf[BUFFSIZE] = {"hello world"};
	char buf2[BUFFSIZE] = {"can't"};
	// 先创建一个文件
	fd = creat("test.text",FILE_MODE);
	if(write(fd,buf,BUFFSIZE) > 0)
	{
		close(fd);
	}
	
	fd = open("test.text",O_RDWR | O_APPEND);
	if(fd < 0)
		err_sys("cant open");
	memset(buf, 0, sizeof(buf));
	int start = lseek(fd, 2, SEEK_SET);
	//buf = "can't";
	write(fd,buf2,BUFFSIZE);
	printf("%s",buf);
	
	return 0;
}