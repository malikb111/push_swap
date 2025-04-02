/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_reconstruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:12:35 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 17:04:20 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Retourne la position de l'élément de B ayant l'index maximum.
   Les positions commencent à 0. */
int	find_max_position(t_stack_node **b)
{
	t_stack_node	*current;
	int				max_index;
	int				pos;
	int				max_pos;

	if (!b || !(*b))
		return (-1);
	current = *b;
	max_index = current->index;
	pos = 0;
	max_pos = 0;
	current = current->next;
	pos++;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

/* Fait tourner la pile B pour placer l'élément maximum en tête.
   Utilise rb ou rrb selon la position la plus efficace. */
void	rotate_to_max(t_stack_node **b)
{
	int	pos;
	int	size;
	int	rrb_count;

	pos = find_max_position(b);
	size = get_stack_size(b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			commands_rb(b, 1);
			pos--;
		}
	}
	else
	{
		rrb_count = size - pos;
		while (rrb_count > 0)
		{
			commands_rrb(b, 1);
			rrb_count--;
		}
	}
}

/* Reconstruit la pile A à partir de la pile B.
   À chaque itération, on fait tourner B jusqu'au maximum soit en tête, puis
   on effectue un `pa` pour le transférer dans A. */
void	reconstruct_stack(t_stack_node **stack_a, t_stack_node **b)
{
	while (*b)
	{
		rotate_to_max(b);
		commands_pa(stack_a, b, 1);
	}
}
