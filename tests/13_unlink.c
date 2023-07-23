


		// The unlink function in C is used to remove or delete a file from the file system. 
		// It allows you to delete a file by specifying its filename or path.




//   int unlink(const char *pathname);




#include <stdio.h>
#include <unistd.h>

int main() {
    const char *filename = "test";

    int r = unlink(filename);
    return 0;
}











