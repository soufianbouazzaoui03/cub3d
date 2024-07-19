/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:02:00 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 16:58:14 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	res = NULL;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
		{
			res = (char *) &s[i];
		}
		i++;
	}
	return (res);
}
