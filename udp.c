

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
/*
	The parameters p1, p2, p3 can represent anything you want e.g. the packet size, the transmission delay, buffer size etc. You need not use all 3 parameters but your program should accept max 3 parameters.
	*/
void main(int argc, char **argv) {
    int sockfd, port,packetsize,buffersize,fd;
    ssize_t n;
    struct sockaddr_in serveraddr;
    char *host,*filename;
    useconds_t delay;
    if (argc != 6) {
       printf("usage: %s <host> <port> <filename>  <delay> <buffersize>\n", argv[0]);
	   // ./udp 128.235.25.157 2244 b0.mp3 10 1024
  //     printf("usage: %s <host> <port> <filename> <packetsize> <delay> <buffersize>\n", argv[0]);
       exit(0);
    }
	host = argv[1];
    port = atoi(argv[2]);
	filename=argv[3];
	//packetsize=atoi(argv[4]);
    delay = atoi(argv[4]);
	buffersize = atoi(argv[5]);	
	/*
	packetsize=atoi(argv[4]);
    delay = atoi(argv[5]);
	buffersize = atoi(argv[6]);
	*/
	char buf[buffersize];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket Created\n");
    if (sockfd < 0){
        error("ERROR opening socket");
    }    
        bzero((char *) &serveraddr, sizeof(serveraddr));
        serveraddr.sin_family=AF_INET;
	    serveraddr.sin_addr.s_addr=inet_addr(host);
	    serveraddr.sin_port=htons(port);
    if ((fd = open(filename,O_RDONLY)) < 0){
        error(" ERROR can't open file!\n");
	}
    while(1)
    {  
	   bzero(buf,buffersize);
       n = read(fd,buf,buffersize);
	   if(n<=0){
        break;
	   }
	   printf("Socket Created\n");
       sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr));
	   usleep(delay*1000);
    }
     printf("done\n");
}