/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 16:36:29 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stacks(t_node *a, t_node *b)
// {
// 	int pos = 0;
// 	ft_printf(YELLOW "\n=========================================\n" RESET);
// 	ft_printf(YELLOW "Stack A                   Stack B\n" RESET);
// 	ft_printf(PURPLE "pos  idx  num          pos  idx  num\n" RESET);
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			ft_printf(DIM_YELLOW "[%d]" RESET, pos);
// 			ft_printf("  %d    ", a->index);
// 			ft_printf(DIM_RED "%d            " RESET, a->nbr);
// 		}
// 		else
// 			ft_printf("                       ");
// 		if (b)
// 		{
// 			ft_printf(DIM_YELLOW "[%d]" RESET, pos);
// 			ft_printf("  %d    ", b->index);
// 			ft_printf(DIM_RED "%d" RESET, b->nbr);
// 		}
// 		ft_printf("\n");
// 		if (a) a = a->next;
// 		if (b) b = b->next;
// 		pos++;
// 	}
// 	ft_printf(YELLOW "=========================================\n\n" RESET);
// }

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;

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
