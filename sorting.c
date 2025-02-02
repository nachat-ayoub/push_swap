/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:29:20 by anachat           #+#    #+#             */
/*   Updated: 2025/02/02 18:03:43 by anachat          ###   ########.fr       */
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
    // If the first element is the largest, rotate the list.
    if (first->nbr > second->nbr && first->nbr > third->nbr)
        ra(stack, 1);
    // Else if the second element is the largest, reverse rotate.
    else if (second->nbr > first->nbr && second->nbr > third->nbr)
        rra(stack);

    // After moving the largest element to the bottom, if the list is still unsorted, swap.
    if (!is_sorted(stack))
        sa(stack, 1);
}

// [1, 2, 3] OK => [1, 2, 3]
// [2, 1, 3] OK => [1, 2, 3]
// [3, 1, 2] OK => [1, 2, 3] 
// [1, 3, 2] OK => [1, 2, 3] 
// [3, 2, 1] OK => [1, 2, 3] 
// [2, 3, 1] OK => [1, 2, 3] 
