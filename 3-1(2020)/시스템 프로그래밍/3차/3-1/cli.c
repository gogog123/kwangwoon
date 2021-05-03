/////////////////////////////////////////////////////////////////////// 
// File Name : cli.c                                                 // 
// Date : 2020/05/23                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #3-1                        // 
// Description : To client connecting server                         //
//               server address is 127.0.0.1                         //
//               if the result of "ls" returned, write it to stdout  //
//               by using write().                                   //
//               if the result of "quit" returned, quit program      //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <dirent.h>   //ls print

#define MAX_BUFF 1024
#define RCV_BUFF 1024
//#define PORTNO 1000


//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: char -> buff, cmd_buff, rcv_buff                          //
//        int -> n  : length                                        //
//        int -> sockfd : socket connect                            //
//        struct sockaddr_in -> srvaddr  : socket address           //
// Output: ls -> To arrange directory file                          //
//         quit -> program exit.                                    //
// Purpose: To implement information transfer between networks.     //
//////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    char buff[MAX_BUFF], cmd_buff[MAX_BUFF], rcv_buff[RCV_BUFF];
    int n;

    int sockfd;
    struct sockaddr_in srvaddr;

    if(argc != 3)
    {
        printf("input wrong\n");
        return 0;
    }

    int port = atoi(argv[2]); //save input port
    char *haddr = argv[1]; //save input address

    if((sockfd=socket(PF_INET, SOCK_STREAM, 0))<0)
    {
        printf("can't creat socket.\n");
        return -1;
    }

/////////////////////////////connect with server////////////////////////////////////
    bzero(buff, sizeof(buff));
    bzero((char*)&srvaddr, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.s_addr = inet_addr(haddr);
    srvaddr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr))<0)
    {
        printf("can't connect.\n");
        return -1;
    }

///////////////////////////sending and receiving data///////////////////////////////////////////////
    for(;;)
    {
        write(STDOUT_FILENO,"> ", 2);
        n = strlen(cmd_buff);

        if((n = read(sockfd, rcv_buff, RCV_BUFF-1))<0)
        {
            write(STDERR_FILENO, "read() error\n", 20);
            exit(1);
        }

        n=read(STDIN_FILENO, rcv_buff, sizeof(rcv_buff)); //receive
        rcv_buff[n] = '\0';
        write(sockfd, rcv_buff, n); //send

//////////////////////////////instruction ls////////////////////////////////////////
        if(strcmp(rcv_buff, "ls\n")==0)
        {
            DIR *dp;
            struct dirent *dirp=0; 
            dp = opendir("./"); //directory open
            while((dirp=readdir(dp))!=0)
            {
                printf("%s\n", dirp->d_name);
            }//filename print
    
            closedir(dp); //directory close
        }

///////////////////////////////instruction quit/////////////////////////////////////////////////
        else if(strcmp(rcv_buff, "quit\n")==0)
        {
            write(STDOUT_FILENO, "Program quit!!\n", 20);
            exit(1);
        }

/////////////////////////////instruction else/////////////////////////////////////////////
        else
        {
            printf("input wrong\n");
            return 0;
        }
        write(STDOUT_FILENO, "\n", 1);
    }

    close(sockfd); // disconnect
  
    return 0;
}