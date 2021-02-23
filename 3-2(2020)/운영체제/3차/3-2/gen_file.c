#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PROCESS 10000

int main()
{
    mkdir("./tmp1", 0777); //make directory
    chdir("./tmp1"); //change directory

    for(int i=0; i< MAX_PROCESS; i++)
    {
        char filename[10];
        sprintf(filename, "%d", i);

        FILE *f_write =fopen(filename, "w"); //open
        fprintf(f_write, "%d", 1+rand()%9);
        fclose(f_write); //close
    }
    return 0;
}