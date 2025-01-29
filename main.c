/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:29:13 by anachat           #+#    #+#             */
/*   Updated: 2025/01/28 18:29:13 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**nums;
	int		i;

	ft_printf("We have %d argumets.\n", ac - 1);
	nums = ft_split(av[1], ' ');
	i = 0;
	while (nums[i])
	{
		ft_printf("N°%d: %d\n", i+1, ft_atoi(nums[i]));
		i++;
	}
}
