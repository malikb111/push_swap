/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:29:59 by abbouras          #+#    #+#             */
/*   Updated: 2025/02/23 18:33:37 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
* Retourne un nombre optimal de chunks en fonction du total.
* Par exemple, pour 700 éléments, un retour de 12 est courant 
* (entre 12 et 16 selon vos tests et vos besoins).
*/
int optimal_chunk_count(int total)
{
	if (total <= 100)
		return (5);
	else if (total <= 500)
		return (8);
	else if (total <= 1000)
		return (12);
	else 
		return (16);
}

/*
* Calcule la taille d’un chunk à partir du total et du nombre de chunks.
* La division entière est utilisée ici : pour les cas où total n'est pas
* parfaitement divisible, le dernier chunk sera traité via transfert de 
* l’intervalle [i * chunk_size, total - 1].
*/
int calculate_chunk_size(int total, int num_chunks)
{
	return (total / num_chunks);
}

int get_stack_size(t_stack_node **stack)
{
    int count = 0;
    t_stack_node *current = *stack;

    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}