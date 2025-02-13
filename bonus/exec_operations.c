/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:43 by anachat           #+#    #+#             */
/*   Updated: 2025/02/12 18:16:18 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_ops(t_node **a, t_node **b)
{
	char	*instr;
	t_list	*ops;
	t_list	*tmp;
	int		res;

	if (!a || !b)
		return (1);
	ops = NULL;
	instr = read_instr();
	while (instr)
	{
		tmp = add_operation(ops, instr);
		if (!tmp)
			return (free_ops(&ops), 1);
		ops = tmp;
		instr = read_instr();
	}
	res = run_ops(&ops, a, b);
	free_ops(&ops);
	return (res);
}

char	*read_instr(void)
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

t_list	*add_operation(t_list *ops, char *instr)
{
	t_list	*new;
	t_list	*curr;

	if (!is_valid_op(instr))
		return (free(instr), NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = instr;
	new->next = NULL;
	if (!ops)
		return (new);
	curr = ops;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (ops);
}

int	run_ops(t_list **ops, t_node **a, t_node **b)
{
	t_list	*curr;

	if (!ops || !*ops || !a || !b)
		return (1);
	curr = *ops;
	while (curr)
	{
		if (!curr->content)
			return (1);
		do_action(curr->content, a, b);
		curr = curr->next;
	}
	return (0);
}

void	free_ops(t_list **ops)
{
	t_list	*curr;
	t_list	*next;

	if (!ops || !*ops)
		return ;
	curr = *ops;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
	*ops = NULL;
}
