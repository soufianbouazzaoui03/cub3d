/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:57 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 17:06:12 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(const char *s1, const char *s2, size_t s1len, size_t s2len)
{
	size_t	i;
	size_t	j;
	char	*strj;

	strj = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!strj)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1len)
	{
		strj[i] = s1[i];
		i++;
	}
	while (i < s1len + s2len)
	{
		strj[i] = s2[j];
		i++;
		j++;
	}
	strj[i++] = '\0';
	return (strj);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1 && s2)
	{
		strj = ft_fill(s1, s2, s1len, s2len);
		if (!strj)
			return (NULL);
		return (strj);
	}
	return (NULL);
}
