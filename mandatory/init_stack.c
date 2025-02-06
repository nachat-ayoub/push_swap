/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:15:28 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 14:23:01 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

static int	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));
	if (!node)
		return (0);
	node->nbr = nbr;
	if (!*stack)
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

int	init_stack(t_node **a, char **args)
{
	char	**nums;
	long	nb;
	int		i;
	int		j;

	i = 0;
	while (args[i])
	{
		nums = ft_split(args[i], ' ');
		if (!nums)
			return (0);
		j = 0;
		while (nums[j])
		{
			nb = ft_atoi_long(nums[j]);
			if (nb == LONG_MAX)
				return (free_2d_arr(nums), free_stack(a), 0);
			if (!append_node(a, (int)nb))
				free_stack(a);
			j++;
		}
		free_2d_arr(nums);
		i++;
	}
	return (1);
}
