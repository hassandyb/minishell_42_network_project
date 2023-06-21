
//example   1   you will see leaks
// #include <stdio.h>
// #include <stdlib.h>

// void ft_leaks (){system("leaks a.out");}

// int main ()
// {
// 	atexit(ft_leaks);
// 	char **p = malloc(5 * sizeof(char *));
// 	char *ptr = malloc (7 * sizeof(char));
// }


//example   2  you will not see leaks
// #include <stdio.h>
// #include <stdlib.h>
// char **p;
// char *ptr;

// void ft_leaks (){system("leaks a.out");}

// int main ()
// {
// 	atexit(ft_leaks);
// 	p = malloc(5 * sizeof(char *));
// 	ptr = malloc (7 * sizeof(char));
// }


// example 3  you will see leaks


// #include <stdio.h>
// #include <stdlib.h>

// void ft_allocate(char **p, char *ptr)
// {
// 	p = malloc(5 * sizeof(char *));
// 	ptr = malloc (7 * sizeof(char));
// }
// void ft_leaks (){system("leaks a.out");}

// int main ()
// {
// 	char **p;
// 	char *ptr;
// 	atexit(ft_leaks);
// 	ft_allocate(p, ptr);


// }

//example   4  when you add exit (0) the program terminated befor ft_leaks will be called, so there actually, but 
// the compilation gives no leaks cause the program ends befor atexit fiunction will be called

// void ft_allocate(char **p, char *ptr)
// {
// 	p = malloc(5 * sizeof(char *));
// 	ptr = malloc (7 * sizeof(char));
// 	exit(0);
// }
// void ft_leaks (){system("leaks a.out");}

// int main ()
// {
// 	char **p;
// 	char *ptr;
// 	atexit(ft_leaks);
// 	// ft_allocate(p, ptr);
// 	p = malloc(5 * sizeof(char *));
// 	ptr = malloc (7 * sizeof(char));
// 	exit(0);
	

// }
// By adding the exit(0) function call at the end of the main function, you explicitly terminate the program execution. When exit(0) is called, it immediately terminates the program without executing any further code.

// In your case, when you call exit(0) after allocating memory for p and ptr, the program terminates before reaching the end of the main function. As a result, the atexit(ft_leaks) function, which registers the ft_leaks function to be called at program exit, does not get a chance to execute.

// Since the ft_leaks function is not executed, the system("leaks a.out") command, which checks for memory leaks, is not invoked. Therefore, you do not see any memory leaks reported.

// It's important to note that although calling exit(0) can prevent memory leak detection in this specific scenario, it is not a recommended solution. Proper memory management, including freeing allocated memory, is crucial in C programs to avoid memory leaks.





