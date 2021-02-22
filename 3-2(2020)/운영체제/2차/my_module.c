#include <linux/module.h>
#include <linux/highmem.h>
#include <linux/kallsyms.h>
#include <linux/syscalls.h>
#include <asm/syscall_wrapper.h>
#define __NR_add 349

void **syscall_table;

void *real_add;

__SYSCALL_DEFINEx(2, sub, int, a, int, b)
{
	printk("Kernel hooked func: %d - %d\n", a, b);
	return a-b;
}

void make_rw(void *addr)
{
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level);

	if(pte->pte &~ _PAGE_RW)
		pte->pte |= _PAGE_RW;
}

void make_ro(void *addr)
{
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level);

	pte->pte = pte->pte &~ _PAGE_RW;
}

static int __init hooking_init(void)
{
	syscall_table = (void**) kallsyms_lookup_name("sys_call_table");

	make_rw(syscall_table);
	real_add = syscall_table[__NR_add];
	syscall_table[__NR_add] = __x64_syssub;
	printk(KERN_INFO "init_[2017202087]\n");

	return 0;
}

static void __exit hooking_exit(void) { 
	syscall_table[__NR_add] = real_add; 

	make_ro(syscall_table); 
	printk(KERN_INFO "exit_[2017202010]\n"); 
}

module_init(hooking_init);
module_exit(hooking_exit);
MODULE_LICENSE("GPL");
