#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/sched/mm.h>
#include <linux/syscalls.h>
#include <linux/highmem.h>
#include <linux/sched/mm.h>
#include <asm/syscall_wrapper.h>
//header

#define __NR_add 349 //system call number 349

void **syscall_table;

void *real_add;

__SYSCALL_DEFINEx(1, info, pid_t, pid){
    struct task_struct *t;
    struct mm_struct *mm; //physical memory
    struct vm_area_struct *vm; //virtual memory

    t = pid_task(find_vpid(pid), PIDTYPE_PID);
    mm = get_task_mm(t);
    vm = mm->mmap; //

    printk(KERN_INFO "########## Loaded files of a process 'test(%d)' in VM ##########\n", pid);

    while(vm->vm_next != NULL){ // vm end
        char buf[256];
        char *path; //

        if(vm->vm_file != NULL){
            path = dentry_path_raw(vm->vm_file->f_path.dentry, buf, sizeof(buf));
			printk(KERN_INFO "mem(%lx ~ %lx) code(%lx ~ %lx) data(%lx ~ %lx) heap(%lx ~ %lx) %s\n"
			,vm->vm_start, vm->vm_end,mm->start_code, mm->end_code,mm->start_data, mm->end_data, mm->start_brk, mm->brk,path);        }
        vm = vm->vm_next;
    }
   	printk(KERN_INFO "#################################################################\n");
 

    mmput(mm); //1 decrease, when 0,free space
    
    return 0;
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
	syscall_table[__NR_add] = __x64_sysinfo;
	//printk(KERN_INFO "init_[2017202087]\n");

	return 0;
}

static void __exit hooking_exit(void) { 
	syscall_table[__NR_add] = real_add; 

	make_ro(syscall_table); 
	//printk(KERN_INFO "exit_[2017202010]\n"); 
}

module_init(hooking_init);
module_exit(hooking_exit);
MODULE_LICENSE("GPL");
