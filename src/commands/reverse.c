/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:01:02 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:25:27 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Effectue une rotation inverse sur une pile.
 *
 * Fait passer le dernier nœud de la pile en début.
 * Met à jour les liaisons de la liste chaînée.
 *
 * @param stack Adresse du pointeur de la pile.
 */
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = stack_find_last(stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/**
 * @brief Rotation inverse de la pile A.
 *
 * Fait passer le dernier nœud de la pile A en début.
 * Affiche "rra" si log est non nul.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param log     Indicateur pour l'affichage.
 */
void	commands_rra(t_stack_node **stack_a, int log)
{
	reverse_rotate(stack_a);
	if (log)
		ft_printf("rra\n");
}

/**
 * @brief Rotation inverse de la pile B.
 *
 * Fait passer le dernier nœud de la pile B en début.
 * Affiche "rrb" si log est non nul.
 *
 * @param stack_b Adresse du pointeur de la pile B.
 * @param log     Indicateur pour l'affichage.
 */
void	commands_rrb(t_stack_node **stack_b, int log)
{
	reverse_rotate(stack_b);
	if (log)
		ft_printf("rrb\n");
}

/**
 * @brief Rotation inverse simultanée de A et B.
 *
 * Effectue une rotation inverse sur les piles A et B.
 * Affiche "rrr" si log est non nul.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param stack_b Adresse du pointeur de la pile B.
 * @param log     Indicateur pour l'affichage.
 */
void	commands_rrr(t_stack_node **stack_a, t_stack_node **stack_b,
			int log)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (log)
		ft_printf("rrr\n");
}
