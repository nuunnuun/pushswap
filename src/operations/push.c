/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*remove_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	node->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

static void	add_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

static void	push_raw(t_stack *destination, t_stack *source)
{
	add_top(destination, remove_top(source));
}

void	pa(t_stack *a, t_stack *b)
{
	push_raw(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_raw(b, a);
	write(1, "pb\n", 3);
}
