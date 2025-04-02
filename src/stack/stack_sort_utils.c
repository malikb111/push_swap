/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:29:59 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 17:40:57 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	optimal_chunk_count(int total)
{
	if (total <= 100)
		return (5);
	else if (total <= 500)
		return (8);
	else if (total <= 1000)
		return (12);
	else
		return (16);
}

int	calculate_chunk_size(int total, int num_chunks)
{
	return (total / num_chunks);
}

int	get_stack_size(t_stack_node **stack)
{
	t_stack_node	*current;
	int				count;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	find_index_pos(t_stack_node **stack, int idx)
{
	t_stack_node	*current;
	int				pos;

	pos = 0;
	current = *stack;
	while (current)
	{
		if (current->index == idx)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void	rotate_to_index(t_stack_node **stack, int idx)
{
	int	pos;
	int	size;

	size = get_stack_size(stack);
	pos = find_index_pos(stack, idx);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			commands_ra(stack, 1);
	}
	else
	{
		while (pos < size)
		{
			commands_rra(stack, 1);
			pos++;
		}
	}
}
