
#include <stdio.h>
#include <unistd.h>

// int main ()
// {
//     int fd[2];
//     pipe(fd);

//     int pid = fork();
    
//     if(pid != 0)//chaild process
//     {
//         dup2(fd[1], 1);// changing standared out put
//         write(1, "Message : Hi from the parent process", 37);
//     }
//     else
//     {
//         dup2(fd[0], 0);
//         char buffer[100];
//         int l = read(0, buffer, 100);
//         buffer[l] = '\0';
//         printf("%s\n", buffer);
//     }
// }


#include <libc.h>
// int main ()
// {
//     int fd[2];
//     pipe(fd);

//     char *s[2] = {"ls",NULL};
//     if (!fork())
//         execve("/bin/ls",s , NULL);
//     puts("hello");
// }


int main(int argc, char const *argv[])
{
    int fd[2];
    pipe(fd);

    char *s[2] = {"ls",NULL};
    if (!fork())
    {
        dup2(fd[1], 1);
        execve("/bin/ls",s , NULL);
    }
    wait(NULL);
    char buffer[100];
    int l = read(fd[0], buffer, 100);
    buffer[l] = '\0';
    printf("%s\n", buffer);
    return 0;
}
