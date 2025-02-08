/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 14:58:23 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (exit_program(), 1);
	if (!init_stack(&a, av + 1) || has_duplicated(a))
		return (free_stack(&a), exit_program(), 1);
	if (!is_sorted(&a))
	{
		size = lstsize(a);
		if (size == 3)
			sort_three(&a);
		else if (size == 4)
			sort_four(&a, &b);
		else if (size == 5)
			sort_five(&a, &b);
		else
			sort_algo(&a, &b);
	}
	free_stack(&a);
}
