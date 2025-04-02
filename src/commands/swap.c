/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:46:55 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 18:54:35 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Intervertit les deux premiers nœuds d'une pile.
 *
 * Si la pile contient moins de deux nœuds, la fonction
 * ne fait rien.
 *
 * @param stack Adresse du pointeur de la pile.
 */
static void	swap(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = *stack;
	if (!current || !current->next)
		return ;
	next_node = current->next;
	current->next = next_node->next;
	if (next_node->next)
		next_node->next->prev = current;
	next_node->prev = NULL;
	next_node->next = current;
	current->prev = next_node;
	*stack = next_node;
}

/**
 * @brief Exécute l'opération sa sur la pile A.
 *
 * Utilise la fonction swap pour intervertir les deux
 * premiers éléments de la pile A.
 * Affiche "sa" si log est non nul.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param log     Indique si le message doit être affiché.
 */
void	commands_sa(t_stack_node **stack_a, int log)
{
	swap(stack_a);
	if (log)
		ft_printf("sa\n");
}

/**
 * @brief Exécute l'opération sb sur la pile B.
 *
 * Utilise la fonction swap pour intervertir les deux
 * premiers éléments de la pile B.
 * Affiche "sb" si log est non nul.
 *
 * @param stack_b Adresse du pointeur de la pile B.
 * @param log     Indique si le message doit être affiché.
 */
void	commands_sb(t_stack_node **stack_b, int log)
{
	swap(stack_b);
	if (log)
		ft_printf("sb\n");
}

/**
 * @brief Exécute l'opération ss sur les piles A et B.
 *
 * Effectue un swap simultané sur la pile A et sur la
 * pile B.
 * Affiche "ss" si log est non nul.
 *
 * @param stack_a Adresse du pointeur de la pile A.
 * @param stack_b Adresse du pointeur de la pile B.
 * @param log     Indique si le message doit être affiché.
 */
void	commands_ss(t_stack_node **stack_a, t_stack_node **stack_b,
			int log)
{
	swap(stack_a);
	swap(stack_b);
	if (log)
		ft_printf("ss\n");
}