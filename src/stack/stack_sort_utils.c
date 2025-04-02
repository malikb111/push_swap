/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:29:59 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:26:11 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Calcule le nombre optimal de chunks.
 *
 * En fonction du total d'éléments, retourne un nombre
 * prédéfini de chunks.
 *
 * @param total Nombre total d'éléments.
 * @return int Nombre optimal de chunks.
 */
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

/**
 * @brief Calcule la taille d'un chunk.
 *
 * Divise le total par le nombre de chunks pour obtenir
 * la taille de chaque chunk.
 *
 * @param total Nombre total d'éléments.
 * @param num_chunks Nombre de chunks.
 * @return int Taille d'un chunk.
 */
int	calculate_chunk_size(int total, int num_chunks)
{
	return (total / num_chunks);
}

/**
 * @brief Calcule la taille de la pile.
 *
 * Parcourt la pile et compte le nombre de nœuds.
 *
 * @param stack Adresse du pointeur de la pile.
 * @return int Nombre de nœuds dans la pile.
 */
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

/**
 * @brief Trouve la position d'un indice dans la pile.
 *
 * Parcourt la pile et retourne la position du nœud dont
 * l'indice correspond à idx. Si non trouvé, retourne -1.
 *
 * @param stack Adresse du pointeur de la pile.
 * @param idx Indice recherché.
 * @return int Position du nœud ou -1 si non trouvé.
 */
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

/**
 * @brief Fait tourner la pile pour amener le nœud avec un indice donné en tête.
 *
 * Effectue des rotations (vers le haut ou vers le bas) pour mettre le nœud
 * avec l'indice spécifié en première position.
 *
 * @param stack Adresse du pointeur de la pile.
 * @param idx Indice du nœud à amener en tête.
 */
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
