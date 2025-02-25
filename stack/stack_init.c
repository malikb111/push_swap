/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/25 01:43:10 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	process_argument(t_stack_node **stack_a, char **av, int start_index, char *arg)
{
	long	n;

	if (error_check_syntax(arg))
	{
		if (start_index == 0)
			free_split_dup(av);
		error_reset(stack_a);
	}
	n = ft_atol(arg);
	if (n < INT_MIN || n > INT_MAX)
	{
		if (start_index == 0)
			free_split_dup(av);
		error_reset(stack_a);
	}
	if (error_check_dup(stack_a, (int)n))
	{
		if (start_index == 0)
			free_split_dup(av);
		error_reset(stack_a);
	}
	stack_add_node(stack_a, (int)n);
}

void	stack_init(t_stack_node **stack_a, char **av, int start_index)
{
	int	i;

	i = start_index;
	while (av[i])
	{
		process_argument(stack_a, av, start_index, av[i]);
		i++;
	}
	stack_index(stack_a);
}

static t_stack_node	*find_min(t_stack_node **stack_a)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	if (!stack_a || !*stack_a)
		return (NULL);
	current = *stack_a;
	min_node = NULL;
	while (current)
	{
		if ((!min_node || current->nbr < min_node->nbr) && current->index == -1)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	stack_index(t_stack_node **stack_a)
{
	t_stack_node	*min;
	int			index;

	if (!stack_a || !*stack_a)
		return ;
	index = 0;
	min = find_min(stack_a);
	while (min)
	{
		min->index = index++;
		min = find_min(stack_a);
	}
}

