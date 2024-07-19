/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:08:07 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/16 18:17:16 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isequale(char s1, const char *set)
{
	int	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[end] && (ft_isequale(s1[end], set)))
	{
		end--;
	}
	while (s1[start] && (ft_isequale(s1[start], set)))
	{
		start++;
	}
	return (ft_substr(s1, (unsigned int)(start), (size_t)(end - start + 1)));
}
