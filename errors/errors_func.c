/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:24:33 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/24 13:30:16 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	error_check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (1);
		i++;
	}
	return (0);
}

int	error_check_dup(t_stack_node **stack, int value)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (current->nbr == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	error_reset(t_stack_node **stack)
{
	stack_free(stack);
	error_exit();
}
