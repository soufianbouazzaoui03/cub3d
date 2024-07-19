/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:50:16 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 17:00:22 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*rtr;
	size_t			i;

	i = 0;
	rtr = (unsigned char *) b;
	while (i < len)
	{
		rtr[i] = (unsigned char) c;
		i++;
	}
	return ((void *)rtr);
}
