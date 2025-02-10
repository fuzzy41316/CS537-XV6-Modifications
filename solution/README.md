---
title: CS 537 Project 2
name: Harrison Doll
login: hdoll
id: 9079514601
email: hdoll2@wisc.edu
---

- Implementation works as intended, to my knowledge.

Edited usys.S to include syscall(getparentname)
Edited user.h to include int getparentname(char* parentbuf,char* childbuf, int parentbufsize, int childbufsize);
Edited syscall.h to include #define SYS_getparentname 22
Edided syscall.c to include extern int sys_getparentname(void); on line 106 and [SYS_getparentname] sys_getparentname to line 130
Edited sysproc.c to include int sys_getparentname(void) function implementation on line 93-120
Added getparentname.c to ../Solutions folder
Added _getparentname\ to line 172 of Makefile

How does a system call work??
    - usys.S has a list of system calls
    - syscall.h has a list of system call numbers

    - Jump into kernnel mode
        - trap.c initializes the trap handler for syscalls
        - vectors just calls jmp alltraps
        - alltraps is in trapasm.S
        - alltraps sets up a trap frame (defined in include/x86.h)
        jumps to trap

        - now we are in C code in kernel mode in trap.c
        - this in turn calls syscall(); which is in syscall.c

