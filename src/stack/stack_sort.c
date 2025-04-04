/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:21:23 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:27:20 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Trie une pile de deux éléments.
 *
 * Compare les deux nœuds de la pile. Si le premier est 
 * supérieur au second, effectue l'opération sa.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 */
static void	sort_two_stack(t_stack_node **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		commands_sa(stack_a, 1);
}

/**
 * @brief Trie une pile de trois éléments.
 *
 * Trie la pile de trois éléments en appliquant des 
 * opérations selon l'ordre des valeurs.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 */
static void	sort_three_stack(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b < c && a < c)
		commands_sa(stack_a, 1);
	else if (a > b && b > c)
	{
		commands_sa(stack_a, 1);
		commands_rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		commands_ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		commands_sa(stack_a, 1);
		commands_ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		commands_rra(stack_a, 1);
}

/**
 * @brief Trie une pile de cinq éléments.
 *
 * Transfère les deux nœuds les plus petits dans B, trie
 * les trois éléments restants de A, puis réinsère les
 * deux nœuds depuis B.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param stack_b Adresse du pointeur de la pile B.
 */
static void	sort_five_stack(t_stack_node **stack_a,
					t_stack_node **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rotate_to_index(stack_a, i);
		commands_pb(stack_a, stack_b, 1);
		i++;
	}
	sort_three_stack(stack_a);
	commands_pa(stack_a, stack_b, 1);
	commands_pa(stack_a, stack_b, 1);
}

/**
 * @brief Trie une pile de grande taille.
 *
 * Pour une pile de plus de cinq éléments, transfère 
 * des nœuds de A vers B par chunks, puis reconstruit A.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param stack_b Adresse du pointeur de la pile B.
 */
static void	sort_large_stack(t_stack_node **stack_a,
					t_stack_node **stack_b)
{
	int	total;

	total = get_stack_size(stack_a);
	transfer_all_chunks(stack_a, stack_b, total);
	reconstruct_stack(stack_a, stack_b);
}

/**
 * @brief Trie la pile en fonction de sa taille.
 *
 * Détermine le nombre d'éléments de la pile et applique 
 * l'algorithme de tri adapté :
 * - 2 éléments : trie simple.
 * - 3 éléments : tri via opérations sa, ra, rra.
 * - 5 éléments : transfert des 2 plus petits puis tri des 3 
 *   restants.
 * - Plus de 5 éléments : tri par chunks.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param stack_b Adresse du pointeur de la pile B.
 */
void	stack_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (size == 2)
		sort_two_stack(stack_a);
	else if (size == 3)
		sort_three_stack(stack_a);
	else if (size == 5)
		sort_five_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}
