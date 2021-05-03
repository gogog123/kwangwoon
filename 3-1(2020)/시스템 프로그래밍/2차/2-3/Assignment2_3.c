/////////////////////////////////////////////////////////////////////// 
// File Name : Assignment2_3.c                                       // 
// Date : 2020/05/06                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #2-3                        // 
// Description : To implement file related instruction.              //
//               pwd, cd, mkdir, rmdir, rename, exit                 //
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: char -> getStr, command confirm                           //
//        int -> a,  end judgment                                   //
//        char -> cwd, current location                             //
//        char -> ptr_make, save file name                          //
// Output: pwd - current working directory                          //
//         cd - change current working directory                    //
//         mkdir - make directory                                   //
//         rmdir - remove directory                                 //
//         exit - end process                                       //
// Purpose: To implement file related instruction.                  //
//////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    char getStr[128];
    int a=0;
    char cwd[128]; // current directory

    while(a==0)
    {
        int i=0;
        printf(">>");
        fgets(getStr, sizeof(getStr), stdin);
        char *ptr = strtok(getStr, " ");

/////////////////////////// getStr : pwd ///////////////////////////////       
        if(strcmp(getStr,"pwd\n")==0)
        {
            getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
        } //when no argument
        else if(strcmp(ptr,"pwd")==0)
        {
            printf("error(argument existence)\n");
            continue;
        }//when argument existence


/////////////////////////// getStr : cd ///////////////////////////////
        else if(strcmp(ptr,"cd\n")==0)
        {
            printf("error(No argument)\n");
            continue;
        } //when no argument
        else if(strcmp(ptr,"cd")==0)
        {
            ptr = strtok(NULL, "\n");
            int check = chdir(ptr);
            if(check==-1)
            {
                printf("error directory not found\n");
            }
        }


/////////////////////////// getStr : mkdir ///////////////////////////////
        else if(strcmp(ptr,"mkdir\n")==0)
        {
            printf("error(No argument)\n");
        } 
        else if(strcmp(ptr,"mkdir")==0)
        {
            mode_t mode;
            char *ptr_make[10]; //save file name
            int i=0;
            ptr_make[i] = strtok(NULL, " ");
            while(ptr_make[i]!=0)
            {
                if (strcmp(ptr_make[i],"-m")==0)
                {
                    char *ptr_test = strtok(NULL, " ");
                    mode = strtol(ptr_test, NULL, 8); //change string->octal
                    i--;
                }
                i++;
                ptr_make[i] = strtok(NULL, " ");
            }
            ptr_make[i-1] = strtok(ptr_make[i-1], "\n");
            for(int j=0; j<i; j++)
            {
                mkdir(ptr_make[j], mode); //autorization
            }
        }

/////////////////////////// getStr : rmdir ///////////////////////////////
        else if(strcmp(ptr,"rmdir\n")==0)
        {
            printf("error(No argument)\n");
        } ///when no argument
        else if(strcmp(ptr,"rmdir")==0)
        {
            ptr = strtok(NULL, "\n");
            rmdir(ptr);
        }

/////////////////////////// getStr : rename ///////////////////////////////        
        else if(strcmp(ptr,"rename\n")==0)
        {
            printf("error(No argument)\n");
        }
        else if(strcmp(ptr,"rename")==0)
        {
            char *ptr1 = strtok(NULL, " ");
            char *ptr2 = strtok(NULL, " ");
            char *ptr3 = strtok(NULL, " ");
            if(ptr2==NULL || ptr3!=0) 
            {
                printf("error(two argument error)\n");
                continue;
            }//no two arguments 
            ptr2 = strtok(ptr2, "\n");

            rename(ptr1, ptr2); 
        }

/////////////////////////// getStr : exit ///////////////////////////////  
        else if(strcmp(ptr,"exit\n")==0)
        {
            a=1; //end while
        }

/////////////////////////// getStr : ? ///////////////////////////////  
        else
        {
            printf("error instruction\n");
        }
        
    }
    return 0;
}