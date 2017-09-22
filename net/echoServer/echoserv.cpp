#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "helper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ECHO_PORT 2002
#define MAX_LINE 1024

int main(int argc,char ** argv)
{
	int list_s;
	int conn_s;
	short int port;
	struct sockaddr_in servaddr;
	char buffer[MAX_LINE];
	char *endptr;
	
	if(argc == 2)
	{
		port = strtol(argv[1],&endptr,0);
		if(*endptr)
		{
			fprintf(stderr,"ECHOSERV : Invaild arguments.\n");
			exit(EXIT_FAILURE);
		}
		
	}
	else if(argc < 2)
	{
		port = ECHO_PORT;
	}
	else {
		fprintf(stderr,"ECHOSERV:Invaild arguments.\n");
		exit(EXIT_FAILURE);
	}
	
	if((list_s = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		fprintf(stderr,"ECHOSERV:Error creating listening socket.\n");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	
	if(bind(list_s,(struct sockaddr *) &servaddr,sizeof(servaddr)) < 0)
	{
		fprintf(stderr, "ECHOSERV : Error calling bind() \n");
		exit(EXIT_FAILURE);
	}
	
	if(listen(list_s,LISTENQ) < 0)
	{
		fprintf(stderr,"ECHOSERV : Error calling listen()\n");
		exit(EXIT_FAILURE);
	}
	
	while(1)
	{
		if((conn_s = accept(list_s,NULL,NULL)) < 0)
		{
			fprintf(stderr,"ECHOSERV : Error calling accpet()\n");
			exit(EXIT_FAILURE);
		}
		
		Readline(conn_s,buffer,MAX_LINE - 1);
		Writeline(conn_s,buffer,strlen(buffer));
		
		if(close(conn_s) < 0)
		{
			fprintf(stderr,"ECHOSERV:Error calling close()\n");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
}
