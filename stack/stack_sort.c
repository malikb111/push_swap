/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:21:23 by abbouras          #+#    #+#             */
/*   Updated: 2025/01/07 22:55:54 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*current;
	int			max_num;
	int			max_bits;

	current = *stack;
	max_num = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max_num)
			max_num = current->index;
		current = current->next;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	get_stack_size(t_stack_node **stack)
{
	t_stack_node	*current;
	int			size;

	size = 0;
	current = *stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	stack_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = get_stack_size(stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				commands_ra(stack_a, 1);
			else
				commands_pb(stack_a, stack_b, 1);
			j++;
		}
		while (*stack_b)
			commands_pa(stack_a, stack_b, 1);
		i++;
	}
}
