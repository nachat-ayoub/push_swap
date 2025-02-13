/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/12 11:59:55 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static char	*read_instr(void)
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

int	add_line(char ***ops, char *line, int size)
{
	char	**new_ops;
	int		i;

	new_ops = malloc(sizeof(char *) * (size + 2));
	if (!new_ops)
		return (free(line), 0);
	i = 0;
	while (i < size)
	{
		new_ops[i] = (*ops)[i];
		i++;
	}
	new_ops[size] = line;
	new_ops[size + 1] = NULL;
	free(*ops);
	*ops = new_ops;
	return (1);
}

char **read_ops(void)
{
	char	**ops;
	char	*instr;
	int		count;

	count = 1;
	ops = malloc(sizeof(char *) * (count + 1));
	if (!ops)
		return (NULL);
	instr = read_instr();
	if (!instr)
		return (free(ops), NULL);
	while (instr)
	{
		if (!is_valid_instr(instr))
			return (free(instr), free_2d_arr(ops), NULL); // 82
		if (!add_line(&ops, instr, count))
			return (free(instr), free_2d_arr(ops), NULL);
		count++;
		instr = read_instr();
	}
	return (ops);
}

int exec_operations(t_node **a, t_node **b)
{
	char	**ops;
	int		i;

	i = 0;
	ops = read_ops(); // 97
	if (!ops)
		return (1);
	while (ops[i])
	{
		do_action(ops[i], a, b);
		i++;
	}
	free_2d_arr(ops);
	return (0);
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
	if (exec_operations(&a, &b)) // 122
		return (free_stack(&a), free_stack(&b), 0);
	if (is_sorted(&a) && lstsize(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_stack(&a), free_stack(&b), 0);
}
