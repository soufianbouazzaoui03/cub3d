/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:01 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/18 18:17:00 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_argv(char *map)
{
	int	i;

	if (!map)
	{
		ft_putstr_fd("Error\nINVALID ARGS!\n", 2);
		return (1);
	}
	i = 0;
	while (map[i])
		i++;
	if (ft_strncmp(&map[i - 4], ".cub ", 4))
	{
		ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2);
		return (1);
	}
	return (0);
}

int	checkinfos(int fd)
{

	
}

int	ft_parsing(const char *file)
{
	int	fd;

	if(check_argv(file))
		return (1);
	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (1);
	
}