
// char *readline(const char *prompt);





#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

//example 1
// int main() {
//     char *input = readline("");
//     printf("Hello, %s!\n", input);
//     free(input);  // Free the dynamically allocated memory
//     return 0;
// }

// int main ()
// {
//     char *ptr = readline("enter something that readline will save :");
//     printf("%s", ptr);
//     free(ptr);
//     return (0);
// }



// example 2


// int main() {
//     char *name = readline("What is your name? ");
//     char *prompt = readline("Enter a prompt: ");

//     printf("%s, welcome to the program!\n", name);
//     printf("Your prompt is: %s\n", prompt);

//     free(name);
//     free(prompt);
//     return 0;
// }

// int main ()
// {
//     char *data1 = readline("Enter your name : ");
//     char *data2 = readline("Enter your age : ");
//     char *data3 = readline("Enter your location : ");
//     char *data4 = readline("Enter your status : ");
//     char *data5 = readline("Enter your school name : ");
//     printf("\n\nHi %s, Your age is %s, Your curent location is %s, and your a is %s, and your school is %s", data1, data2, data3, data4, data5);
// }

// example 3  

#include <readline/history.h>

// int main() {
//     char *input;
//     while ((input = readline(">> ")) != NULL) {
//         if (input[0] != '\0') {
//             add_history(input);  // Add the input to command history
//             printf("You entered: %s\n", input);
//         }
//         free(input);  // Free the dynamically allocated memory
//     }
//     return 0;
// }

int main() {
    char *input = readline("");
	if(input == NULL)
		printf("NULL\n");
	else if(input[0] == '\0')
		printf("Empty file\n");
	else
    	printf("Hello, %s!\n", input);
    free(input);  // Free the dynamically allocated memory
    return 0;
}








