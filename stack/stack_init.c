/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/24 13:39:18 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack_node **stack_a, char **av)
{
	long	n;
	int		i;

	i = 1;
	while (av[i])
	{
		if (error_check_syntax(av[i]))
			error_reset(stack_a);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_reset(stack_a);
		if (error_check_dup(stack_a, (int)n))
			error_reset(stack_a);
		stack_add_node(stack_a, (int)n);
		i++;
	}
}
