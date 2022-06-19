/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:18:11 by root              #+#    #+#             */
/*   Updated: 2022/06/19 16:15:40 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	unsigned int	state;
	unsigned int	words;
	unsigned int	i;

	if (!s)
		return (0);
	words = 0;
	state = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			state = 1;
		else
		{
			if (state == 1)
				words++;
			state = 0;
		}
		i++;
	}
	return (words);
}

static int	len_word(char const *str, char c)
{
	unsigned int	size;

	size = 0;
	while (*str && *str != c)
	{
		++size;
		++str;
	}
	return (size);
}

static char	**free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i++])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	words;
	unsigned int	line;
	unsigned int	col;

	words = count_words(s, c);
	tab = (char **)ft_calloc(sizeof(char *), (words + 1));
	if (tab == NULL )
		return (NULL);
	line = 0;
	while (line < words)
	{
		while (*s && *s == c)
			++s;
		tab[line] = (char *)ft_calloc(sizeof(char), len_word(s, c) + 1);
		if (!tab[line])
			return (free_tab(tab));
		col = 0;
		while (*s && *s != c)
			tab[line][col++] = *s++;
		tab[line++][col] = 0;
	}
	tab[line] = 0;
	return (tab);
}
