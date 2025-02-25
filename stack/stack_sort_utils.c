/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:29:59 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/25 10:40:22 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
