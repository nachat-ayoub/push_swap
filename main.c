/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/02/04 12:31:14 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node
t_node *new_node(int nbr)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->nbr = nbr;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// Function to generate a doubly linked list with 3 nodes
t_node *generate_list()
{
	t_node *b = new_node(1);
	t_node *c = new_node(2);
	t_node *d = new_node(3);

	if (!b || !c || !d)
		return NULL;

	// Link the nodes forward
	b->next = c;
	c->next = d;

	// Link the nodes backward
	d->prev = c;
	c->prev = b;

	return b; // Return the head of the list
}

// Function to print the doubly linked list
void print_list(t_node *head)
{
	t_node *curr = head;
	ft_printf("\nNode List:\n");
	while (curr != NULL) {
		ft_printf(RED "[i: %d] " RESET, curr->index);
		ft_printf("n: %d\n", curr->nbr);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;

	(void)a;
	(void)b;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (exit_program(), 1);
	if (init_stack(&a, av + 1) == 0 || has_duplicated(a))
		return (free_stack(&a), exit_program(), 1);
	if (!is_sorted(&a))
	{
		size = lstsize(a);
		if (size == 3)
			sort_three(&a);
		else if (size == 4)
			sort_four(&a, &b);
		// else if (size == 5)
		// 	sort_five(&a, &b);
		// else
		// 	sort_algo(&a, &b);
	}
	print_list(a);
}
