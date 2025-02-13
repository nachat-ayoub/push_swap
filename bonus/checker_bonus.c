/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/12 18:23:51 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	exit_program(void)
{
	ft_putstr_fd("Error\n", 2);
}

static int	is_sorted(t_node **stack)
{
	t_node	*curr;

	if (!stack || !*stack)
		return (0);
	curr = *stack;
	while (curr)
	{
		if (curr->next && curr->nbr > curr->next->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_valid_op(char *op)
{
	if (ft_strncmp(op, "sa", 4) == 0)
		return (1);
	if (ft_strncmp(op, "sb", 4) == 0)
		return (1);
	if (ft_strncmp(op, "ss", 4) == 0)
		return (1);
	if (ft_strncmp(op, "pb", 4) == 0)
		return (1);
	if (ft_strncmp(op, "pa", 4) == 0)
		return (1);
	if (ft_strncmp(op, "ra", 4) == 0)
		return (1);
	if (ft_strncmp(op, "rb", 4) == 0)
		return (1);
	if (ft_strncmp(op, "rr", 4) == 0)
		return (1);
	if (ft_strncmp(op, "rra", 4) == 0)
		return (1);
	if (ft_strncmp(op, "rrb", 4) == 0)
		return (1);
	if (ft_strncmp(op, "rrr", 4) == 0)
		return (1);
	return (exit_program(), 0);
}

void	do_action(char *instr, t_node **a, t_node **b)
{
	if (ft_strncmp(instr, "sa", 4) == 0)
		sa(a);
	if (ft_strncmp(instr, "sb", 4) == 0)
		sb(b);
	if (ft_strncmp(instr, "ss", 4) == 0)
		ss(a, b);
	if (ft_strncmp(instr, "pb", 4) == 0)
		pb(a, b);
	if (ft_strncmp(instr, "pa", 4) == 0)
		pa(a, b);
	if (ft_strncmp(instr, "ra", 4) == 0)
		ra(a);
	if (ft_strncmp(instr, "rb", 4) == 0)
		rb(b);
	if (ft_strncmp(instr, "rr", 4) == 0)
		rr(a, b);
	if (ft_strncmp(instr, "rra", 4) == 0)
		rra(a);
	if (ft_strncmp(instr, "rrb", 4) == 0)
		rrb(b);
	if (ft_strncmp(instr, "rrr", 4) == 0)
		rrr(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2 && !av[1][0])
		return (exit_program(), 1);
	if (!init_stack(&a, av + 1) || has_duplicated(a))
		return (free_stack(&a), exit_program(), 1);
	if (exec_ops(&a, &b))
		return (free_stack(&a), free_stack(&b), 0);
	if (is_sorted(&a) && lstsize(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_stack(&a), free_stack(&b), 0);
}
