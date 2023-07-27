

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

// why pipe


// to use excve we need to run it in a child process cause it replacecs the proccess image with the coamnd program process image

// so we have the child process

// now a question hto excute comand like ls cat pwd grep .ext using excve 
// we need to change the input or out put for the comand 

// the problem is with execve the is not argumnet for fdout and fdin the work standared

// to create an enter comunication between tow procees you need a pipe
// to change the defult 0 1 , 2 yu will need dup2 ....


// let suose we want to excye ths comand ls - la | grep 1_why_pipe


int main ()
{
    int fd[2];
    pipe(fd);

    int pid = fork();
    
    if(pid != 0)//parent process
    {
        wait(NULL);
        // dup2(fd[1], 1);// changing standared out put
        execve
    }
    else
    {
        // dup2(fd[0], 0);

    }
}















