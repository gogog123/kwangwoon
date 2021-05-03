/////////////////////////////////////////////////////////////////////// 
// File Name : opt.c                                                 // 
// Date : 2020/05/01                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #2-1 (getopt)               // 
// Description : getopt() is called in a loop.                       //
//               when getopt() returns -1, indicating no more options//                                            
//               are preseant, the loop terminates.                  //
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: int -> aflag, bflag parameter                             //
//        char* -> cvalue parameter                                 //
//                                                                  //
// Output: input success a=1, b=1, c=(input value) output           //
//                                                                  //
// Purpose: confirm upload input(char, int type)                    //
//////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    int aflag =0, bflag = 0;
    char *cvalue = NULL;
    int index,c;
    opterr =0;

    while ((c = getopt(argc, argv, "abc:"))!= -1)
    {
        switch(c)
        {
            case 'a':
            {
                aflag=1;  //aflag =1
                break;
            }
            case 'b':
            {
                bflag=1;  //bflag = 1
                break;
            }
            case 'c':
            {
                cvalue = optarg; //get argument
                break;
            }
        }
    }
    printf("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);
    for (index = optind; index < argc; index++)
    {
        printf("Non-option argument %s\n", argv[index]);
    } //print non option

    return 0;
}