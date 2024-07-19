/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 04:02:27 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/12 01:41:56 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int num)
{
	if (num == '\t' || num == '\n' || num == '\r' 
		|| num == '\f' || num == '\v' || num == ' ')
		return (1);
	else
		return (0);
}

void	ft_sign(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' && str[(*i) + 1] != '-')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	ft_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807LL && sign == 1)
			return (-1);
		if (res > 9223372036854775807LL -1LL && sign == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}
