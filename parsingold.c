/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:01 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/20 14:21:07 by soel-bou         ###   ########.fr       */
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


char	**alloc_map(int fd)
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
	close(fd);
}

int	checkexistence(t_map_data *data, int id) // 1:NO 2:SO 3:WE 4:EA F:5 C:6 
{
	if (id == 1 && data->info.north)
		return (1);
	if (id == 2 && data->info.south)
		return (1);
	if (id == 3 && data->info.weast)
		return (1);
	if (id == 4 && data->info.east)
		return (1);
	if (id == 5 && data->info.floor)
		return (1);
	if (id == 6 && data->info.ceiling)
		return (1);
	return (0);
}

int checkdirection(char *dir)
{
	if (!dir)
		return (1);
	if (!ft_strcmp(dir, "NO") && !ft_strcmp(dir, "SO") && !ft_strcmp(dir, "WE") && !ft_strcmp(dir, "EA") && !ft_strcmp(dir, "F") && !ft_strcmp(dir, "C"))
		return (0);
	return (1);
}

int checkfile(char *file)
{
	int fd;

	if (!file)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
int set_data(t_map_data *data, char *infos)
{
	if (!ft_strcmp(infos[0], "NO"))
	{
		if (checkexistence(data, 1))
			return (1);
		data->no_path = ft_strdup(infos[1]);
		data->info.north = true;
	}
	else if (!ft_strcmp(infos[0], "SO"))
	{
		if (checkexistence(data, 2))
			return (1);
		data->so_path = ft_strdup(infos[1]);
		data->info.south = true;
	}
	else if (!ft_strcmp(infos[0], "WE"))
	{
		if (checkexistence(data, 3))
			return (1);
		data->we_path = ft_strdup(infos[1]);
		data->info.weast = true;
	}
	else if (!ft_strcmp(infos[0], "EA"))
	{
		if (checkexistence(data, 4))
			return (1);
		data->ea_path = ft_strdup(infos[1]);
		data->info.east = true;
	}
	return (0);
}

void	freesplit(char **list)
{
	int i;

	i = 0;
	while(list[i])
		free(list[i++]);
	free(list);
}

int check_line(t_map_data *data, char *line)
{
	char **infos;

	infos = ft_split(line, ' ');
	if (!checkdirection(infos[0]) || !checkfile(infos[1]) || infos[2] != NULL)
		return (freesplit(infos), 1);
	if(set_data(data, infos));
		return (freesplit(infos), 1);
	freesplit(infos);
	return (0);
}

int	checkinfos(t_map_data *data)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if(check_line(data, data->map[i]))
			return (1);
	}
	
	return (0);
}

int	ft_parsing(const char *file, t_map_data *data)
{
	int	fd;

	if(check_argv(file))
		return (1);
	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (1);
	data->map = alloc_map(fd);
	get_map(file, data->map);
	
}