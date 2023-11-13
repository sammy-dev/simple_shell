#0x16. C - Simple Shell

## Learning Objectives
At the end of this project, you will have a deep understanding of various aspects of the Unix operating system, including its history, key figures, and fundamental concepts. Additionally, you will gain practical knowledge in shell programming, process management, and system calls. The project aims to enhance your ability to explain the following topics without external assistance:

### General
**Original Unix Operating System:**
   - Identify the designer and implementer of the original Unix operating system.

**UNIX Shell:**
   - Recognize the individual who wrote the first version of the UNIX shell.

 **B Programming Language:**
   - Understand the inventor of the B programming language, the direct predecessor to the C programming language.

 **Ken Thompson:**
   - Describe the significance and role of Ken Thompson in the development of Unix.

 **Shell Functionality:**
   - Explain how a shell works and its role in the Unix environment.

 **Process Identification:**
   - Define what a PID (Process ID) and PPID (Parent Process ID) are in Unix.

 **Environment Manipulation:**
   - Learn how to manipulate the environment of the current process.

 **Function vs. System Call:**
   - Differentiate between a function and a system call.

 **Process Creation:**
   - Understand the process of creating processes in Unix.

 **Main Prototypes:**
    - Identify the three prototypes of the main function.

 **PATH Usage:**
    - Explain how the shell uses the PATH variable to locate programs.

 **Execve System Call:**
    - Learn how to execute another program using the execve system call.

 **Process Suspension:**
    - Understand how to suspend the execution of a process until one of its children terminates.

 **EOF (End-of-File):**
    - Define EOF and its significance in file handling.

### Copyright - Plagiarism
- Acknowledge the importance of original work and the consequences of plagiarism.

### Project Requirements
- Adhere to specific coding standards (Betty style).
- Implement a shell that complies with specified requirements.
- Avoid memory leaks in the shell code.
- Utilize a limited set of allowed functions and system calls.
- Create a README.md file providing project description and instructions.
- Include an AUTHORS file listing all contributors to the repository.

### Compilation and Testing
- Compile the shell using a specific set of options.
- Test the shell in both interactive and non-interactive modes.
- Ensure the shell produces the same output and error messages as the /bin/sh shell.

## Project Structure
The project should include the following components:

 **Source Code:**
   - Shell implementation files (no more than 5 functions per file).
   - Header files with proper include guards.

 **Documentation:**
   - README.md file providing project description and instructions.
   - AUTHORS file listing all contributors.

 **Coding Standards:**
   - Code should adhere to the Betty style.

 **Testing Suite:**
   - Develop a suite of tests covering regular and edge cases.

## Compilation and Execution
To compile the shell, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the shell in interactive mode:
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Run the shell in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
```

## Tasks

### 0. Betty would be proud
- Write a beautiful code that passes the Betty checks.
- Repository: [simple_shell](GitHub repository link)

### 1. Simple shell 0.1
- Write a UNIX command line interpreter.
- Usage: `simple_shell`
- Handle basic commands and errors.

### 2. Simple shell 0.2
- Handle command lines with arguments.

### 3. Simple shell 0.3
- Handle the PATH.
- Avoid unnecessary fork calls.

### 4. Simple shell 0.4
- Implement the exit built-in command.

### 5. Simple shell 1.0
- Implement the env built-in command.

### 6. Simple shell 0.1.1
- Write your own getline function.
- Use a buffer to optimize reading.

### 7. Simple shell 0.2.1
- Avoid using strtok.

### 8. Simple shell 0.4.1
- Handle arguments for the built-in exit command.

### 9. setenv, unsetenv
- Implement the setenv and unsetenv built-in commands.

### 10. cd
- Implement the built-in command cd.

### 11. ;
- Handle the commands separator ;.

### 12. && and ||
- Handle the shell logical operators && and ||.

### 13. alias
- Implement the alias built-in command.

### 14. Variables
- Handle variables replacement.
- Handle $? and $$ variables.

### 15. Comments
- Handle comments (#).

### 16. File as input
- Accept a file as a command line argument.
- Execute commands from the file.

## Conclusion
This project will provide a comprehensive understanding of Unix, shell programming, and system calls, enhancing your proficiency in system-level programming and software development. It encourages collaboration, adherence to coding standards, and the development of robust and efficient code.
```
