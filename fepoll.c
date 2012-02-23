#include <stdlib.h>
#include <stdio.h>
#include <sys/epoll.h>

#include "fepoll.h"

/*
return : -1:error
*/
int fepoll_create()
{
	//create listen tcp socket
    int s;
	char bindaddr[20];
	memset(bindaddr, "\0", 20);
	strcpy(bindaddr, "127.0.0.1");
	
    struct sockaddr_in sa;
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//error
		return -1;
	}
	
	memset(&sa,0,sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bindaddr && inet_aton(bindaddr, &sa.sin_addr) == 0) {
        anetSetError(err, "invalid bind address");
        close(s);
        return -1;
    }
    if (anetListen(err,s,(struct sockaddr*)&sa,sizeof(sa)) == ANET_ERR)
        return -1;
	
	
	ep_ac_evt.events = EPOLLIN|EPOLLOUT|EPOLLET;
	int eid = epoll_create(1024);
	epoll_ctl(eid, EPOLL_CTL_ADD, &ep_ac_evt);
}
