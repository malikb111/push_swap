/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:10 by abbouras          #+#    #+#             */
/*   Updated: 2025/04/02 17:41:15 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../external/libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					error_exit(void);
void					error_reset(t_stack_node **stack);
int						error_check_dup(t_stack_node **stack, int value);
int						error_check_syntax(char *str);
long					ft_atol(char *str);
int						ft_isspace(char c);
int						count_words_dup(char const *s, char c);
void					free_split_dup(char **split);
void					stack_init(t_stack_node **a, char **av,
							int start_index);
void					stack_add_node(t_stack_node **stack, int val);
void					stack_free(t_stack_node **stack);
void					stack_print(t_stack_node **stack);
int						get_stack_size(t_stack_node **stack);
int						stack_is_sorted(t_stack_node **stack);
void					commands_sa(t_stack_node **stack, int log);
void					commands_sb(t_stack_node **stack, int log);
void					commands_ss(t_stack_node **a,
							t_stack_node **b, int log);
void					commands_pa(t_stack_node **a,
							t_stack_node **b, int log);
void					commands_pb(t_stack_node **a,
							t_stack_node **b, int log);
void					commands_ra(t_stack_node **a, int log);
void					commands_rb(t_stack_node **b, int log);
void					commands_rr(t_stack_node **a,
							t_stack_node **b, int log);
void					commands_rra(t_stack_node **a, int log);
void					commands_rrb(t_stack_node **b, int log);
void					commands_rrr(t_stack_node **a,
							t_stack_node **b, int log);
void					stack_index(t_stack_node **a);
void					stack_sort(t_stack_node **a,
							t_stack_node **b);
void					transfer_all_chunks(t_stack_node **a, t_stack_node **b,
							int total);
void					transfer_chunk(t_stack_node **a, t_stack_node **b,
							int min, int max);
int						element_in_chunk(t_stack_node **stack, int min,
							int max);
int						find_max_position(t_stack_node **b);
void					rotate_to_max(t_stack_node **b);
void					reconstruct_stack(t_stack_node **a,
							t_stack_node **b);
int						optimal_chunk_count(int total);
int						calculate_chunk_size(int total, int num_chunks);
t_stack_node			*stack_find_last(t_stack_node **stack);
int						find_index_pos(t_stack_node **stack, int idx);
void					rotate_to_index(t_stack_node **stack, int idx);

#endif