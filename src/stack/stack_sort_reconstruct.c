/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_reconstruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:12:35 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 18:57:27 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Retourne la position du nœud avec l'index maximum dans B.
 *
 * Parcourt la pile B et retourne la position 
 * (commençant à 0) du nœud dont l'index est le plus 
 * élevé. Si la pile est vide, retourne -1.
 *
 * @param b Adresse du pointeur de la pile B.
 * @return int Position du nœud maximum, ou -1 en cas d'erreur.
 */
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

/**
 * @brief Tourne la pile B pour mettre le maximum en tête.
 *
 * En fonction de la position du maximum dans B, effectue 
 * une rotation vers le haut avec rb, ou vers le bas avec 
 * rrb, pour que le nœud maximum se retrouve en première 
 * position.
 *
 * @param b Adresse du pointeur de la pile B.
 */
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

/**
 * @brief Reconstruit la pile A à partir de B.
 *
 * Transfère tous les éléments de la pile B vers la pile A.
 * À chaque itération, la pile B est tournée pour mettre le 
 * nœud maximum en tête, puis ce nœud est transféré sur A.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param b       Adresse du pointeur de la pile B.
 */
void	reconstruct_stack(t_stack_node **stack_a, t_stack_node **b)
{
	while (*b)
	{
		rotate_to_max(b);
		commands_pa(stack_a, b, 1);
	}
}