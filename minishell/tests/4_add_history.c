


//           prototype   void rl_clear_history(void);

//The rl_clear_history function is used to clear the command history in the readline library. 
//It removes all previously entered commands from memory

// ==> In commands those are  working 
// cd /Users/hed-dyb/Desktop
// cd ~/Desktop
// cd $HOME/Desktop
// => In flags those are working 
// cd /Users/hed-dyb/Desktop
// cd $HOME/Desktop

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// cc  $(CFLAGS) 4_rl_clear_history.c

// CFLAGS = -Wall -Wextra -Werror 
	// -I/Users/hed-dyb/.brew/Cellar/readline/8.2.1/include/ 
	// -L/Users/hed-dyb/.brew/Cellar/readline/8.2.1/lib/ -lreadline





// The -I flag in the command you used (-I/Users/hed-dyb/.brew/Cellar/readline/8.2.1/include/) 
// specifies an additional directory to search for header files during the compilation process. 
// In this case, it tells the compiler to look for header files in the specified directory.

// The -L flag (-L/Users/hed-dyb/.brew/Cellar/readline/8.2.1/lib/) specifies an additional
//  directory to search for libraries during the linking process. By providing this flag, 
//  you're instructing the linker to search for libraries in the specified directory.


// -I (Stand for "Include"  )     flag helps  ==>  locate the necessary header files (e.g., readline.h history.h ...ext) , 
// -L (Stand for "Library"  )flag helps  ==>   find the library files (e.g., libreadline.a or libhistory.a ..ext).

// 1. Header Files:
//    - Header files (e.g., `readline.h`, `history.h`) contain function declarations, type definitions,
//     and other necessary information about functions, structures, constants, etc.
//    - They provide the interface or API (Application Programming Interface) for using a library.
//    - Header files are typically used during the compilation process to ensure that the program knows 
//    the correct function signatures and types when calling functions from a library.
//    - They are included in your C/C++ source code using the `#include` preprocessor directive.

// 2. Library Files:
//    - Library files (e.g., `libreadline.a`, `libhistory.so`) contain the compiled object code of 
// 	functions and other related data.
//    - They are created from the source code of a library and provide the implementation of 
//    the functions declared in the header files.
//    - Library files can be static (e.g., `libreadline.a`), which means the library code is 
//    directly linked into the final executable. Or they can be dynamic/shared (e.g., `libreadline.so`),
//     where the library code is loaded at runtime when the program starts.
//    - Library files are used during the linking process to combine object code from your program and 
//    the library code, creating the final executable.

// The Relationship:
// - Header files define the functions, types, and constants that are available in a library. 
// They act as an interface to the library.
// - Library files contain the actual implementation of the functions declared in the header files.
// - When you compile a program that uses a library, you need to include the appropriate 
// header files to ensure that the program knows the correct function signatures and types.
// - During the linking process, the linker looks for the library files specified with the `-L` flag 
// to resolve references to functions and symbols in the program.
// - The linker combines the object code from your program with the library code to create the final executable.

// In summary, header files provide the necessary declarations and definitions for using a library, while library files contain the compiled code for the implementation of those declarations. Together, they enable you to use functions and other features provided by external libraries in your program.






//Example 1: Clearing Command History


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
	char *line ;
	while(1)
    {
		line = readline("HERE> ");
        add_history(line);
    }


    return 0;
}




