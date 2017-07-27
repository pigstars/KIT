//
//  main.cpp
//  TTCP
//
//  Created by pigstars on 2017/7/27.
//  Copyright © 2017年 pigstars. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
struct option long_options[] =
{
    {"help",no_argument,NULL,'n'},
    {0,0,0,0},
};
struct optt
{
    unsigned int port;
    char *host;
};
struct optt option;
char *usage =
{
    "TTCP \n"
    "--help     Show usage\n"
    "-p         remote host's port\n"
    "-h         remote host\n"
};

void show_usage();

int main(int argc, char * argv[]) {
    int opt;
    int option_index = 0;
    int socketfd;
    std::string optString = "p:h:";
    while((opt = getopt_long(argc, argv,optString.c_str(),long_options,&option_index)) != EOF)
    {
        
        switch(opt)
        {
            case 'n':
                show_usage();
                break;
            case 'p':
                option.port = atoi(optarg);
                break;
            case 'h':
                option.host = optarg;
                break;
            default:
                show_usage();
                break;
        }
    }
    
    struct hostent *hp = gethostbyname(option.host);
    int i = 0;
    while(hp->h_addr_list[i] != NULL)
    {
        printf("hostname: %s\n",hp->h_name);
        printf("      ip: %s\n",inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
        i++;
    }
    
   
    
    return 0;
}

inline void show_usage()
{
    std::cout << usage << std::endl;
}

int Socket(const char *host,int clienPort)
{
    int sock;
    unsigned long inaddr;
    struct sockaddr_in ad;
    struct hostent *hp;
    
    memset(&ad,0,sizeof(ad));
    ad.sin_family = AF_INET;
    inaddr = inet_addr(host);
    
    if(inaddr != INADDR_NONE)
    {
        memcpy(&ad.sin_family,&inaddr,sizeof(inaddr));
    }
    else
    {
        hp = gethostbyname(host);
        if(hp == NULL)
        {
            return -1;
        }
        memcpy(&ad.sin_addr, hp->h_addr, hp->h_length);
       
    }
    ad.sin_port = htons(clienPort);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        return sock;
    if(connect(sock, (struct sockaddr *)&ad, sizeof(ad) < 0))
        return -1;
    return sock;
    
}
