/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:42 by abbouras          #+#    #+#             */
/*   Updated: 2024/12/28 16:08:57 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void	error_exit(void);
void	error_reset(t_stack_node **stack);
int		error_check_dup(t_stack_node **stack, int value);
int		error_check_syntax(char *str);
long	ft_atol(char *str);
int		ft_isspace(char c);
void	stack_init(t_stack_node **stack_a, char **av);
void	stack_add_node(t_stack_node **stack, int val);
t_stack_node		*stack_find_last(t_stack_node **stack);
void	stack_free(t_stack_node **stack);
void	stack_print(t_stack_node **stack);
int		stack_is_sorted(t_stack_node **stack);

#endif