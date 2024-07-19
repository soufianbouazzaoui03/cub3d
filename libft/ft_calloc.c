/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:07 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/16 10:31:50 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptrcalloc;

	ptrcalloc = malloc(count * size);
	if (ptrcalloc == NULL)
		return (NULL);
	ft_memset(ptrcalloc, 0, count * size);
	return (ptrcalloc);
}
