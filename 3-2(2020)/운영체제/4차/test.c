#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define __NR_add 349 //system call number 349

int main(int argc, char* argv[])
{
	int a, b;
	long ret;

	a = atoi(argv[1]);
	b = atoi(argv[2]);
    //char -> int

#ifdef WRAPPING // wrapping
	printf("%d add %d = %ld\n", a, b, syscall(__NR_add, getpid()));
#else // not wrapping
	printf("%d add %d = %ld\n", a, b, syscall(__NR_add, a, b));
#endif

	return 0;
}
