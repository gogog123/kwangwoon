/////////////////////////////////////////////////////////////////////// 
// File Name : cli.c                                                 // 
// Date : 2020/05/27                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #3-2                        // 
// Description : To client connecting server                         //
//               server address is 127.0.0.1                         //
//               by using write().                                   //
//               if the result of "quit" returned, quit program      //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h> //memset

#define BUF_SIZE 256

//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: char -> buff                                              //
//        int -> n  : length                                        //
//        int -> sockfd : socket connect                            //
//        struct sockaddr_in -> srvaddr  : socket address           //
// Output: buff(form the server)                                    //
//         quit -> program exit.                                    //
// Purpose: To server connecting client.                            //
//          Output from server                                      //
//////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    char buff[BUF_SIZE];
    int n;
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/////////////////////////////connect with server////////////////////////////////////
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("can't connect.\n");
        return -1;
    }

///////////////////////////sending and receiving data///////////////////////////////////////////////
    while(1)
    {
        write(STDOUT_FILENO, "> ", 2);
        read(STDIN_FILENO, buff, BUF_SIZE);

        if(write(sockfd, buff, BUF_SIZE)>0) // buffer to server
        {
            if(read(sockfd, buff, BUF_SIZE)>0)
                printf("from server: %s", buff); //buffer from the server
            else
                break;
        }
        else
            break;
            
    }

    close(sockfd);
    return 0;
}