/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:27:04 by anachat           #+#    #+#             */
/*   Updated: 2025/02/12 18:25:47 by anachat          ###   ########.fr       */
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
void	do_action(char *instr, t_node **a, t_node **b);
int		exec_ops(t_node **a, t_node **b);
char	*read_instr(void);
t_list	*add_operation(t_list *ops, char *instr);
int		run_ops(t_list **ops, t_node **a, t_node **b);
void	free_ops(t_list **ops);
int		is_valid_op(char *op);

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