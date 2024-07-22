/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:12 by soel-bou          #+#    #+#             */
/*   Updated: 2024/07/20 21:25:40 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "cub3d.h"

//char	*ft_strdup_gnl(char *s1);
char	*ft_strchr(const char *s, int c);
//char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
#endif