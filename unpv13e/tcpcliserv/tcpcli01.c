#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	printf("%d\n",SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	str_cli(stdin, sockfd);		/* do it all */
	struct linger lin,linVal;
	socklen_t optlen;
	lin.l_onoff = 1;
	lin.l_linger = 0;
	optlen = sizeof(linVal);
	//setsockopt(sockfd,SOL_SOCKET,SO_LINGER,&lin,sizeof(lin));
	getsockopt(sockfd,SOL_SOCKET,SO_LINGER,&linVal,&optlen);
	printf("linVal %d %d",linVal.l_onoff,linVal.l_linger);
	exit(0);
}
