



//		int pipe(int pipefd[2]);




		// pipefd[0] reading from the pipe fd;

		// pipefd[1] writing to the pipe fd;

		// pipefd[1]  | pipefd[0]














#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// int main() {
//     int pipefd[2]; // Array to store read and write file descriptors

// 	pipe(pipefd);
// 	pid_t pid = fork();



// 	if(pid != 0) 
// 	{
//         // Parent process (Writer)
//         close(pipefd[0]); // Close the read end since parent only writes
//         char message[] = "Hello, child!";
//         write(pipefd[1], message, sizeof(message));
//         close(pipefd[1]); // Close the write end after writing
//     }
// 	else
// 	{
//         // Child process (Reader)
//         close(pipefd[1]); // Close the write end since child only reads
//         char buffer[100];
//         ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1);
//         buffer[bytesRead] = '\0';
//         printf("Child received: %s\n", buffer);
//         close(pipefd[0]); // Close the read end after reading
//     } 
	

//     return 0;
// }




//    write fd[1] |  read df2[0]

// example of parent process sending a message to the child ;
// int main ()
// {
// 	int fd[2];

// 	pipe(fd);
// 	int p = fork();

// 	if(p != 0)// parent proccess
// 	{

// 		close(fd[0]);
// 		char msg[] = "Amessage sent from the fd inpot of the pipe to the out put fd of the pipe, resualting creatingaan entercommunication  between a parent process to his child process";
// 		write(fd[1], msg, sizeof(msg));
// 		close (fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		char buff[200];
// 		ssize_t n =  read(fd[0], buff, 199);
// 		buff[n] = '\0';
// 		printf("Child process receved this :\n%s\n", buff);
// 		close(fd[0]);
// 	}
// }

// example of sending a number from child to parnet using pipe

// int main ()
// {
// 	int fd[2];


// 	pipe(fd);
// 	int p = fork();

// 	if(p == 0)// child process
// 	{
// 		int nbr = 1997;
// 		write(fd[1], &nbr, sizeof(int));
// 	}
// 	else// parent proccess
// 	{
// 		int nbr;
// 		read(fd[0], &nbr, sizeof(int));
// 		printf("The parent process recieve this number : %d\n", nbr);
// 	}
// }














