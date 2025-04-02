/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_transfer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:12:37 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:26:01 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Vérifie la présence d'un élément dans un chunk.
 *
 * Parcourt la pile et retourne 1 si un nœud a un index
 * compris entre min et max, 0 sinon.
 *
 * @param stack Adresse du pointeur de la pile.
 * @param min   Borne inférieure de l'index.
 * @param max   Borne supérieure de l'index.
 * @return int  1 si un élément est trouvé, 0 sinon.
 */
int	element_in_chunk(t_stack_node **stack, int min, int max)
{
	t_stack_node	*curr;

	curr = *stack;
	while (curr)
	{
		if (curr->index >= min && curr->index <= max)
			return (1);
		curr = curr->next;
	}
	return (0);
}

/**
 * @brief Transfère des éléments de A vers B par chunk.
 *
 * Transfère les éléments de la pile A dont l'index se situe dans
 * l'intervalle [min, max] vers la pile B. Pour les éléments de la
 * moitié inférieure du chunk, une rotation de B (rb) est appliquée.
 *
 * @param a   Adresse de la pile A.
 * @param b   Adresse de la pile B.
 * @param min Borne inférieure de l'index.
 * @param max Borne supérieure de l'index.
 */
void	transfer_chunk(t_stack_node **a, t_stack_node **b, int min, int max)
{
	int	half_chunk;

	half_chunk = (max - min + 1) / 2;
	while (element_in_chunk(a, min, max))
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			commands_pb(a, b, 1);
			if ((*b) && ((*b)->index < (min + half_chunk)))
				commands_rb(b, 1);
		}
		else
			commands_ra(a, 1);
	}
}

/**
 * @brief Transfère tous les éléments de A vers B par chunk.
 *
 * Calcule le nombre de chunks et la taille de chacun, puis
 * transfère les éléments de A vers B par intervalle.
 *
 * @param a     Adresse de la pile A.
 * @param b     Adresse de la pile B.
 * @param total Nombre total d'éléments.
 */
void	transfer_all_chunks(t_stack_node **a, t_stack_node **b, int total)
{
	int	num_chunks;
	int	chunk_size;
	int	i;
	int	max_index;

	num_chunks = optimal_chunk_count(total);
	chunk_size = calculate_chunk_size(total, num_chunks);
	i = 0;
	max_index = 0;
	while (i < num_chunks)
	{
		if (i == num_chunks - 1)
			max_index = total - 1;
		else
			max_index = ((i + 1) * chunk_size - 1);
		transfer_chunk(a, b, i * chunk_size, max_index);
		i++;
	}
}
