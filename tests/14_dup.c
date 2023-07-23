


// int dup(int oldfd);





// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>

// int main() {
//     int fd = open("file.txt", O_RDONLY); 


//     int newfd = dup(fd);  


//     char buffer[4];
//     read(fd, buffer, 3);
//     buffer[3] = '\0';

//     printf("%s\n", buffer);
// 	buffer[0] = '\0';



//     read(newfd, buffer, 3);
//     buffer[3] = '\0';
//     printf("%s\n", buffer);

//     // close(fd);
//     // close(newfd);

//     return 0;
// }


// wy would i need to use dup 
//   1  Parallel Processing: _________________________________






// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <pthread.h>

// void* threadFunction(void* arg) {
//     int fd = *(int*)arg;
//     int newfd = dup(fd);  // Duplicate the file descriptor
//     char buffer[4];

//     // Read from the duplicated file descriptor
//     ssize_t bytesRead = read(newfd, buffer, 3);
//     buffer[3] = '\0';
    
//     // Print the read content
//     printf("Thread with fd = %d : %s\n", newfd, buffer);

//     close(newfd);
//     pthread_exit(NULL);
// }

// int main() {
//     int fd = open("file.txt", O_RDONLY);  // Open file for reading



//     pthread_t thread1, thread2;

//     // Create two threads
//     pthread_create(&thread1, NULL, threadFunction, &fd);
//     pthread_create(&thread2, NULL, threadFunction, &fd);

//     // Wait for threads to finish
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     close(fd);

//     return 0;
// }


// scenarios where dup becomes necessary:
//  File Descriptor Preservation: Sometimes, you may need to preserve a file descriptor for later use while performing redirection. The dup function allows you to duplicate the file descriptor and keep a separate copy, which can be useful for restoring the original file descriptor state after redirection.

		// int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		// int savedFd = dup(fd); // Duplicate the file descriptor

		// // Perform redirection with dup2
		// dup2(otherFd, fd); // Redirect fd to otherFd

		// // ...

		// // Restore the original file descriptor state
		// dup2(savedFd, fd);




//  Multiple Input/Output Streams: When dealing with multiple input or output streams simultaneously, duplicating file descriptors can help manage the streams separately.
			// // int fd1 = open("file1.txt", O_RDONLY);
			// int fd2 = open("file2.txt", O_RDONLY);

			// // ...

			// int newFd1 = dup(fd1);
			// int newFd2 = dup(fd2);

			// // Use newFd1 and newFd2 to operate on separate input streams

// Creating Pipelines: When constructing pipelines, where the output of one process is connected to the input of another, dup can be used to duplicate file descriptors and establish communication channels between processes.

				// int pipefd[2];
				// pipe(pipefd); // Create a pipe

				// int fdIn = open("input.txt", O_RDONLY);
				// int fdOut = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

				// dup2(fdIn, STDIN_FILENO);   // Redirect input from fdIn
				// dup2(fdOut, STDOUT_FILENO); // Redirect output to fdOut

				// // ...

				// dup2(pipefd[1], STDOUT_FILENO); // Redirect output to the write end of the pipe

				// // ...


















