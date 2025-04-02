/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:39:03 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 19:26:23 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Ajoute un nœud à la fin de la pile.
 *
 * Alloue un nouveau nœud avec la valeur fournie et
 * l'ajoute à la fin de la pile. Si la pile est vide,
 * le nœud devient le premier élément.
 *
 * @param stack Adresse du pointeur de la pile.
 * @param val La valeur à ajouter dans le nœud.
 */
void	stack_add_node(t_stack_node **stack, int val)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
		return ;
	node->nbr = val;
	node->next = NULL;
	node->index = -1;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = stack_find_last(stack);
		last->next = node;
		node->prev = last;
	}
}

/**
 * @brief Retourne le dernier nœud de la pile.
 *
 * Parcourt la pile et retourne le dernier nœud.
 *
 * @param stack Adresse du pointeur de la pile.
 * @return t_stack_node* Pointeur vers le dernier nœud, ou NULL
 * si la pile est vide ou l'adresse invalide.
 */
t_stack_node	*stack_find_last(t_stack_node **stack)
{
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

/**
 * @brief Affiche les valeurs de tous les nœuds de la pile.
 *
 * Parcourt la pile et affiche la valeur de chaque nœud.
 *
 * @param stack Adresse du pointeur de la pile.
 */
void	stack_print(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		ft_printf("node : %d\n", current->nbr);
		current = current->next;
	}
}

/**
 * @brief Libère tous les nœuds de la pile.
 *
 * Parcourt la pile, libère chaque nœud et met le pointeur
 * de la pile à NULL.
 *
 * @param stack Adresse du pointeur de la pile.
 */
void	stack_free(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*destroyer;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		destroyer = current;
		current->nbr = 0;
		current = current->next;
		free(destroyer);
	}
	*stack = NULL;
}

/**
 * @brief Vérifie si la pile est triée.
 *
 * Parcourt la pile et teste si chaque nœud a un index
 * inférieur ou égal à celui du suivant.
 *
 * @param stack Adresse du pointeur de la pile.
 * @return int Retourne 1 si la pile est triée, 0 sinon.
 */
int	stack_is_sorted(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
