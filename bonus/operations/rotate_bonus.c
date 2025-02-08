/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:34 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 11:14:38 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	last = find_last(*a);
	first->next = NULL;
	last->next = first;
	*a = second;
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	last = find_last(*b);
	first->next = NULL;
	last->next = first;
	*b = second;
}

void	rr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	ra(a);
	rb(b);
}
