/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:27 by anachat           #+#    #+#             */
/*   Updated: 2025/02/09 17:52:48 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exit_program(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	is_valid_instr(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "sa", 4) == 0)
		return (1);
	if (ft_strncmp(str, "sb", 4) == 0)
		return (1);
	if (ft_strncmp(str, "ss", 4) == 0)
		return (1);
	if (ft_strncmp(str, "pb", 4) == 0)
		return (1);
	if (ft_strncmp(str, "pa", 4) == 0)
		return (1);
	if (ft_strncmp(str, "ra", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rb", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rr", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rra", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rrb", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rrr", 4) == 0)
		return (1);
	return (exit_program(), 0);
}

void	do_action(char *instr, t_node **a, t_node **b)
{
	if (ft_strncmp(instr, "sa", 4) == 0)
		sa(a);
	else if (ft_strncmp(instr, "sb", 4) == 0)
		sb(b);
	else if (ft_strncmp(instr, "ss", 4) == 0)
		ss(a, b);
	else if (ft_strncmp(instr, "pb", 4) == 0)
		pb(a, b);
	else if (ft_strncmp(instr, "pa", 4) == 0)
		pa(a, b);
	else if (ft_strncmp(instr, "ra", 4) == 0)
		ra(a);
	else if (ft_strncmp(instr, "rb", 4) == 0)
		rb(b);
	else if (ft_strncmp(instr, "rr", 4) == 0)
		rr(a, b);
	else if (ft_strncmp(instr, "rra", 4) == 0)
		rra(a);
	else if (ft_strncmp(instr, "rrb", 4) == 0)
		rrb(b);
	else if (ft_strncmp(instr, "rrr", 4) == 0)
		rrr(a, b);
}
