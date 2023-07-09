
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>





int main() {
  int fd = open("file.txt", O_RDONLY);
  int newfd = dup(fd);

  // Use both file descriptors to read from the file.
  char buf1[10], buf2[10];
  read(fd, buf1, 10);
  read(newfd, buf2, 10);
  printf("%s\n%s\n", buf1, buf2);

  close(fd);
  close(newfd);

  return 0;
}
