/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:53:31 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 17:59:38 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			slen;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	res = (char *)malloc((slen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < slen)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
