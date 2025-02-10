# CS537 Fall 2024 - Project 2  

## 🔍 Problem Statement  
In this project, I implemented a new **system call** in the xv6 operating system called `getparentname`. This system call retrieves the **name of the parent process** of the calling process and returns it via a user-provided buffer. The project involved:  
- **Modifying xv6's kernel** to add a new system call.  
- **Implementing a user-level program (`getparentname.c`)** to invoke and test the new system call.  
- **Handling edge cases**, such as invalid buffer pointers and non-positive buffer sizes.  
- **Ensuring correct process name retrieval**, by working with xv6’s process control block (PCB).  

This project reinforced my understanding of **system call mechanisms, process management, and navigating a large codebase in xv6**.  

---

## 🎯 What I Learned  
This assignment was an excellent deep dive into **operating systems concepts** and **xv6 internals**. I gained hands-on experience with:  
✅ **Adding a system call** – Understanding how user processes communicate with the kernel.  
✅ **Kernel modifications** – Editing `syscall.c`, `sysproc.c`, `usys.S`, and other key files.  
✅ **Process Control Block (PCB) management** – Accessing process and parent process details.  
✅ **Kernel debugging** – Debugging xv6 using QEMU and print statements.  
✅ **User-space testing** – Writing a user program to verify the system call's correctness.  

---

## 🏆 Results  
I successfully implemented `getparentname`, passing **all test cases**, and received **100% on the assignment**. This project significantly improved my ability to **modify and extend an OS kernel**, a fundamental skill in systems programming.  

---
