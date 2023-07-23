

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













