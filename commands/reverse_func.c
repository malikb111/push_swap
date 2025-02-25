/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:01:02 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/25 10:21:31 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = stack_find_last(stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	commands_rra(t_stack_node **stack_a, int log)
{
	reverse_rotate(stack_a);
	if (log)
		ft_printf("rra\n");
}

void	commands_rrb(t_stack_node **stack_b, int log)
{
	reverse_rotate(stack_b);
	if (log)
		ft_printf("rrb\n");
}

void	commands_rrr(t_stack_node **stack_a, t_stack_node **stack_b, int log)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (log)
		ft_printf("rrr\n");
}
