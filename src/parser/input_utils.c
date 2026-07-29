/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_empty_argument(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (1);
	i = 0;
	while (arg[i])
	{
		if (!is_whitespace(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
