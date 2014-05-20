/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 23:39:12 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/17 20:17:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw(*e);
	draw_vert(*e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit (0);
	return (0);
}