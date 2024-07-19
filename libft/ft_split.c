/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:05:46 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 16:38:20 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(const char *s, char c)
{
	int	numofwords;
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	numofwords = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			numofwords++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (numofwords);
}

static char	*ft_fill(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

void static	ft_initia(size_t *i, size_t *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**list;
	size_t	i;
	size_t	j;
	int		start;

	ft_initia(&i, &j, &start);
	list = (char **)ft_calloc(wordcounter(s, c) + 1, sizeof(char *));
	if (!list)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i] == '\0') && start >= 0)
		{
			list[j] = ft_fill(s, start, i);
			if (!list[j])
				return (ft_free(list, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (list);
}
