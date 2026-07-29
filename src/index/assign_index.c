/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_stack *stack, t_node *target)
{
	t_node	*node;
	int		count;

	count = 0;
	node = stack->top;
	while (node)
	{
		if (node->value < target->value)
			count++;
		node = node->next;
	}
	return (count);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		node->index = count_smaller(stack, node);
		node = node->next;
	}
}
