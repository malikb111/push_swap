/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:08:23 by malik             #+#    #+#             */
/*   Updated: 2024/12/24 13:33:42 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

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
	while (str[i] >= '0' && str[i] <= '9' )
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	if (sign == 1)
		number = -number;
	return (number);
}
