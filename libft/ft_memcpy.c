/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:53:49 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/10 23:37:45 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;

	if (!dst && !src)
	{
		return (dst);
	}
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	while (n)
	{
		*tdst = *tsrc;
		tdst++;
		tsrc++;
		n--;
	}
	return (dst); 
}
