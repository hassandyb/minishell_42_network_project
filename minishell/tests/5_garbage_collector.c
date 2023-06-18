

#include <stdio.h>
#include <stdlib.h>

//Example of garbage collector


// whithout the garbage collector concept

void ft_leaks(){ system ("leaks a.out");}
int main ()
{
	atexit(ft_leaks);
	char *p = malloc(50 * sizeof(char *));
	int *i = malloc(30 * sizeof(int));
	char **ptr = malloc(11 * sizeof(char *));
}

// whith the garbage collector concept

typedef struct s_free
{
	void *ptr;
	struct t_free *next;
}t_free;

void ft_leaks(){ system ("leaks a.out");}
int main ()
{
	atexit(ft_leaks);
	t_free *f;
	char *p = malloc(50 * sizeof(char *));
	int *i = malloc(30 * sizeof(int));
	char **ptr = malloc(11 * sizeof(char *));
	ft_create_node(f, p);
	ft_add

}




