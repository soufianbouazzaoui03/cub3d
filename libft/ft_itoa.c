/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:20:26 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/12 20:47:18 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static long	ft_size2(long n)
{
	long	res;

	res = 1;
	while (n > 1)
	{
		res *= 10;
		n--;
	}
	return (res);
}

static char	*ft_fillpos(size_t size, long nbr, long zeros)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (zeros)
	{
		res[i++] = nbr / zeros + '0';
		nbr = nbr - (nbr / zeros) * zeros;
		zeros /= 10;
	}
	res[size] = '\0';
	return (res);
}

static char	*ft_fillnega(size_t size, long nbr, long zeros)
{
	int		i;
	char	*res2;

	i = 1;
	nbr = nbr * (-1);
	res2 = (char *)malloc((size + 2) * sizeof(char));
	if (!res2)
		return (NULL);
	res2[0] = '-';
	while (zeros)
	{
		res2[i++] = nbr / zeros + '0';
		nbr = nbr - (nbr / zeros) * zeros;
		zeros /= 10;
	}
	res2[size + 1] = '\0';
	return (res2);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*res;
	size_t	size;
	long	zeros;

	nbr = n;
	size = ft_size(nbr);
	zeros = ft_size2(size);
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr > 0)
	{
		res = ft_fillpos(ft_size(nbr), nbr, ft_size2(ft_size(nbr)));
		if (!res)
			return (NULL);
	}
	else
	{
		res = ft_fillnega(ft_size(nbr), nbr, ft_size2(ft_size(nbr)));
		if (!res)
			return (NULL);
	}
	return (res);
}
