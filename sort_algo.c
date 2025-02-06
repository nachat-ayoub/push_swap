/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:36:27 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 14:46:12 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	semi_sort(t_node **a, t_node **b, int size)
{
	int	range;
	int	i;

	range = 16;
	if (size > 100)
		range = 33;
	i = 0;
	while (i < size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= (i + range))
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else
			rra(a, 1);
	}
}

void	sort_algo(t_node **a, t_node **b)
{
	int	max_pos;
	int	size;

	ft_index(*a);
	semi_sort(a, b, lstsize(*a));
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
	}
}
