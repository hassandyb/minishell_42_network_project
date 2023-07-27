



//Why do we need the fork 

#include <stdio.h>
#include <unistd.h>



// int main ()
// {
// 	printf("1\n");
// 	printf("1\n");
// 	printf("1\n");

// 	execve("/bin/pwd", (char*[]){"pwd", NULL}, NULL);
// 	printf("2\n");
// 	printf("2\n");
// 	printf("2\n");
// }

// why you cant see the 2 number desplayed 



// execve function, it replaces the current process image with a new process image of the "pwd" command.
//the execve call, your program stops executing, and the "pwd" command runs instead,
// This behavior of execve is called "process image replacement." 
// replaces the current process image. ==>means once you call execve the the procees you are working with it s all component (function, data, code ...) will be changed with he comand component you trying to execute

// how can i fix that 

// you can use simply run execve in child process

#include <sys/wait.h>
int main ()
{
	printf("1\n");
	printf("1\n");
	printf("1\n");	
	int pid = fork();
	if(pid != 0)
	{
		wait(NULL);// wait all child process to finish, means to excute he coamnd and exit
		printf("2\n");
		printf("2\n");
		printf("2\n");
	}
	else
	{
		execve("/bin/ls", (char *[]){"ls", "-la", NULL}, NULL);
	}
}



