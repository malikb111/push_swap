/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 18:57:07 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Traite un argument pour initialiser la pile.
 *
 * Vérifie la syntaxe du nombre, sa plage, et s'il est unique.
 * En cas d'erreur, libère av si nécessaire, puis quitte.
 *
 * @param a Adresse du pointeur de la pile.
 * @param av Tableau des arguments.
 * @param start Indice de départ dans av.
 * @param arg Argument à traiter.
 */
static void	process_arg(t_stack_node **a, char **av, int start, 
		char *arg)
{
	long	n;

	if (error_check_syntax(arg))
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	n = ft_atol(arg);
	if (n < INT_MIN || n > INT_MAX)
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	if (error_check_dup(a, (int)n))
	{
		if (start == 0)
			free_split_dup(av);
		error_reset(a);
	}
	stack_add_node(a, (int)n);
}

/**
 * @brief Initialise la pile à partir d'un tableau d'args.
 *
 * Parcourt le tableau av en partant de start, traite 
 * chaque argument et indexe la pile.
 *
 * @param a Adresse du pointeur de la pile.
 * @param av Tableau des arguments.
 * @param start Indice de départ dans av.
 */
void	stack_init(t_stack_node **a, char **av, int start)
{
	int	i;

	i = start;
	while (av[i])
	{
		process_arg(a, av, start, av[i]);
		i++;
	}
	stack_index(a);
}

/**
 * @brief Trouve le nœud minimum non indexé.
 *
 * Parcourt la pile et retourne le nœud dont la valeur
 * est la plus petite et qui n'est pas encore indexé.
 *
 * @param a Adresse du pointeur de la pile.
 * @return t_stack_node* Pointeur sur le nœud minimum ou NULL.
 */
static t_stack_node	*find_min(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*min_node;

	if (!a || !*a)
		return (NULL);
	current = *a;
	min_node = NULL;
	while (current)
	{
		if ((!min_node || current->nbr < min_node->nbr) && 
				current->index == -1)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

/**
 * @brief Indexe la pile de manière croissante.
 *
 * Assigne un indice à chaque nœud en partant du plus petit,
 * via l'extraction répétée du nœud minimum.
 *
 * @param a Adresse du pointeur de la pile.
 */
void	stack_index(t_stack_node **a)
{
	t_stack_node	*min;
	int				index;

	if (!a || !*a)
		return ;
	index = 0;
	min = find_min(a);
	while (min)
	{
		min->index = index++;
		min = find_min(a);
	}
}
