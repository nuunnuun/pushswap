/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kullatid <kullatid@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:00:00 by kullatid          #+#    #+#             */
/*   Updated: 2026/07/28 12:00:00 by kullatid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(char *str, int *position)
{
	if (str[*position] == '-')
	{
		(*position)++;
		return (-1);
	}
	if (str[*position] == '+')
		(*position)++;
	return (1);
}

int	parse_int(char *str, int *value)
{
	long	number;
	long	limit;
	int		sign;
	int		i;

	i = 0;
	sign = get_sign(str, &i);
	limit = INT_MAX;
	if (sign < 0)
		limit = -(long)INT_MIN;
	number = 0;
	while (str[i])
	{
		if (number > (limit - (str[i] - '0')) / 10)
			return (0);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	*value = (int)(number * sign);
	return (1);
}
