/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/25 10:24:31 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	process_arg(t_stack_node **a, char **av, int start, char *arg)
{
	long	n;

	if (error_check_syntax(arg))
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	n = ft_atol(arg);
	if (n < INT_MIN || n > INT_MAX)
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	if (error_check_dup(a, (int)n))
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	stack_add_node(a, (int)n);
}

void	stack_init(t_stack_node **a, char **av, int start)
{
	int	i;

	i = start;
	while (av[i])
	{
		process_arg(a, av, start, av[i]);
		i++;
	}
	stack_index(a);
}

static t_stack_node	*find_min(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	if (!a || !*a)
		return (NULL);
	current = *a;
	min_node = NULL;
	while (current)
	{
		if ((!min_node || current->nbr < min_node->nbr) && current->index == -1)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	stack_index(t_stack_node **a)
{
	t_stack_node	*min;
	int				index;

	if (!a || !*a)
		return ;
	index = 0;
	min = find_min(a);
	while (min)
	{
		min->index = index++;
		min = find_min(a);
	}
}
