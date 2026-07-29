/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

void	stack_init(t_stack *stack);
t_node	*node_new(int value);
void	stack_add_bottom(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);

int		is_whitespace(char c);
int		is_empty_argument(char *arg);
int		is_digit(char c);
int		is_valid_number(char *str);
int		parse_int(char *str, int *value);
int		has_duplicate(t_stack *stack, int value);
void	parse_token(t_stack *stack, char *token);
void	parse_argument(t_stack *stack, char *arg);
void	parse_arguments(t_stack *stack, int argc, char **argv);
void	error_exit(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	assign_indexes(t_stack *stack);
t_node	*find_min_index_node(t_stack *stack);

int		is_sorted(t_stack *stack);
int		get_node_position(t_stack *stack, t_node *target);
int		should_rotate(t_stack *stack, t_node *target);
void	move_min_to_top(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
int		get_max_bits(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);

#endif
