/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 18:25:17 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**split_av;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2 && av[1][1] != '\0')
	{
		split_av = ft_split(av[1], ' ');
		stack_init(&stack_a, split_av, 0);
		free_split_dup(split_av);
	}
	else
		stack_init(&stack_a, av, 1);
	if (!stack_is_sorted(&stack_a))
		stack_sort(&stack_a, &stack_b);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
