/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/07 20:37:07 by anachat          ###   ########.fr       */
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

	curr = *stack;
	while (curr)
	{
		if (curr->next && curr->nbr > curr->next->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static 	int do_action(char *instr, t_node **a, t_node **b)
{
	if (ft_strncmp(instr, "sa", 4) == 0)
		return (sa(a, 1), 0);
	if (ft_strncmp(instr, "sb", 4) == 0)
		return (sb(b, 1), 0);
	if (ft_strncmp(instr, "ss", 4) == 0)
		return (ss(a, b), 0);
	if (ft_strncmp(instr, "pb", 4) == 0)
		return (pb(a, b), 0);
	if (ft_strncmp(instr, "pa", 4) == 0)
		return (pa(a, b), 0);
	if (ft_strncmp(instr, "ra", 4) == 0)
		return (ra(a, 1), 0);
	if (ft_strncmp(instr, "rb", 4) == 0)
		return (rb(b, 1), 0);
	if (ft_strncmp(instr, "rr", 4) == 0)
		return (rr(a, b), 0);
	if (ft_strncmp(instr, "rra", 4) == 0)
		return (rra(a, 1), 0);
	if (ft_strncmp(instr, "rrb", 4) == 0)
		return (rrb(b, 1), 0);
	if (ft_strncmp(instr, "rrr", 4) == 0)
		return (rrr(a, b), 0);
	return (0);
}

static 	int process_action(char *instr, t_node **a, t_node **b)
{
	if (ft_strncmp(instr, "sa", 4) != 0 && ft_strncmp(instr, "sb", 4) != 0
		&& ft_strncmp(instr, "ss", 4) != 0 && ft_strncmp(instr, "pb", 4) != 0
		&& ft_strncmp(instr, "pa", 4) != 0 && ft_strncmp(instr, "ra", 4) != 0
		&& ft_strncmp(instr, "rb", 4) != 0 && ft_strncmp(instr, "rr", 4) != 0
		&& ft_strncmp(instr, "rra", 4) != 0 && ft_strncmp(instr, "rrb", 4) != 0
		&& ft_strncmp(instr, "rrr", 4) != 0)
	{
		free_stack(a);
		free_stack(b);
		return (free(instr), exit_program(), 1);
	}
	do_action(instr, a, b);
	return (0);
}


int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*instr;

	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (exit_program(), 1);
	if (!init_stack(&a, av + 1) || has_duplicated(a))
		return (free_stack(&a), exit_program(), 1);
	if (!is_sorted(&a))
	{
		instr = get_next_line(0);
		if (instr[ft_strlen(instr) - 1] == '\n')
			instr[ft_strlen(instr) - 1] = '\0';
		process_action(instr, &a, &b);
		while (instr)
		{
			instr = get_next_line(0);
			process_action(instr, &a, &b);
			free(instr);
		}
	}
	free_stack(&a);
	if (!is_sorted(&a))
		return (ft_printf("KO\n"), 1);
	ft_printf("OK\n");
}
