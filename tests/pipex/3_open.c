




# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>  
  #include <stdlib.h>






// int main() {
//     int fd = open("example.txt", O_WRONLY | O_CREAT| O_APPEND | 0644);

//     write(fd, "222222.\n", 10);

//     close(fd);
//     return 0;
// }


int main() 
{
    
	int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC);

    write(fd, "1111111.\n", 10);

    close(fd);

    return 0;
}
