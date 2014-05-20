/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 01:08:30 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/03 03:48:43 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp_maj(char *s1, char *s2)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 1;
	if (s1[i] == '.')
		i++;
	if (s2[j] == '.')
		j++;
	while (((ft_tolower(s1[i]) == ft_tolower(s2[j]) && x)| (s1[i] == s2[j])) && (s1[i] != '\0' || s2[j] != '\0'))
	{
		x = 0;
		j++;
		i++;
	}
	if (s1[i] == '\0' && s2[j] == '\0')
		return (0);
	else
	{
		if (x)
			return (ft_tolower(s1[i]) - ft_tolower(s2[j]));
		else
			return (s1[i] - s2[j]);
	}
}
