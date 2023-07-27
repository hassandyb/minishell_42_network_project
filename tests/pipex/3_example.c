





#include <stdio.h>
#include <unistd.h>





// int main() {
//     int pipefd[2];
    
//     // Create the pipe
//     pipe(pipefd);


//     pid_t pid = fork();

// 	if(pid != 0) {
//         // Parent process (writing end)
//         dup2(pipefd[1], 1); // Redirect stdout to the writing end of the pipe
//         close(pipefd[1]); // Close the writing end of the pipe
//         close(pipefd[0]); // Close the reading end of the pipe


//         printf("Writing to the pipe something \n");// ==>  1 ==>fd[1]
//     }

//     else
// 	{
//         // Child process (reading end)
//         dup2(pipefd[0], 0); // Redirect stdin to the reading end of the pipe
//         close(pipefd[0]); // Close the reading end of the pipe
//         close(pipefd[1]); // Close the writing end of the pipe

//         char buffer[100];

//         scanf("%99[^\n]", buffer); // Read up to 99 characters until a newline is encountered
//         printf("Received: %s\n", buffer);
//     } 
	

//     return 0;
// }



