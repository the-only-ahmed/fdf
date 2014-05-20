/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:24:24 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/23 23:34:06 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) malloc(sizeof(unsigned char) * n);
	ft_memcpy(str, s2, n);
	ft_memcpy(s1, str, n);
	return (s1);
}
