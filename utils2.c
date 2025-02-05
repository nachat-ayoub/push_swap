/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:49:57 by anachat           #+#    #+#             */
/*   Updated: 2025/02/04 16:37:10 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index(t_node *s)
{
	t_node *curr_i;
	t_node *curr_j;

	if (!s)
		return ;
	curr_i = s;
	while (curr_i)
	{
		curr_i->index = 0;
		curr_j = s;
		while (curr_j)
		{
			if (curr_i->nbr > curr_j->nbr)
				curr_i->index++;
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
}

int	lstsize(t_node *lst)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = (*curr).next;
		i++;
	}
	return (i);
}

int	get_pos(t_node *stack, int index)
{
	int pos = 0;

	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int get_max_pos(t_node *stack)
{
	int pos = 0;
	int max_pos = 0;
	int idx = 0;
	ft_index(stack);

	while (stack)
	{
		if (stack->index > idx)
		{
			idx = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}