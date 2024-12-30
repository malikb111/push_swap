/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:21:39 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/30 22:09:42 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	commands_pa(t_stack_node **stack_a, t_stack_node **stack_b, int log)
{
	t_stack_node	*current;

	current = *stack_b;
	if (!current)
		return ;
	*stack_b = (*stack_b)->next;
	if (*stack_b) 
		(*stack_b)->prev = NULL;
	current->prev = NULL; 
	current->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = current;
	*stack_a = current;
	if (log)
		ft_printf("pa\n");
}

void	commands_pb(t_stack_node **stack_a, t_stack_node **stack_b, int log)
{
	t_stack_node	*current;

	current = *stack_a;
	if (!current)
		return ;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	current->prev = NULL; 
	current->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = current;
	*stack_b = current;
	if (log)
		ft_printf("pb\n");
}
