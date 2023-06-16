
#include <readline/readline.h>
#include <stdlib.h>

//char *readline(const char *prompt);
int main ()
{
	while(1)
	{
		char *ptr = readline("\nEnter text :\n");
	}
}

// In the code you provided, when you press Ctrl + D, you see ^D being displayed on the terminal. 
//This is the default behavior of the terminal when it receives an end-of-file (EOF) character.

//In Unix-like systems, including Linux, pressing Ctrl + D at the beginning of a line in the 
//terminal indicates the end of input or the end of a file. The ^D symbol represents the EOF character 
//in the terminal's output.

//When you press Ctrl + D, it sends the EOF character to the input stream,
//and readline() interprets it as the end of input. Therefore, the program continues executing, 
//and you don't see any further output or action.







