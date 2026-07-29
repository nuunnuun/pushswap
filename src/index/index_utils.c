/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_index_node(t_stack *stack)
{
	t_node	*node;
	t_node	*minimum;

	if (!stack || !stack->top)
		return (NULL);
	minimum = stack->top;
	node = stack->top->next;
	while (node)
	{
		if (node->index < minimum->index)
			minimum = node;
		node = node->next;
	}
	return (minimum);
}
