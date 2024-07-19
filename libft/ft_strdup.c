/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:16:23 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 16:53:26 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *) s1;
	cpy = malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (i < len)
	{
		cpy[i] = *str;
		i++;
		str++;
	}
	cpy[len] = '\0'; 
	return (cpy);
}
