#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_PROCESSES 10000

void child(int a, int b, int i){
    struct sched_param p;
            
            if(a ==1) //rr time-sharing
            {
                if(b==1) { //highest
                    p.sched_priority = 0; // priorty 
                    nice(-20);
                }
                else if(b==2){ //default
                    p.sched_priority = 0; // priorty 
                    nice(0);
                }
                else{ //b==3 lowest
                    p.sched_priority = 0; // priorty 
                    nice(19);
                }
                
                if(sched_setscheduler(getpid(), SCHED_OTHER, &p)==-1){ // set sheculer
                    perror("rr time-sharing error\n");
                    printf("error\n");
                    return;
                }
            }
            else if(a==2) //first-in, first-out
            {
                if(b==1){ //highest
                    p.sched_priority = sched_get_priority_max(SCHED_FIFO); //max
                }
                else if(b==2){ // default
                    p.sched_priority = (sched_get_priority_min(SCHED_FIFO)+sched_get_priority_max(SCHED_FIFO))/2;
                }
                else{ //lowest
                    p.sched_priority = sched_get_priority_min(SCHED_FIFO);
                }
                
                if(sched_setscheduler(getpid(), SCHED_FIFO,&p)==-1){ // set scheduler
                    perror("first-in first-out error\n");
                    return;
                }
            }
            else{ //rr
                if(b==1){ //highest
                    p.sched_priority = sched_get_priority_max(SCHED_RR); //max
                }
                else if(b==2){ // default
                    p.sched_priority = (sched_get_priority_min(SCHED_RR)+sched_get_priority_max(SCHED_RR))/2;
                }
                else{ //lowest
                    p.sched_priority = sched_get_priority_min(SCHED_RR);
                }
                
                if(sched_setscheduler(getpid(), SCHED_RR,&p)==-1){ // set scheduler
                    perror("first-in first-out error\n");
                    return;
                }
            }    

            chdir("./tmp1"); // change directory
            FILE* file = NULL;
            char f_name[10];
            sprintf(f_name,"%d",i); // file name copy
            file = fopen( f_name, "r" ); // file open
            if( file != NULL )
            {
                char s[10];
                char *tmp;
                
                tmp = fgets( s, sizeof(s), file ); // read text
                fclose( file ); // file close
            }
            exit(0); // exit child
    
}

int main()
{
    int a;
    printf("SELECT NUMBER\n");
    printf("1. the standart round-robin time-sharing policy\n");
    printf("2. a firsth-in, first-out policy\n");
    printf("3. round-robin policy\n");
    printf("select: ");
    scanf("%d", &a); //select
    if(a < 1 || a>3) //error
    {
        printf("error input\n");
        return -1;
    }    

    int b;
    printf("SELECT NUMBER\n");
    printf("1. highest\n");
    printf("2. defalut\n");
    printf("3. lowest\n");
    printf("select: ");
    scanf("%d", &b); //select
    if(b < 1 || b>3) //error
    {
        printf("error input\n");
        return -1;
    } 

    chdir("./tmp1");
    int status;
    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin); //time measurement begin
    pid_t pid;

    for(int i=0; i<MAX_PROCESSES; i++)
    {
        if(pid = fork() > 0) //create process 
        {
            continue;
        }
        
        if(pid == 0) //child
        {
            child(a, b, i);
            //printf("error4\n"); //check4
        }  // child process end  
    }

    for(int i=0; i< MAX_PROCESSES; i++){
        wait(&status);
    }

    clock_gettime(CLOCK_MONOTONIC, &end); //time measurement end
    printf("Run time : %f\n", (double)(end.tv_sec-begin.tv_sec)+ (double)(end.tv_nsec-begin.tv_nsec)/1000000000.0);
    //print run time

    return 0;

}