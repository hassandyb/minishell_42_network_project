


//           prototype   void rl_clear_history(void);

//The rl_clear_history function is used to clear the command history in the readline library. 
//It removes all previously entered commands from memory


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// cc  $(CFLAGS) 4_rl_clear_history.c

// CFLAGS = -Wall -Wextra -Werror -I/Users/hed-dyb/.brew/Cellar/readline/8.2.1/include/ -L/Users/hed-dyb/.brew/Cellar/readline/8.2.1/lib/ -lreadline


//Example 1: Clearing Command History


int main() {
    add_history("command 1");
    add_history("command 2");
    add_history("command 3");

    printf("Command history before clearing:\n");
    for (int i = 0; i < history_length; i++) {
        printf("%s\n", history_get(i)->line);
    }

    rl_clear_history();

    printf("\nCommand history after clearing:\n");
    for (int i = 0; i < history_length; i++) {
        printf("%s\n", history_get(i)->line);
    }

    return 0;
}



