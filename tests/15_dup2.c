

// #include <unistd.h>

// int dup2(int oldfd, int newfd);





#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// int main() {
//     int fd = open("file.txt", O_WRONLY); 



//     int newfd = dup2(fd, STDOUT_FILENO);  // Duplicate fd and assign it to STDOUT_FILENO

//     // Write to the redirected STDOUT
//     printf("This text will be written to the file.\n");

//     close(fd);

//     return 0;
// }


int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);


    // Duplicate the file descriptor for stdout (file descriptor 1) to the new file descriptor (fd).
    
	
	// dup2(fd, 1);
    // Now anything written to stdout will be redirected to "output.txt".
    // printf("This will be written to output.txt instead of the terminal.\n");
	
	
	dup2(fd, 0);
	scanf("Enter something :\n");
	
	close(fd);
    // Don't forget to close the file descriptor when it's no longer needed.
    close(fd);

    return 0;
}













