/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:15:37 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 14:29:10 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	is_valid_nb(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[++i]))
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi_long(char *str)
{
	int		i;
	int		s;
	long	nb;

	if (!is_valid_nb(str))
		return (LONG_MAX);
	i = 0;
	s = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		if ((s == 1 && nb > INT_MAX) || (s == -1 && nb > -(long)INT_MIN))
			return (LONG_MAX);
		i++;
	}
	return (nb * s);
}

int	has_duplicated(t_node *stack)
{
	t_node	*curr_i;
	t_node	*curr_j;

	curr_i = stack;
	while (curr_i)
	{
		curr_j = curr_i->next;
		while (curr_j)
		{
			if (curr_i->nbr == curr_j->nbr)
				return (1);
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
	return (0);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
