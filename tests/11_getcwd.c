


//		 getcwd  ==>  get current working directory
//       char *getcwd(char *buf, size_t size);



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    char *buffer = malloc(4096);

    char *r = getcwd(buffer, 4096);
	if(r == NULL)
		printf("getcwd failed\n");
	else
    	printf("Current working directory: %s\n", buffer);
	free(buffer);
    return 0;
}














