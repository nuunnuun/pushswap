/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 22:24:23 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	token_error(t_stack *stack, char *token)
{
	free(token);
	error_exit(stack, NULL);
}

void	parse_token(t_stack *stack, char *token)
{
	t_node	*node;
	int		value;

	value = 0;
	if (!is_valid_number(token) || !parse_int(token, &value))
		token_error(stack, token);
	if (has_duplicate(stack, value))
		token_error(stack, token);
	node = node_new(value);
	if (!node)
		token_error(stack, token);
	stack_add_bottom(stack, node);
	free(token);
}
