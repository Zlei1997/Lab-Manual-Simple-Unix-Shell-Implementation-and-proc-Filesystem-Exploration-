# Lab-Manual-Simple-Unix-Shell-Implementation-and-proc-Filesystem-Exploration-# Simple Shell Implementation


In this project I will try to implement a basic Unix shell in C that accepts user commands, processes them, and executes the corresponding programs. I will also extend the shell to explore and display information from the /proc filesystem in Linux. I will build the basic shell function in the first part and then add the proc command in the second part. This is done through my virtual machine box (Linux ubuntu).



## Compilation and Execution
1. First, I will write the contents and save the code to a file named `simple_shell.c`. I use "vi simple_shell.c"
2. I compile the shell with the following command gcc -o simple_shell simple_shell.c
3. Next I will run the shell with ./simple_shell
4. I use these sample commands: ls, echo Hello, World! , echo Ming, exit 0
5. I go back and write to implement the proc command
6. I use these sample commands: proc cpuinfo, proc loadavg, proc 1482/status


# Takeaway
This project helps me understand and get more familiar with basic shell functionality such as command parsing, process control, and interaction with the proc filesystem in Linux.
