/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:21:39 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:25:30 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Déplace le sommet de pile B vers pile A.
 *
 * Transfère le premier élément de la pile B à la pile A.
 * Met à jour les pointeurs de chaque pile.
 *
 * @param stack_a Pointeur vers pile A.
 * @param stack_b Pointeur vers pile B.
 * @param log Si non nul, affiche "pa" en sortie.
 */
void	commands_pa(t_stack_node **stack_a, t_stack_node **stack_b,
		int log)
{
	t_stack_node	*current;

	current = *stack_b;
	if (!current)
		return ;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	current->prev = NULL;
	current->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = current;
	*stack_a = current;
	if (log)
		ft_printf("pa\n");
}

/**
 * @brief Déplace le sommet de pile A vers pile B.
 *
 * Transfère le premier élément de la pile A à la pile B.
 * Met à jour les pointeurs de chaque pile.
 *
 * @param stack_a Pointeur vers pile A.
 * @param stack_b Pointeur vers pile B.
 * @param log Si non nul, affiche "pb" en sortie.
 */
void	commands_pb(t_stack_node **stack_a, t_stack_node **stack_b,
		int log)
{
	t_stack_node	*current;

	current = *stack_a;
	if (!current)
		return ;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	current->prev = NULL;
	current->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = current;
	*stack_b = current;
	if (log)
		ft_printf("pb\n");
}
