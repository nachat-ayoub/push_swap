/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:43:34 by anachat           #+#    #+#             */
/*   Updated: 2025/02/01 20:23:05 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_node **a, int log_instr)
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
	first->prev = last;
	
	second->prev = NULL;
	
	last->next = first;
	*a = second;
	if (log_instr)
		ft_printf("ra\n");
}

void rb(t_node **b, int log_instr)
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
	first->prev = last;
	
	second->prev = NULL;
	
	last->next = first;
	*b = second;
	if (log_instr)
		ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
