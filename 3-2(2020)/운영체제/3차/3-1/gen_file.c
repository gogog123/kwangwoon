#include <stdio.h>
#include <stdlib.h>
#include <time.h> //random 
#define MAX_PROCESSES 4

int main()
{
    FILE *f_write = fopen("temp.txt", "w"); //file open

    for(int i= 0; i<MAX_PROCESSES*2; i++)
    {
        fprintf(f_write, "%d\n", 2+rand()%20); // 2~21 number write file
    }

    fclose(f_write); //file close
    return 0;
}