/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:56:46 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/02 09:56:47 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

int					ft_error(char *error_text);
void				ft_error_0(t_stack *stack_a, t_stack *stack_b,
						const char *msg, char **str);
void				ft_error_1(t_stack *stack_a, t_stack *stack_b,
						const char *msg);
int					exit_with_error(char **args, t_stack *a, t_stack *b);
t_node				*ft_lstnew_ps(int value);
int					exits_in_stack(t_stack *stack, int value);
int					is_numeric(const char *str);
int					fill_stack(t_stack *stack, int argc, char **argv);
void				swap_s(t_stack *stack);
void				push_value(t_stack *stack, int value);
void				push(t_stack *src, t_stack *dest);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				print_stack(t_stack *stack);
int					*copy_to_arr(t_stack *stack);
int					find_index(int *arr, int size, int value);
void				assign_index_to_nodes(t_stack *stack, int *sorted_values);
void				b_sort(int *arr, int size);
void				assign_index(t_stack *stack);
int					count_args(char **argv);
void				sort3(t_stack *stack);
int					find_min_position(t_stack *stack);
void				sort_five(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);
void				sort_stack(t_stack *a, t_stack *b);
int					init_stacks(t_stack **a, t_stack **b);
void				free_stacks(t_stack *a, t_stack *b);
void				free_stack(t_stack *stack);
void				free_split(char **split);
void				sort_and_index(t_stack *a, t_stack *b);
int					check_sorted(t_stack *stack);
int					ps_atoi(const char *str);

#endif
