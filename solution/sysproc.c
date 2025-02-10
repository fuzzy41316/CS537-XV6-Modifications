#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// Return name of parent and child process
int sys_getparentname(void)
{
  // Grab the current process, as well as the buffer sizes
  struct proc *curproc = myproc();
  int parentbufsize, childbufsize;

  argint(2, &parentbufsize);
  argint(3, &childbufsize);

  // If the buffer sizes are passed a non-positive integer, return -1 to indicate failure
  if (parentbufsize < 1|| childbufsize < 1) return -1;

  // Allocate memory for the buffers based on the aformentioned buffer sizes
  char* parentbuf;
  char* childbuf;
  argptr(0, &parentbuf, parentbufsize);
  argptr(1, &childbuf, childbufsize);

  // If either of the buffers are passed a null pointer, return -1 to indicate failure
  if (parentbuf == 0 || childbuf == 0) return -1;

  // Copy the name of the parent process and child process
  for (int i = 0; i < parentbufsize; i++) parentbuf[i] = curproc->parent->name[i];
  for (int i = 0; i < childbufsize; i++) childbuf[i] = curproc->name[i];

  return 0;
}
