

#include <stdio.h>
#include <stdlib.h>

//Example of garbage collector


// whithout the garbage collector concept

// void ft_leaks(){ system ("leaks a.out");}
// int main ()
// {
// 	atexit(ft_leaks);
// 	char *p = malloc(50 * sizeof(char *));
// 	int *i = malloc(30 * sizeof(int));
// 	char **ptr = malloc(11 * sizeof(char *));
// }

// whith the garbage collector concept

typedef struct s_free
{
	void *ptr;
	struct s_free *next;
}t_free;

t_free *ft_create_node(void *p)
{
	t_free *node;

	node = malloc(sizeof(t_free));
	node->ptr = p;
	node->next = NULL;
	return node;
}

void ft_add_node(t_free **fad, t_free *node)
{
	t_free *temp = *fad;
	if(*fad == NULL)
		*fad = node;
	else
	{
		while(temp)
		{
			if(temp->next == NULL)
				break;
			temp = temp->next;
		}
		temp->next = node;
	}
}

void ft_free_nodes(t_free *f)
{
	while(f)
	{
		t_free *node_saver;
		node_saver = f;
		f = f->next;
		free(node_saver->ptr);
		free(node_saver);
	}

}

void ft_leaks(){ system ("leaks a.out");}
int main ()
{
	atexit(ft_leaks);
	t_free *f = NULL;
	char *p = malloc(50 * sizeof(char *));
	int *i = malloc(30 * sizeof(int));
	char **ptr = malloc(11 * sizeof(char *));
	
	ft_add_node(&f, ft_create_node(p));
	ft_add_node(&f, ft_create_node(i));
	ft_add_node(&f, ft_create_node(ptr));

	ft_free_nodes(f);

}




