/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 00:46:43 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/22 00:46:46 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_env e, int x, int y, int color)
{
	mlx_pixel_put(e.mlx, e.win, x, y, color);
	mlx_pixel_put(e.mlx, e.win, x, y + 1, color);
	mlx_pixel_put(e.mlx, e.win, x + 1, y + 1, color);
	mlx_pixel_put(e.mlx, e.win, x, y, color);
}

void	draw_seg(t_env e, int x, int y, t_coord cord)
{
	t_segment	seg;

	seg.x = x;
	seg.y = y;
	seg.Dx = abs((cord.x  + LAR/2) - x);
	seg.Dy = abs((cord.y + LON/2) - y);
	if (x > (cord.x + LAR/2))
		seg.x_inc = -1;
	else
		seg.x_inc = 1;
	if (y > (cord.y + LON/2))
		seg.y_inc = -1;
	else
		seg.y_inc = 1;
	dddd(cord.color, e, seg);
}

void	dddd(int color, t_env e, t_segment seg)
{
	int		i;
	int		erreur;

	if (seg.Dx > seg.Dy)
	{
		erreur = seg.Dx / 2;
		i = 0;
		while (i < seg.Dx)
		{
			seg.x += seg.x_inc;
			erreur += seg.Dy;
			if (erreur > seg.Dx)
			{
				erreur -= seg.Dx;
				seg.y += seg.y_inc;
			}
			draw_point(e, seg.x, seg.y, color);
			i++;
		}
	}
	else
		dessin(e, seg, color);
}

void	dessin(t_env e, t_segment seg, int color)
{
	int		erreur;
	int		i;

	erreur = seg.Dy / 2;
	i = 0;
	while (i < seg.Dy)
	{
		seg.y += seg.y_inc;
		erreur += seg.Dx;
		if (erreur > seg.Dy)
		{
			erreur -= seg.Dy;
			seg.x += seg.x_inc;
		}
		draw_point(e, seg.x, seg.y, color);
		i++;
	}
}

void	draw_vert(t_env e)
{
	t_vect	*tmp;
	t_vect	*tmp2;
	t_coord cord;
	int		a;

	tmp = e.v;
	tmp2 = e.v;
	a = 0;
	while (a <= e.nb_c)
	{
		a++;
		tmp2 = tmp2->next;
	}
	while (tmp && tmp2)
	{
		if (tmp->v_z || tmp2->v_z)
		{
			cord.x = tmp2->v_x;
			cord.y = tmp2->v_y;
			cord.color = 0xFFFFFF;
			draw_seg(e, tmp->v_x + LAR / 2, tmp->v_y + LON / 2, cord);
		}
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
}