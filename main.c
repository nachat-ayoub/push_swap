#include "push_swap.h"

int main (int ac, char **av)
{
	ft_printf("We have %d argumets.\n", ac - 1);
	int i  = 1;
	while (ac > 1 && i < ac)
	{
		ft_printf("Arg N°%d:\n'%s'\n", ac, av[i]);
		i++;
	}
}