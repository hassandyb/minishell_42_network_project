

				// #include <unistd.h>

				// char *ttyname(int fd);

// return 
// != NULL      string containing the terminal name ; 

// == NULL   he file descriptor is not associated with a terminal.







#include <stdio.h>
#include <unistd.h>


//       predefined constants in C - <unistd.h>
		// STDERR_FILENO

		// STDIN_FILENO

		// STDOUT_FILENO


int main() {
    // int fd = STDOUT_FILENO; // Use the standard input file descriptor (0)
	int fd = 1;

    // Check if the file descriptor is associated with a terminal
    if (isatty(fd)) {
        char *terminal_name = ttyname(fd);
        if (terminal_name) {
            printf("Terminal name: %s\n", terminal_name);
        } else {
            perror("ttyname");
            return 1;
        }
    } else {
        printf("File descriptor %d is not associated with a terminal.\n", fd);
    }
    return 0;
}




















