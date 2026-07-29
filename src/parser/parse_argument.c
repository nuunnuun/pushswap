/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*copy_token(char *arg, int start, int end)
{
	char	*token;
	int		i;

	token = malloc(sizeof(char) * (end - start + 1));
	if (!token)
		return (NULL);
	i = 0;
	while (start < end)
		token[i++] = arg[start++];
	token[i] = '\0';
	return (token);
}

static int	skip_whitespace(char *arg, int i)
{
	while (arg[i] && is_whitespace(arg[i]))
		i++;
	return (i);
}

void	parse_argument(t_stack *stack, char *arg)
{
	char	*token;
	int		start;
	int		i;

	if (is_empty_argument(arg))
		error_exit(stack, NULL);
	i = 0;
	while (arg[i])
	{
		i = skip_whitespace(arg, i);
		start = i;
		while (arg[i] && !is_whitespace(arg[i]))
			i++;
		if (i > start)
		{
			token = copy_token(arg, start, i);
			if (!token)
				error_exit(stack, NULL);
			parse_token(stack, token);
		}
	}
}
