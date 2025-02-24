/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_transfer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:12:37 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/24 05:39:28 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Vérifie s'il existe dans la pile un élément dont l'index est entre min et max */
int element_in_chunk(t_stack_node **stack, int min, int max)
{
    t_stack_node *curr = *stack;
    while (curr)
    {
        if (curr->index >= min && curr->index <= max)
            return (1);
        curr = curr->next;
    }
    return (0);
}

/* Transfère de A vers B tous les éléments dont l'index est dans [min, max].
   On effectue une rotation de B (rb) pour les éléments de la moitié inférieure du chunk. */
void transfer_chunk(t_stack_node **a, t_stack_node **b, int min, int max)
{
    int half_chunk = (max - min + 1) / 2;
    
    while (element_in_chunk(a, min, max))
    {
        if ((*a)->index >= min && (*a)->index <= max)
        {
            commands_pb(a, b, 1);
            if ((*b) && ((*b)->index < (min + half_chunk)))
                commands_rb(b, 1);
        }
        else
            commands_ra(a, 1);
    }
}

/* Calcule le nombre de chunks, la taille de chaque chunk et transfère par chunks */
void transfer_all_chunks(t_stack_node **a, t_stack_node **b, int total)
{
    int num_chunks = optimal_chunk_count(total);
    int chunk_size = calculate_chunk_size(total, num_chunks);
    int i = 0;
    int max_index;

    while (i < num_chunks)
    {
        if (i == num_chunks - 1)
            max_index = total - 1;
        else
            max_index = ((i + 1) * chunk_size - 1);
        transfer_chunk(a, b, i * chunk_size, max_index);
        i++;
    }
}