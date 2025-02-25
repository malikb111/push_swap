/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:39:03 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/25 10:23:06 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_add_node(t_stack_node **stack, int val)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return ;
	node->nbr = val;
	node->next = NULL;
	node->index = -1;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = stack_find_last(stack);
		last->next = node;
		node->prev = last;
	}
}

t_stack_node	*stack_find_last(t_stack_node **stack)
{
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	stack_print(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		ft_printf("node : %d\n", current->nbr);
		current = current->next;
	}
}

void	stack_free(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*destroyer;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		destroyer = current;
		current->nbr = 0;
		current = current->next;
		free(destroyer);
	}
	*stack = NULL;
}

int	stack_is_sorted(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
