


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





// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     // Source and destination directories
//     const char *srcDirectory = "/Users/hed-dyb/Desktop/tests";
//     const char *destDirectory = "/Users/hed-dyb/Desktop/tests/dir1";

//     // File name to move
//     const char *filename = "file.txt";

//     // Change current working directory to source directory
//     chdir(srcDirectory) ;

//     // Move the file from source directory to destination directory
//     rename(filename, destDirectory);

//     printf("File '%s' moved from '%s' to '%s'\n", filename, srcDirectory, destDirectory);

//     return 0;
// }







// changing file location using chdir 


// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     // Source and destination directories
//     const char *srcDirectory = "/Users/hed-dyb/Desktop/tests";
//     const char *destDirectory = "/Users/hed-dyb/Desktop/tests/dir1";

//     // File name to move
//     const char *filename = "file.txt";

//     // Change current working directory to source directory
//     chdir(srcDirectory);

//     // Move the file from source directory to destination directory
//     char destPath[4096];
//     // snprintf(destPath, sizeof(destPath), "%s/%s", destDirectory, filename);
//     rename(filename, destPath);

//     // printf("File '%s' moved from '%s' to '%s'\n", filename, srcDirectory, destPath);

//     return 0;
// }


//   




#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
	// 
	char **argv = malloc(3 * sizeof(char *));

	// argv[0] = "/bin/ls";// add bin here 
	// argv[1] = "-la";
	// argv[2] = NULL;

	// execve(argv[0], argv, NULL);





	argv[0] = "ls";// 
	argv[1] = "-la";
	argv[2] = NULL;

	execve("/bin/ls", argv, NULL);
    
}


