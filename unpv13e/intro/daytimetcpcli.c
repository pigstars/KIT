#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr,cliaddr;
	socklen_t			len;

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);
		
		int rcvbuf,sndbuf,optlen;
	    optlen = sizeof(rcvbuf);
		Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&rcvbuf,&optlen);
		printf("SO_RCVBUF = %d\n",rcvbuf);
		Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&sndbuf,&optlen);
		printf("SO_SENDBUF = %d\n",sndbuf);
		
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");
		
		Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&rcvbuf,&optlen);
		printf("SO_RCVBUF = %d\n",rcvbuf);
		Getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&sndbuf,&optlen);
		printf("SO_SENDBUF = %d\n",sndbuf);

	int cnt  = 0;
	len =  sizeof(cliaddr);
	Getsockname(sockfd,(SA *)&cliaddr,&len);
	printf("local addr: %s",Sock_ntop((SA *)&cliaddr,len));
	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		cnt++;
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");
	printf("%d\n",cnt);
	exit(0);
}
