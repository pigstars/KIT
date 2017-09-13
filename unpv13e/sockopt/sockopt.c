#include	"unp.h"
#include	<netinet/tcp.h>		/* for TCP_MAXSEG value */

int
main(int argc, char **argv)
{
	int			sockfd, mss, sendbuff,rcvbuf,sndbuf,n;
	socklen_t	optlen;
	struct sockaddr_in sockaddr;
	char recvline[MAXLINE];

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

		/* Fetch and print the TCP maximum segment size.  */
	optlen = sizeof(mss);
	Getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &mss, &optlen);
	printf("TCP mss = %d\n", mss);
	Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&rcvbuf,&optlen);
	printf("SO_RCVBUF = %d\n",rcvbuf);
	Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&sndbuf,&optlen);
	printf("SO_SENDBUF = %d\n",sndbuf);
	

		/* Set the send buffer size, then fetch it and print its value.  */
	sendbuff = 65536;
	Setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuff, sizeof(sendbuff));

	optlen = sizeof(sendbuff);
	Getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuff, &optlen);
	printf("send buffer size = %d\n", sendbuff);
	
	bzero(&sockaddr, sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(argv[1]);
	inet_pton(AF_INET,argv[1],&sockaddr.sin_addr);
	sockaddr.sin_port = htons(9999);
	if( (n = connect(sockfd,(SA *)(&sockaddr),sizeof(sockaddr)) ) < 0)
		err_sys("connect error");
		
	while((n = read(sockfd,recvline,MAXLINE)) > 0)
	{
		recvline[n] = 0;
		printf("hhh");
		if(fputs(recvline,stdout) == EOF)
			err_sys("fputs error");
	}

	exit(0);
}
