
		// int access(const char *pathname, int mode);

		// On success, it returns 0,
		// On failure, it returns -1,


		// mode: This is an integer that specifies the access mode. It can be one of the following constants defined in <unistd.h>:

		// F_OK: Used to check if the file or directory exists.
		// R_OK: Used to check if the file or directory is readable.
		// W_OK: Used to check if the file or directory is writable.
		// X_OK: Used to check if the file or directory is executable.





#include <stdio.h>
#include <unistd.h>

// int main() {
//     // const char *pathname = "/Users/hed-dyb/Desktop/tests/file.txt";
//     const char *pathname = "file.txt";// file.txt" exists in the same directory where the code is located
//     int mode = R_OK | W_OK;
//     // int mode = X_OK;

//     if (access(pathname, mode) == 0) {
//         printf("File is readable and writable.\n");
//     } else {
//         perror("access");
//         return 1;
//     }

//     return 0;
// }

//_________________________________

// int main ()
// {
// 	const char *pathname = "file.txt";

// 	if(access (pathname, F_OK) == 0)
// 		printf("the file does exist\n");
// 	if(access (pathname, R_OK) == 0)
// 		printf("the file is readable\n");
// 	if(access (pathname, W_OK) == 0)
// 		printf("the file is writable\n");
// 	if(access (pathname, X_OK) == 0)
// 		printf("the file is executable\n");
	
// }
//_________________________________






