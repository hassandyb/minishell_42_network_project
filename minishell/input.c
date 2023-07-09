#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>

int main()
{
	while (1)
	{
		int fd = open("in.txt", O_RDONLY, 0666);
	if (fd == -1)
	{
		printf("error while open file\n");
		break;

	}
	dup2(fd, 0);
	close(fd);
	char arr[10];
	
	scanf("%s",arr);
	printf("%s", arr);
	}
	
	

}