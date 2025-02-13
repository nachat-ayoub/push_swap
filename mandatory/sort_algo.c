/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:36:27 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 17:46:58 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	detect_comb(t_node *a, int size)
{
	int	diff;
	int	count;

	count = 0;
	while (a && a->next)
	{
		diff = a->index - a->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		a = a->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

static int	get_range(int size)
{
	if (size > 100)
		return (33);
	else
		return (16);
}

static void	semi_sort(t_node **a, t_node **b, int size)
{
	int	is_comb;
	int	range;
	int	i;

	range = get_range(size);
	is_comb = detect_comb(*a, size);
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
		else if (is_comb)
			rra(a, 1);
		else
			ra(a, 1);
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
