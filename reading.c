/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 01:08:18 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 03:03:16 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_lecture(char *file, int *nb_l, int *nb_c)
{
	int		fd;
	int		**tab;

	*nb_l = line_nb(file);
	if (*nb_l == -1)
		return (NULL);
	tab = (int**)malloc(sizeof(int) * *nb_l);
	fd = open(file, O_RDONLY);
	tab = remplir(fd, *nb_l, tab, nb_c);
	if (close(fd) == -1)
		return (NULL);
	return (tab);
}

int		line_nb(char *file)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while (get_next_line(fd, &str) > 0)
		i++;
	if (close(fd) == -1)
		return (-1);
	return (i);
}

char	*delete_spaces(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] == ' ' && str[i] == ' ')
		{
			j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		i++;
	}
	return (str);
}

int		**remplir(int fd, int nb_l, int **tab, int *nb_c)
{
	int		i;
	int		j;
	char	*str;
	char	*ch;

	i = 0;
	while (i < nb_l)
	{
		j = 0;
		get_next_line(fd, &str);
		str = delete_spaces(str);
		*nb_c = space_nb(str) + 1;
		tab[i] = (int*)malloc(sizeof(int) * (*nb_c));
		while (j < *nb_c - 1)
		{
			ch = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
			str = ft_strchr(str, ' ') + 1;
			tab[i][j] = ft_atoi(ch);
			j++;
		}
		tab[i][j] = ft_atoi(str);
		i++;
	}
	return (tab);
}

int		space_nb(char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			x++;
		i++;
	}
	return (x);
}
