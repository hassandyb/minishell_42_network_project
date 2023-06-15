
Useful resources :


https://github.com/kube/42homebrew

https://github.com/madebypixel02/minishell

###################################    readline function 

==>  return value s
The readline function does not return NULL in case of failure or end-of-file. Instead, it returns NULL only when the end of input is reached or an error occurs.

When you press Enter without typing anything, readline returns an empty string ('\0').


In the readline function, if an error occurs or the end of input is reached (e.g., when the user presses Ctrl+D to indicate end-of-file), the readline function returns NULL. By checking if input is not equal to NULL, the code can determine whether the readline function successfully obtained user input.

If input is not NULL, it means that the readline function was able to read input from the user, and the program can proceed to process and handle that input accordingly. This check ensures that the program does not attempt to use input when it has not been assigned a valid value.

On the other hand, if input is NULL, it indicates that an error occurred or the end of input was reached, and the program can handle this situation appropriately. In the provided code, the loop will exit, and the program will continue execution after the loop.

In summary, the check (input = readline(">> ")) != NULL is used to verify that the readline function successfully read user input and that the input variable contains a valid value before further processing is performed.



#################################################   Input redirection

1. Reading input from a file:
   ```
   $ cat < file.txt
   ```
   In this example, the `cat` command reads the contents of the `file.txt` file instead of waiting for user input. The output will be displayed on the terminal.

2. Chaining commands with input redirection:
   ```
   $ sort < input.txt > output.txt
   ```
   This command reads the contents of `input.txt` and sorts them using the `sort` command. The sorted output is then redirected to the `output.txt` file using the `>` symbol.

3. Combining input redirection with pipes:
   ```
   $ grep "error" < logfile.txt | sort > errors.txt
   ```
   In this example, the `grep` command reads the contents of `logfile.txt` and searches for lines containing the word "error". The output is then piped to the `sort` command and redirected to the `errors.txt` file.

4. Redirecting input from another command:
   ```
   $ echo "Hello, World!" | grep "Hello" | wc -l
   ```
   Here, the `echo` command outputs the text "Hello, World!". The output is piped to the `grep` command, which searches for lines containing the word "Hello". Finally, the output of `grep` is redirected to the `wc -l` command, which counts the number of lines in the input. In this case, the result will be 1.

These examples demonstrate how input redirection allows you to modify the source of input for a command, making it more flexible and powerful.


#################################################   Output Redirection 

1. Writing command output to a file:
   ```
   $ ls -l > file.txt
   ```
   In this example, the `ls -l` command lists the files and directories in the current directory, and the output is redirected to the `file.txt` file using the `>` symbol. The file `file.txt` will contain the output of the `ls -l` command.

2. Appending command output to a file:
   ```
   $ echo "Additional content" >> file.txt
   ```
   The `echo` command prints the text "Additional content", and the `>>` symbol is used to append the output to the `file.txt` file. If the file already exists, the output will be added to the end of the file without overwriting its existing content.

3. Discarding command output:
   ```
   $ make > /dev/null
   ```
   In this example, the `make` command is executed to build a project, but the output is discarded by redirecting it to the special file `/dev/null`. The `/dev/null` file is a system device that acts as a sink for data, essentially discarding anything written to it.

4. Piping command output to another command:
   ```
   $ ls | grep "txt" > text_files.txt
   ```
   Here, the `ls` command lists the files and directories in the current directory, and the output is piped to the `grep` command, which searches for lines containing the word "txt". The resulting output is then redirected to the `text_files.txt` file using the `>` symbol.

These examples demonstrate how output redirection allows you to control where the output of a command is directed, whether it's to a file, to another command for further processing, or even to a null device for discarding the output.

#################################################    Output redirection (Append mode)

1. Appending command output to a file:
   ```
   $ echo "Hello, World!" >> greetings.txt
   ```
   In this example, the `echo` command prints the text "Hello, World!", and the `>>` symbol is used to append the output to the `greetings.txt` file. If the file already exists, the output will be added to the end of the file without overwriting its existing content. If the file doesn't exist, a new file will be created.

2. Appending command output to a log file:
   ```
   $ date >> log.txt
   ```
   Here, the `date` command prints the current date and time. The `>>` symbol is used to append the output to the `log.txt` file. Each time this command is executed, the current date and time will be added as a new line at the end of the `log.txt` file.

3. Appending output from multiple commands to a file:
   ```
   $ echo "Error occurred!" >> error.log
   $ date >> error.log
   ```
   In this example, two commands are used. The first `echo` command prints the text "Error occurred!", and the output is appended to the `error.log` file using `>>`. The second `date` command prints the current date and time, which is also appended to the `error.log` file. Both outputs will be added as separate lines at the end of the file.

