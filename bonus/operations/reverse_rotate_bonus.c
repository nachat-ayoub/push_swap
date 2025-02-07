/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:55:29 by anachat           #+#    #+#             */
/*   Updated: 2025/02/07 18:16:27 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rra(t_node **a, int log_instr)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = find_last(*a);
	before_last = *a;
	while (before_last->next != last)
		before_last = before_last->next;
	last->next = first;
	before_last->next = NULL;
	*a = last;
	if (log_instr)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int log_instr)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = find_last(*b);
	before_last = *b;
	while (before_last->next != last)
		before_last = before_last->next;
	last->next = first;
	before_last->next = NULL;
	*b = last;
	if (log_instr)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
