/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:55:29 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 11:14:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rra(t_node **a)
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
}

void	rrb(t_node **b)
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
}

void	rrr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rra(a);
	rrb(b);
}
