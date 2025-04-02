/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:24:33 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 18:55:21 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Affiche "Error" sur stderr et quitte.
 */
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Vérifie la syntaxe d'une chaîne.
 * 
 * La chaîne doit représenter un nombre valide.
 * Elle peut commencer par '+' ou '-'. Sinon, tous les
 * caractères doivent être des chiffres.
 *
 * @param str Chaine à vérifier.
 * @return int Retourne 1 si une erreur est détectée,
 *             0 sinon.
 */
int	error_check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Vérifie la présence de doublons dans la pile.
 * 
 * Parcourt la pile pour déterminer si la valeur
 * est déjà présente.
 *
 * @param stack Adresse du pointeur de pile.
 * @param value Valeur à chercher.
 * @return int Retourne 1 si un doublon est trouvé,
 *             0 sinon.
 */
int	error_check_dup(t_stack_node **stack, int value)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (current->nbr == value)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * @brief Libère la pile et quitte en erreur.
 * 
 * Appelle la fonction de libération de la pile,
 * puis termine le programme avec un message d'erreur.
 *
 * @param stack Adresse du pointeur de pile.
 */
void	error_reset(t_stack_node **stack)
{
	stack_free(stack);
	error_exit();
}