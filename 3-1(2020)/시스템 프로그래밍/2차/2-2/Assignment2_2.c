/////////////////////////////////////////////////////////////////////// 
// File Name : Assignment2_2.c                                       // 
// Date : 2020/05/05                                                 // 
// Os : Ubuntu 16.04 LTS 64bits                                      // 
// Author : Hong se jung                                             // 
// Student ID : 2017202087                                           // 
// ----------------------------------------------------------------- // 
// Title : System Programming Assignment #2-2 (ls-filesystem)        // 
// Description : To implement ls instruction.                        //
//               Use opendir(), readdir(), closedir().               //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

//////////////////////////////////////////////////////////////////////
// main function                                                    //
// ================================================================ //
// Input: DIR* -> dp, file open pointer                             //
//        dirent* -> drip , access file name                        //
//                                                                  //
// Output: input file name existence      output filename(success)  //
//               file name not existence  output fail               //
// Purpose: To implement ls instruction.                            //
//////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp=0; 

    dp = opendir("./"); //directory open

    if(argc>=2)
    {
        dp = opendir(argv[argc-1]);
        if(dp==NULL) //directory not fond
        {
            printf("can't open %s\n",argv[1]);
            return 0; //exit
            }
    }
    
    while((dirp=readdir(dp))!=0)
    {
        printf("filename : %s\n", dirp->d_name);
    }//filename print
    
    closedir(dp); //directory close

    return 0;
}