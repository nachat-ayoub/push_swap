/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 11:39:13 by anachat          ###   ########.fr       */
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
		return (sa(a), 0);
	if (ft_strncmp(instr, "sb", 4) == 0)
		return (sb(b), 0);
	if (ft_strncmp(instr, "ss", 4) == 0)
		return (ss(a, b), 0);
	if (ft_strncmp(instr, "pb", 4) == 0)
		return (pb(a, b), 0);
	if (ft_strncmp(instr, "pa", 4) == 0)
		return (pa(a, b), 0);
	if (ft_strncmp(instr, "ra", 4) == 0)
		return (ra(a), 0);
	if (ft_strncmp(instr, "rb", 4) == 0)
		return (rb(b), 0);
	if (ft_strncmp(instr, "rr", 4) == 0)
		return (rr(a, b), 0);
	if (ft_strncmp(instr, "rra", 4) == 0)
		return (rra(a), 0);
	if (ft_strncmp(instr, "rrb", 4) == 0)
		return (rrb(b), 0);
	if (ft_strncmp(instr, "rrr", 4) == 0)
		return (rrr(a, b), 0);
	return (exit_program(), 1);
}

char	*read_instr()
{
	char	*instr;
	int		nl_idx;

	instr = get_next_line(0);
	if (instr)
	{
		nl_idx = ft_strlen(instr) - 1;
		if (instr[nl_idx] == '\n')
			instr[nl_idx] = '\0';
	}
	return (instr);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*instr;
	int		invalid;

	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (exit_program(), 1);
	if (!init_stack(&a, av + 1) || has_duplicated(a))
		return (free_stack(&a), exit_program(), 1);
	if (!is_sorted(&a))
	{
		instr = read_instr();
		while (instr)
		{
			invalid = do_action(instr, &a, &b);
			free(instr);
			if (invalid)
				return (free_stack(&a), free_stack(&b), 1);
			instr = read_instr();
		}
	}
	free_stack(&a);
	free_stack(&b);
	if (!is_sorted(&a))
		return (ft_printf("KO\n"), 1);
	ft_printf("OK\n");
}
