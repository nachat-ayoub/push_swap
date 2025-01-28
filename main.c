/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/01/28 18:29:13 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	ft_printf("We have %d argumets.\n", ac - 1);
	i = 0;
	while (ac > 1 && i < ac)
	{
		ft_printf("Arg N°%d:\n'%s'\n", ac, av[i]);
		i++;
	}
}
