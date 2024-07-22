/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:58:08 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/22 01:05:09 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_pars_info {
	bool	north;
	bool	south;
	bool	east;
	bool	weast;
	bool	floor;
	bool	ceiling;
}	t_pars_info; 

typedef struct s_map_data {
	char		*f_color;
	char		*c_color;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	char		**cub_map;
	int			h;
	int			w;
	t_pars_info	info;
}	t_map_data;

//ERRORS
void    err_exit(char *s);



#endif