


//  int chdir(const char *path);



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// int main() {
//     const char *path = "/Users/hed-dyb/Desktop";

//     if (chdir(path) == 0) {
//         printf("Current working directory changed to: %s\n", path);
//     } else {
//         perror("chdir");
//         return 1;
//     }

//     return 0;
// }

// int main ()
// {
// 	char buffer[1024];

// 	if(getcwd(buffer, 1024) == NULL)
// 	{
// 		printf("getcwd failed\n");
// 		return 1;
// 	}
// 	printf("Current working directory : %s\n\n", buffer);

// 	char *newdir = "/Users/hed-dyb/Desktop";
	
// 	int r = chdir(newdir);
// 	if(r == -1)
// 	{
// 		printf("chdir failed!\n");
// 		return (0);
// 	}

// 	if(getcwd(buffer, 1024) == NULL)
// 	{
// 		printf("getcwd failed\n");
// 		return 1;
// 	}
// 	printf("Current working directory : %s\n\n", buffer);

// }

// int main()
// {
// int fd = open ("file.txt", O_RDONLY);
// char *buffer = malloc(4);
// read(fd, buffer, 3);

// printf("%s\n", buffer);
// buffer[0] = '\0';

// // close(fd);
// // unclose(fd);
// // fd = open ("file.txt", O_RDONLY);


// read(fd, buffer, 3);
// buffer[3] = '\0';
// printf("%s\n", buffer);

// free(buffer);
// }






