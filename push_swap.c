/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:12 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/24 13:17:14 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_printf("%p, %p\n\n", &stack_a, &stack_b);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2 && av[1][1] != '\0')
		av = ft_split(av[1], ' ');
	stack_init(&stack_a, av);
	stack_print(&stack_a);
	stack_free(&stack_a);
}
