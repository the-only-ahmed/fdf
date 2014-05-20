/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:24:27 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/26 10:57:18 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*str == c)
			return ((void*)str);
		str++;
		i++;
	}
	return (NULL);
}
