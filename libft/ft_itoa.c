/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:28:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/11/23 04:40:24 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		reverse(int n, int *length)
{
	int		rev;

	rev = 0;
	if (n == 0)
		*length = 1;
	while (n > 0)
	{
		rev *= 10;
		rev += n % 10;
		n /= 10;
		(*length)++;
	}
	return (rev);
}

static int		negative(int *n, int *length)
{
	int		neg;

	neg = 0;
	if (*n < 0)
	{
		neg = 1;
		(*length)++;
		*n *= -1;
	}
	return (neg);
}

char	*ft_itoa(int n)
{
	int		rev;
	int		length;
	int		neg;
	int		i;
	char	*str;

	length = 0;
	neg = negative(&n, &length);
	rev = reverse(n, &length);
	str = (char*)malloc(sizeof(char) * (length + 1));
	i = 0;
	if (neg)
	{
		str[0] = '-';
		i++;
	}
	while (i < length)
	{
		str[i] = (rev % 10) + '0';
		rev /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
