/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:29:20 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 11:50:30 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack)
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

void	sort_three(t_node **stack)
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

void	sort_four(t_node **a, t_node **b)
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

void	sort_five(t_node **a, t_node **b)
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
	sort_four(a, b);
	pa(a, b);
}

void	sort_algo(t_node **a, t_node **b)
{
	int	i;
	int	size;
	int	range;

	ft_index(*a);
	size = lstsize(*a);
	if (size > 100)
		range = 33;
	else
		range = 16;
	i = 0;
	while (size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
			size--;
		}
		else if ((*a)->index <= (i + range))
		{
			pb(a, b);
			rb(b, 1);
			i++;
			size--;
		}
		else
			rra(a, 1);
	}
	int max_pos;
	while (*b)
	{
		max_pos = get_max_pos(*b);
		if (max_pos == 0)
			pa(a, b);
		else
		{
			size = lstsize(*b);
			if (max_pos <= (size / 2))
				rb(b, 1);
			else
				rrb(b, 1);
		}
		// print_stacks(*a, *b);
	}
}
