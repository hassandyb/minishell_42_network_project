#include <stdio.h>

int main(int argc, char **argv, char **ev)
{
	int i = -1;
	while(argv[++i])
		printf("%s\n", argv[i]);
	printf("\n\n");

	i = -1;
	while(ev[++i])
		printf("%s\n", ev[i]);
}

// t_env
// {
// 	char *key;//befor ==
// 	char *value //after ==
// 	struct ... next
// }
// t_env *ft_function (ev)
// {
// 	//
// }