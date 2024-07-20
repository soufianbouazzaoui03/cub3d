/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:24:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/20 21:17:25 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**alloc_map(int fd)
// {
// 	char	**map;
// 	char	*line;
// 	int		i;
// 	int		newlines;
	
// 	i = 0;
// 	newlines = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if(!line)
// 			break ;
// 		if (line[0] != '\n' && newlines < 6)
// 		{
// 			newlines++;
// 			i++;
// 		}
// 	}
// 	map = (char **)malloc(i * sizeof(char *));
// 	if(!map)
// 		err_exit("Malloc error!");
// 	return (map);
// }

// void	get_map(char *file, char **map)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	i = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		err_exit("fd error");
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (line[0] != '\n')
// 			map[i++] = ft_strdup(line);
// 	}
// 	close(fd);
// }

// int primarychecks(t_map_data *data)
// {
	
// }

// int	parscolors(t_map_data *data)
// {
	
// }

int	set_data(t_map_data *data, char *file)
{
	int fd;
	int i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while(get_next_line(fd))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	data->map = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		data->map[i++] = ft_strdup(line);
		free(line);
	}
	return (data->map[i] = NULL, 0);
}


// int gettexters(t_map_data *data, char *line, char *dir)
// {
// 	int i;
// 	int end;
// 	char *file;

// 	i = 0;
// 	end = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (!line[i] || line[i] == '\n')
// 		return (1);
// 	while(line[end] && line[end] != ' ' && line[end] != '\t' && line[end] != '\n')
// 		end++;
// 	file = ft_substr(line, i, end);
// 	if (!file)
// 		return (1);
// 	if (!ft_strcmp(dir, "NO"))
// 	{
// 		if(data->no_path != NULL) //deja kayn!!
// 			return (1);
// 		data->no_path = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "SO"))
// 	{
// 		if(data->so_path != NULL) //deja kayn!!
// 			return (1);
// 		data->so_path = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "WE"))
// 	{
// 		if(data->we_path != NULL) //deja kayn!!
// 			return (1);
// 		data->we_path = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "EA"))
// 	{
// 		if(data->ea_path != NULL) //deja kayn!!
// 			return (1);
// 		data->ea_path = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "F"))
// 	{
// 		if(data->f_color != NULL) //deja kayn!!
// 			return (1);
// 		data->f_color = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "C"))
// 	{
// 		if(data->c_color != NULL) //deja kayn!!
// 			return (1);
// 		data->c_color = ft_strdup(file);	
// 	}
// 	return (0);
// }


// int parsdirection(t_map_data *data)
// {
// 	char **map = data->map;
// 	int i;
// 	int j;

// 	i = -1;
// 	while(map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if(map[i][j] == 'N')
// 			{
// 				if(map[i][j + 1] != 'O' || gettexters(data, &map[i][j + 2], "NO"))
// 					return (1);
// 				break ;
// 			}
// 			else if(map[i][j] == 'S')
// 			{
// 				if(map[i][j + 1] != 'O' || gettexters(data, &map[i][j + 2], "SO"))
// 					return (1);
// 				break ;
// 			}
// 			else if(map[i][j] == 'W')
// 			{
// 				if(map[i][j + 1] != 'E' || gettexters(data, &map[i][j + 2], "WE"))
// 					return (1);
// 				break ;
// 			}
// 			else if(map[i][j] == 'E')
// 			{
// 				if(map[i][j + 1] != 'A' || gettexters(data, &map[i][j + 2], "EA"))
// 					return (1);
// 				break ;
// 			}
// 			else if(map[i][j] != '1' && map[i][j] != ' ' && map[i] != '\t' && map[i] != '\n')
// 				return (1);
// 			else if(map[i][j] == '1')
// 				return (1);
// 		}
// 	}	
// }

int	parsargs(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) <= 4)
		return (ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2), 1);
	while (argv[1][i])
		i++;
	if (ft_strncmp(&argv[1][i - 4], ".cub ", 4))
	{
		ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2);
		return (1);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (ft_putstr_fd("Error\nCan't open the mapfile\n", 2), 1);
	return (0);
}

void	ft_parsing(int argc, char **argv, t_map_data *data)
{
	if (parsargs(argc, argv))
		exit(1);
	if(set_data(data, argv[1]))
		exit(1);
	int i = 0;
	while(data->map[i])
	{
		printf("%s", data->map[i]);
	}
	
}

int main(int argc, char **argv)
{
	t_map_data data;
	ft_parsing(argc, argv, &data);
}