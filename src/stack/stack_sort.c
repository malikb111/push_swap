/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:21:23 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 17:41:14 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_two_stack(t_stack_node **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		commands_sa(stack_a, 1);
}

static void	sort_three_stack(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b < c && a < c)
		commands_sa(stack_a, 1);
	else if (a > b && b > c)
	{
		commands_sa(stack_a, 1);
		commands_rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		commands_ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		commands_sa(stack_a, 1);
		commands_ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		commands_rra(stack_a, 1);
}

static void	sort_five_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rotate_to_index(stack_a, i);
		commands_pb(stack_a, stack_b, 1);
		i++;
	}
	sort_three_stack(stack_a);
	commands_pa(stack_a, stack_b, 1);
	commands_pa(stack_a, stack_b, 1);
}

static void	sort_large_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	total;

	total = get_stack_size(stack_a);
	transfer_all_chunks(stack_a, stack_b, total);
	reconstruct_stack(stack_a, stack_b);
}

void	stack_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (size == 2)
		sort_two_stack(stack_a);
	else if (size == 3)
		sort_three_stack(stack_a);
	else if (size == 5)
		sort_five_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}
