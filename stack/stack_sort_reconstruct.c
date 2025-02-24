/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_reconstruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:12:35 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/24 01:14:33 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Retourne la position de l'élément de B ayant l'index maximum.
   Les positions commencent à 0. */
int find_max_position(t_stack_node **stack_b)
{
    t_stack_node *current;
    int max_index;
    int pos;
    int max_pos;

    if (!stack_b || !(*stack_b))
        return (-1);
    current = *stack_b;
    max_index = current->index;
    pos = 0;
    max_pos = 0;
    current = current->next;
    pos++;
    while (current)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (max_pos);
}

/* Reconstruit la pile A à partir de la pile B.
   À chaque itération, on fait tourner B jusqu'au maximum soit en tête, puis
   on effectue un `pa` pour le transférer dans A. */
void reconstruct_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int pos;
    int size;
    
    while (*stack_b)
    {
        pos = find_max_position(stack_b);
        size = get_stack_size(stack_b);
        if (pos <= size / 2)
        {
            while (pos > 0)
            {
                commands_rb(stack_b, 1);
                pos--;
            }
        }
        else
        {
            int rrb_count = size - pos;
            while (rrb_count > 0)
            {
                commands_rrb(stack_b, 1);
                rrb_count--;
            }
        }
        commands_pa(stack_a, stack_b, 1);
    }
}