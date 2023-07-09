
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


// example 1
// int main() {
//     int file = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     int copy = dup(file); // Duplicate file descriptor

//     // Write to the original and duplicated file descriptors
//     int i = 0;
//     while(i++ < 4)
//     {
//       write(file, "Hello, original!\n", 17);
//       write(copy, "Hello, copy!\n", 13);
//     }
      

//     close(file);
//     close(copy);
    
//     return 0;
// }

//example 2
// int main ()
// {
//   int fd = open("file.txt", O_RDONLY, 0777);
//   int copy = dup(fd);
//   char arr1[10];
//   char arr2[10];
//   read(fd, arr1, 2);
//   read(copy, arr2, 2);
//   arr1[2] = '\0';
//   arr2[2] = '\0';

//   printf("%s\n%s\n", arr1, arr2);
//   arr1[0] = '\0';
//   arr2[0] = '\0';

//   close(fd);
//   close(copy);

//   read(fd, arr1, 2);
//   read(copy, arr2, 2);
  
//   arr1[2] = '\0';
//   arr2[2] = '\0';

//     printf("%s\n%s\n", arr1, arr2);
// }

//example 3 ==>dup 2 is used to change the strdout fd


// int main() {
//     int file = open("file.txt", O_WRONLY , 0777);
//     int stdout_copy = dup2(file, STDOUT_FILENO); // Redirect stdout to the file

//     printf("This will be written to the file.\n");

//     close(file);
    
//     return 0;
// }

// int main ()
// {
//   // int fd =  open("file.txt", O_WRONLY , 0777);
//   int fd =  open("file.txt", O_WRONLY , O_TRUNC,0777);
//   dup2(fd, STDOUT_FILENO);
//   printf("something ....\n");
//   close (fd);
// }

//examplemaking dup/dup2 usful

//Redirecting Standard Output to a File:

// int main() {
//     int file = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     int stdout_copy = dup2(file, STDOUT_FILENO); // Redirect stdout to the file

//     printf("This will be written to the file.\n");

//     close(file);
    
//     return 0;
// }










