/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:14:04 by anachat           #+#    #+#             */
/*   Updated: 2025/02/01 19:30:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_node **a, int log_instr)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*a = second;
	if (log_instr)
		ft_printf("sa\n");
}

void sb(t_node **b, int log_instr)
{
	t_node	*first;
	t_node	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*b = second;
	if (log_instr)
		ft_printf("sb\n");
}

void ss(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}
