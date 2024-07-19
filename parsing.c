/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:01 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/19 16:18:07 by soel-bou         ###   ########.fr       */
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


char	**get_big_map(int fd)
{
	char	**map;
	char	*line;
	int		i;
	
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		if (line[0] != '\n')
			i++;
	}
	map = (char **)malloc(i * sizeof(char *));
	if(!map)
		err_exit("Malloc error!");
	return (map);
}

void	get_map(char *file, char **map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit("fd error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
			map[i++] = ft_strdup(line);
	}
	
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