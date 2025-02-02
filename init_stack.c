/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:15:28 by anachat           #+#    #+#             */
/*   Updated: 2025/02/02 12:28:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *head)
{
	t_node *curr;

	curr = head;
	while(curr->next)
		curr = curr->next;
	return (curr);
}

static void	append_node(t_node **stack, int nbr)
{
	t_node *node;
	t_node *last_node;

	if (!stack) // exit
		return ;
	node = malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));
	if (!node)
		return ;
	node->nbr = nbr;
	if (!*stack) // list is empty (first node to add will be head)
		*stack = node;
	else
	{ // put the node at the end
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
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
			ft_printf("[nb] = %d\n", nb);
			if (nb == LONG_MAX)
				return (free_2d_arr((void **)nums), 0);
			append_node(a, (int)nb);
			j++;
		}
		free_2d_arr((void **)nums);
		i++;
	}
	return (1);
}