The `>>` symbol is useful when you want to continuously add new output to an existing file, such as log files or when you want to accumulate data over time without losing previous information. It ensures that the output is appended to the file rather than overwriting it.

readline function #######################################################

The `readline` function is a popular library function in Unix-like systems that allows you to read input from the user in a line-oriented manner. It provides a simple and convenient way to implement command line interfaces.

Here's a brief explanation of the `readline` function and some simple examples:

Function Signature:
```c
char *readline(const char *prompt);
```

Description:
The `readline` function reads a line of text from the user and returns a pointer to a dynamically allocated string containing the input. It also provides basic line editing capabilities, such as command history and editing of the current input line.

Example 1: Basic Input
```c
#include <stdio.h>
#include <readline/readline.h>

int main() {
    char *input = readline("Enter your name: ");
    printf("Hello, %s!\n", input);
    free(input);  // Free the dynamically allocated memory
    return 0;
}
```
In this example, the `readline` function is used to read a line of text from the user, prompting them to enter their name. The input is then displayed along with a greeting.

Example 2: Command History
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;
    while ((input = readline(">> ")) != NULL) {
        if (input[0] != '\0') {
            add_history(input);  // Add the input to command history
            printf("You entered: %s\n", input);
        }
        free(input);  // Free the dynamically allocated memory
    }
    return 0;
}
```
In this example, the `readline` function is used in a loop to continuously read lines of input from the user. The `add_history` function is used to add each non-empty input to the command history. The program will keep running until the user enters an empty line.

These examples demonstrate some basic usage of the `readline` function. You can explore the `readline` library further to discover more advanced features and customization options, such as input completion and keybindings.

Example 1: Basic Input and Output
```c
#include <stdio.h>
#include <readline/readline.h>

int main() {
    char *input = readline("Enter a number: ");
    int number = atoi(input); // Convert input to an integer
    printf("You entered: %d\n", number);
    free(input);
    return 0;
}
```
In this example, the user is prompted to enter a number. The input is then converted to an integer using `atoi` and displayed back to the user.

Example 2: Customizing the Prompt
```c
#include <stdio.h>
#include <readline/readline.h>

int main() {
    char *name = readline("What is your name? ");
    char *prompt = readline("Enter a prompt: ");

    printf("%s, welcome to the program!\n", name);
    printf("Your prompt is: %s\n", prompt);

    free(name);
    free(prompt);
    return 0;
}
```
In this example, the user is asked to enter their name and a custom prompt. The entered name is used to greet the user, and the custom prompt is displayed back to them.

Example 3: Reading Multiple Inputs
```c
#include <stdio.h>
#include <readline/readline.h>

int main() {
    char *input1 = readline("Enter the first number: ");
    char *input2 = readline("Enter the second number: ");

    int number1 = atoi(input1);
    int number2 = atoi(input2);
    int sum = number1 + number2;

    printf("The sum of %d and %d is: %d\n", number1, number2, sum);

    free(input1);
    free(input2);
    return 0;
}
```
In this example, the user is prompted to enter two numbers. The inputs are converted to integers, and their sum is calculated and displayed to the user.

These examples should give you a good starting point for using the `readline` function. Remember to free the dynamically allocated memory using `free` once you are done using the input obtained from `readline`.



rl_clear_history #################################################

The `rl_clear_history` function is part of the readline library and is used to clear the command history. It removes all previously entered commands from memory. Here's an explanation of the `rl_clear_history` function with a simple example:

Function Signature:
```c
void rl_clear_history(void);
```

Description:
The `rl_clear_history` function clears the command history, removing all previously entered commands. After calling this function, the history will be empty, and there will be no previously entered commands to retrieve.

Example:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    add_history("command 1");
    add_history("command 2");
    add_history("command 3");

    printf("Command history before clearing:\n");
    HIST_ENTRY **history_list = history_list();
    for (int i = 0; history_list[i] != NULL; i++) {
        printf("%s\n", history_list[i]->line);
    }

    rl_clear_history();

    printf("\nCommand history after clearing:\n");
    history_list = history_list();
    for (int i = 0; history_list[i] != NULL; i++) {
        printf("%s\n", history_list[i]->line);
    }

    return 0;
}
```
In this example, the `add_history` function is used to add three commands to the command history. We then print the command history before clearing it using `rl_clear_history`. After clearing, we print the command history again. The output will show that the history is empty after calling `rl_clear_history`.

Output:
```
Command history before clearing:
command 1
command 2
command 3

Command history after clearing:
```
As you can see, the command history is cleared, and there are no previously entered commands.

The `rl_clear_history` function is useful when you want to reset or clear the command history in your program. It allows you to start fresh with an empty history if needed.