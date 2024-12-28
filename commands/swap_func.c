/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:46:55 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/28 17:16:55 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next
}

void	commands_sa(t_stack_node **stack_a, int log)
{
	swap(stack_a);
	if (log)
		ft_printf("sa/n");
}

void	commands_sb(t_stack_node **stack_b, int log)
{
	swap(stack_b);
	if (log)
		ft_printf("sb/n");
}

void	commands_ss(t_stack_node **stack_a, t_stack_node **stack_b, int log)
{
	swap(stack_a);
	swap(stack_b);
	if (log)
		ft_printf("ss/n");
}