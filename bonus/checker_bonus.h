/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:27:04 by anachat           #+#    #+#             */
/*   Updated: 2025/02/08 14:26:07 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_node	t_node;

struct s_node
{
	int		nbr;
	int		index;
	t_node	*next;
};

int		init_stack(t_node **a, char **nums);
t_node	*find_last(t_node *head);
long	ft_atoi_long(char *str);
void	free_2d_arr(char **arr);
void	free_stack(t_node **stack);
int		has_duplicated(t_node *stack);
int		lstsize(t_node *lst);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif