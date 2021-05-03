/////////////////////////////////////////////////////////////////////// 
// File Name : srv.c                                                 // 
// Date : 2020/05/27                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #3-2                        // 
// Description : To server connecting client                         //
//               Process fork() system call                          //
//               signal handling                                     //                     //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>  //signal

#define BUF_SIZE 256

//////////////////////////////////////////////////////////////////////
// sh_chld, sh_alrm function                                        //
// ================================================================ //
// Input:  signum                                                   //
// Output:    X                                                     //
// Purpose:  signal handling                                         //
//////////////////////////////////////////////////////////////////////
void sh_chld(int signum)
{
    printf("Status of child process was changed.\n");
    wait(NULL);
}

void sh_alrm(int signum)
{
    printf("Child Process(PID : %d) will be terminated.\n", getpid());
    exit(1);
}

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
    printf("==========Client info==========\n");
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
// main function                                                    //
// ================================================================ //
// Input: char -> buff                                              //
//        int -> n, clilen  : length                                //
//        int -> sockfd, client_fd : socket connect                 //
//        struct sockaddr_in -> server_addr                         //
//                              client_addr  : socket address       //
// Output: client information                                       //
//         child process ID                                         //
//         confirm of child termination                             //
// Purpose:  To server connecting client                            //
//           Process fork() system call                             //
//////////////////////////////////////////////////////////////////////

int main(int argc, char ** argv)
{
    char buff[BUF_SIZE];
    int n;
    struct sockaddr_in server_addr, client_addr;
    int server_fd, client_fd;
    int len;
    int port;

////////////// Applying signal handler(sh_alrm) for SIGALRM ////////////////
////////////// Applying signal handler(sh_chld) for SIGCHID ////////////////
    signal(SIGCHLD, sh_chld);
    signal(SIGALRM, sh_alrm);

//////////////////////////socket connet/////////////////////////////////////
    server_fd = socket(PF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_fd,(struct sockaddr *)&server_addr, sizeof(server_addr))<0)
    {
        printf("Server: Can't bind local address.\n");
        return 0;
    }
    listen(server_fd, 5);

///////////////////////sending and receiving data///////////////////////////////////////////////
    while(1)
    {
        pid_t pid;
        len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);

///////////////////////print client information //////////////////////////////////
        if(client_info(&client_addr)<0)
        {
            write(STDERR_FILENO, "client_info() err!!\n", 20);
        }
       
        
        n=(read(client_fd, buff, BUF_SIZE)); //read 
        while(1)
        {
            write(client_fd, buff, n); //write
            
            if((pid=fork())<0) // error
            {
                write(STDERR_FILENO, "fork error\n", 20);
            }
            else if(pid == 0) //child
            {
                printf("Child Process ID : %d\n", getpid()); // print prcess id
                n=(read(client_fd, buff, BUF_SIZE));
                //printf("%s", buff);

                if((strncmp(buff, "quit\n", 4))==0) //quit string compare
                {
                    alarm(1); //child end
                    sleep(2); 
                    break;
                }

                else //not quit
                    continue;
            }
            else // parent
            {
                sleep(10); //waiting
            }

            break;
        }

        //write(client_fd, buff, 0);

        close(client_fd); // exit connect
        return 0;

    }

    return 0;
    
}