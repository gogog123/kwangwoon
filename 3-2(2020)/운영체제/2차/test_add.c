#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char *argv[])
{
	int a, b;
	long ret;
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	ret = syscall(349, a, b);
	printf("%d + %d = %ld\n", a, b, ret);

	return 0;
}

