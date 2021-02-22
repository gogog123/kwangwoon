#include <linux/kernel.h>
#inculde <linux/syscalls.h>

SYSCALL_DEFINE2(add, int, a, int, b)
{
	long ret;

	ret = a+b;

	return ret;
}	
