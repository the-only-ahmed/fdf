/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:00:29 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 15:46:49 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_calculate_words(char const *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			words += 1;
		i++;
	}
	words += 1;
	return (words);
}

static char		**split(char const *s, char c, char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (s[++k] != '\0')
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(**tab) * 255);
		while (s[k] != c && (s[k - (1 + j)] == c || k - j == 0))
		{
			tab[i][j] = s[k];
			j++;
			k++;
		}
		if (tab[i][j - 1] != c && tab[i][j - 1] != '\0')
		{
			tab[i][j] = '\0';
			i++;
		}
	}
	if (s[k] != c)
		i++;
	tab[i] = NULL;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	if (*s == 0)
	{
		tab = (char **)malloc(sizeof(char*));
		tab[0] = (char*)malloc(sizeof(char));
		tab[0] = 0;
		return (tab);
	}
	words = ft_calculate_words(s, c);
	tab = (char**)malloc(sizeof(**tab) * words);
	tab = split(s, c, tab);
	return (tab);
}
