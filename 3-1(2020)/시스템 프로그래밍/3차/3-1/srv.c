/////////////////////////////////////////////////////////////////////// 
// File Name : srv.c                                                 // 
// Date : 2020/05/23                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #3-1                        // 
// Description : To server connecting client                         //
//               Use listen() and accept()                           //
//               When client connected, display client IP and PORT   //
//               Receive command from client                         //
//               Send result processed to client                     //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MAX_BUFF 1024
#define SEND_BUFF 1024


//////////////////////////////////////////////////////////////////////
// client_info function                                             //
// ================================================================ //
// Input:  struct sockaddr_in -> cliaddr  : socket address          //
// Output: client information                                       //
//         return 1                                                 //
// Purpose:  display client IP and PORT .                           //
//////////////////////////////////////////////////////////////////////
int client_info(struct sockaddr_in* cliaddr)
{
    printf("\n==========Client info==========\n");
    write(STDOUT_FILENO, "client IP: ", 10);
    write(STDOUT_FILENO, inet_ntoa((*cliaddr).sin_addr), sizeof(*cliaddr)); 
    // 32bitIP_address -> datted decimal S
    write(STDOUT_FILENO, "\n",2);
    printf("client port: ");
    printf("%d \n",ntohs((*cliaddr).sin_port));
    //network byte order -> host byte order
    printf("===============================\n");
    return 1;
}

//////////////////////////////////////////////////////////////////////
// client_process function                                          //
// ================================================================ //
// Input:  char* -> buff, result_buff                               //
// Output: return 1                                                 //
// Purpose: copy result_buff = buff                                 //
//////////////////////////////////////////////////////////////////////
int cmd_process(char *buff, char* result_buff)
{
    strcpy(result_buff, buff);
    return 1;
}


//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: char -> buff, result_buff                                 //
//        int -> n, clilen  : length                                //
//        int -> sockfd : socket connect                            //
//        struct sockaddr_in -> srvaddr, cliaddr  : socket address  //
// Output:  Instruction input to client                             //
// Purpose: To implement information transfer between networks.     //
//////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    char buff[MAX_BUFF], result_buff[SEND_BUFF];
    int n ,clilen;

    struct sockaddr_in cliaddr, srvaddr;
    int connfd, listenfd;

    if(argc != 2)
    {
        printf("input wrong\n");
        return 0;
    }

    int port = atoi(argv[1]);

//////////////////////////socket connet/////////////////////////////////////
    if((listenfd = socket(PF_INET, SOCK_STREAM, 0))<0)
    {
        printf("Server: Can't open stream socket.\n");
        return 0;
    }

/////////////////////////////connect with client////////////////////////////////////
    bzero((char*)&srvaddr, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    srvaddr.sin_port = htons(port);

    if(bind(listenfd,(struct sockaddr *)&srvaddr, sizeof(srvaddr))<0)
    {
        printf("Server: Can't bind local address.\n");
        return 0;
    }

    listen(listenfd, 5);

///////////////////////////sending and receiving data///////////////////////////////////////////////
    while(1)
    {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
        if(connfd<0)
        {
            printf("Server: accept faild.\n");
            return 0;
        }

/////////////////////////////print client information //////////////////////////////////
        if(client_info(&cliaddr)<0)
        {
            write(STDERR_FILENO, "client_info() err!!\n", 20);
        }

        while((write(connfd, buff, MAX_BUFF))>0)
        {
            n = read(connfd, buff, MAX_BUFF);
            buff[n] = '\0';

            if((cmd_process(buff, result_buff))<0)
            {
                write(STDERR_FILENO, "cmd_process() err!!\n", 20);
                break;
            }//result buff copy

//////////////////////////////send data/////////////////////////////////////////////////
            write(connfd, result_buff, strlen(result_buff));
            write(STDOUT_FILENO, result_buff, n);

            if(!strcmp(result_buff, "quit"))
            {
                write(STDOUT_FILENO, "quit\n", 10);
                close(connfd); // client disconnect
                break;
            }
        }
    }

    close(listenfd);  // server disconnect
    return 0;
}
