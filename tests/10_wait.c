


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// int main() {
//     pid_t child_pid = fork();

// 	if (child_pid == 0) {
//         // Child process
//         printf("Child process executing...\n");
//         sleep(2);
//         printf("Child process exiting...\n");
//         return 123;
//     } 
// 	else 
// 	{
//         // Parent process
//         printf("Parent process waiting for child...\n");
//         wait(NULL);
//         printf("Child process finished.\n");
//     }

//     return 0;
// }





#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child process executing...\n");
        sleep(8);
        printf("Child process exiting...\n");
        return 123;
    } else {
        // Parent process
        printf("Parent process waiting for child...\n");
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}



