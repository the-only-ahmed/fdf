/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:05:53 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 20:10:05 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		if (s2[j] == '\0')
			return ((char *) &s1[i - j + 1]);
		i++;
	}
	return (NULL);
}
