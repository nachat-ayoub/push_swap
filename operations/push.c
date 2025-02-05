/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:23:35 by anachat           #+#    #+#             */
/*   Updated: 2025/02/01 12:01:31 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void pa(t_node **a, t_node **b)
{
	t_node *bhead;

	if (!b || !*b)
		return;
	bhead = *b;
	*b = (*b)->next;
	bhead->next = *a;
	*a = bhead;
	ft_printf("pa\n");
}

void pb(t_node **a, t_node **b)
{
	t_node *ahead;

	if (!a || !*a)
		return;
	ahead = *a;
	*a = (*a)->next;
	ahead->next = *b;
	*b = ahead;
	ft_printf("pb\n");
}
