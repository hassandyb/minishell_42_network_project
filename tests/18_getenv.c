

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char *username = getenv("eco");
    if (username != NULL) 
	{
        printf("Hello, %s!\n", username);
    } 
	else {
        printf("Hello, unknown user!\n");
    }

    return 0;
}
