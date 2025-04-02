/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:26:33 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 16:16:55 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	commands_ra(t_stack_node **stack_a, int log)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last = stack_find_last(stack_a);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (log)
		ft_printf("ra\n");
}

void	commands_rb(t_stack_node **stack_b, int log)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last = stack_find_last(stack_b);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (log)
		ft_printf("rb\n");
}

void	commands_rr(t_stack_node **stack_a, t_stack_node **stack_b, int log)
{
	commands_ra(stack_a, 0);
	commands_rb(stack_b, 0);
	if (log)
		ft_printf("rr\n");
}
