








// int execve(const char *pathname, char *const argv[], char *const envp[]);



// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     // char *argv[] = { "ls", "-l", NULL };
//     // char *argv[] = { "ls", NULL };
//     char *argv[] = { "echo", "hassan", NULL };
//     char *envp[] = { NULL };

// 	execve("/bin/echo", argv, envp);
//     // if (execve("/bin/", argv, envp) == -1) {
//     //     perror("execve");
//     //     return 1;
//     // }

//     // This code will only execute if execve fails.
//     printf("This line won't be reached.\n");

//     return 0;
// }

//____________________________________________

#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = { "ls", NULL };
    char *envp[] = { NULL };

    // execve("/bin/echo", argv, envp);
    execve("ls", argv, envp);

    // This code will only execute if execve fails.
    printf("This line won't be reached.\n");

    return 0;
}








