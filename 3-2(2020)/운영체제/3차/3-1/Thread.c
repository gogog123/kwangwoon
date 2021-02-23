#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_PROCESSES 4
int file[MAX_PROCESSES*4];
int n;
int file_write = MAX_PROCESSES*2;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

int child(void *arg)
{
    int multi;

    pthread_mutex_lock(&counter_mutex); // mutex lock request
    multi = file[2*n] * file[(2*n)+1];
    n = n+1;
    file[file_write] = multi;
    printf("file[file_write] %d\n", file[file_write]);
    printf("file_write : %d\n", file_write); 

    FILE *f_write = fopen("temp.txt", "a"); //write continuation
    fprintf(f_write, "%d\n", file[file_write]);
    fclose(f_write);

    file_write = file_write +1;
    pthread_mutex_unlock(&counter_mutex);
    return multi;
}

int main()
{
    if(MAX_PROCESSES%2 !=0){
        return 0;
    } // odd error, even

    FILE *f_read = fopen("temp.txt", "r"); //open file only read write
    if(f_read == NULL){
        return 0;
    } // file NULL error

    char str[10];
    for(int i=0; i<MAX_PROCESSES*2; i++)
    {
        fgets(str, sizeof(str), f_read);
        file[i] = atoi(str);
    } //file read
    fclose(f_read); //file close

    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin); //time measurement begin

    for(int i = MAX_PROCESSES; i>0; i = i/2)
    {
        pthread_t tid[MAX_PROCESSES];
        n = 0;
        for(int j=0; j<i; j++)
        {
            pthread_create(&tid[j], NULL, (void*)child, NULL); //create thread
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        for(int j=0; j<i; j++)
        {
            pthread_join(tid[j], (void**)&file[j]); //wait termiantion thread 
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end); //time measurement end
    printf("Run time : %f\n", (double)(end.tv_sec-begin.tv_sec)+ (double)(end.tv_nsec-begin.tv_nsec)/1000000000.0);

    return 0;
}