/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:29:20 by anachat           #+#    #+#             */
/*   Updated: 2025/02/04 12:52:26 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_node **stack)
{
	t_node *curr;

	curr = *stack;
	while (curr)
	{
		if (curr->next && curr->nbr > curr->next->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void sort_three(t_node **stack)
{
	t_node *first;
	t_node *second;
	t_node *third;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return;
	first = *stack;
	second = first->next;
	third = second->next;
	if (first->nbr > second->nbr && first->nbr > third->nbr)
		ra(stack, 1);
	else if (second->nbr > first->nbr && second->nbr > third->nbr)
		rra(stack, 1);
	if (!is_sorted(stack))
		sa(stack, 1);
}

void sort_four(t_node **a, t_node **b)
{
	int	pos;

	ft_index(*a);
	pos = get_pos(*a, 0);	
	while ((*a)->index != 0)
	{
		if (pos < 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}


void sort_five(t_node **a, t_node **b);
