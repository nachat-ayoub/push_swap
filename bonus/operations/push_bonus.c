/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:23:35 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 11:14:00 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*bhead;

	if (!b || !*b)
		return ;
	bhead = *b;
	*b = (*b)->next;
	bhead->next = *a;
	*a = bhead;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*ahead;

	if (!a || !*a)
		return ;
	ahead = *a;
	*a = (*a)->next;
	ahead->next = *b;
	*b = ahead;
}
