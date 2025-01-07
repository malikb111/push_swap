/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2025/01/07 21:03:05 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack_node **stack_a, char **av, int start_index)
{
	long	n;
	int		i;

	i = start_index;
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
