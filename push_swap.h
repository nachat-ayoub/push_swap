/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:27:04 by anachat           #+#    #+#             */
/*   Updated: 2025/02/04 12:41:07 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>

# define RED   "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_node t_node;

struct s_node
{
	int		nbr;
	int		index;
	int		push_cost;
	int		above_median;
	int		cheapest;
	t_node	*target_node;
	t_node	*next;
	t_node	*prev;
};

void	exit_program();
int		init_stack(t_node **a, char **nums);
t_node	*find_last(t_node *head);
long	ft_atoi_long(char *str);
void	free_2d_arr(void **arr);
void	free_stack(t_node **stack);
int		has_duplicated(t_node *stack);
int 	is_sorted(t_node **stack);
void	sort_three(t_node **stack);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	ft_index(t_node *s);
int		lstsize(t_node *lst);
int		get_pos(t_node *stack, int index);

// Operations:
void	sa(t_node **a, int log_instr);
void	sb(t_node **b, int log_instr);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a, int log_instr);
void	rb(t_node **b, int log_instr);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a, int log_instr);
void	rrb(t_node **b, int log_instr);
void	rrr(t_node **a, t_node **b);


#endif
