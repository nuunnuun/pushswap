/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (1);
	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_node_position(t_stack *stack, t_node *target)
{
	t_node	*node;
	int		position;

	position = 0;
	node = stack->top;
	while (node)
	{
		if (node == target)
			return (position);
		position++;
		node = node->next;
	}
	return (-1);
}

int	should_rotate(t_stack *stack, t_node *target)
{
	return (get_node_position(stack, target) <= stack->size / 2);
}

void	move_min_to_top(t_stack *a)
{
	t_node	*minimum;

	minimum = find_min_index_node(a);
	while (a->top != minimum)
	{
		if (should_rotate(a, minimum))
			ra(a);
		else
			rra(a);
	}
}
