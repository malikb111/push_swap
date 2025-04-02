/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:08:23 by malik             #+#    #+#             */
/*   Updated: 2025/04/02 19:00:40 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Vérifie si le caractère est un espace.
 *
 * Retourne 1 si le caractère est un espace ou un contrôle
 * entre 9 et 13, sinon retourne 0.
 *
 * @param c Caractère à vérifier.
 * @return int 1 si c'est un espace, 0 sinon.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/**
 * @brief Libère un tableau de chaînes.
 *
 * Parcourt le tableau, libère chaque chaîne, puis
 * libère le tableau lui-même.
 *
 * @param split Tableau de chaînes à libérer.
 */
void	free_split_dup(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief Compte le nombre de mots d'une chaîne.
 *
 * Parcourt la chaîne et compte le nombre de sous-chaînes
 * séparées par le caractère c.
 *
 * @param s Chaîne à analyser.
 * @param c Caractère délimiteur.
 * @return int Nombre de mots trouvés.
 */
int	count_words_dup(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

/**
 * @brief Convertit une chaîne en long.
 *
 * Ignore les espaces initiaux, tient compte du signe (+ ou -) 
 * et convertit la partie numérique en une valeur long.
 *
 * @param str Chaîne à convertir.
 * @return long Valeur convertie.
 */
long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	number = 0;
	sign = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	if (sign == 1)
		number = -number;
	return (number);
}