/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 03:18:21 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/22 03:18:23 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_env e)
{
	t_vect	*tmp;
	t_coord	cord;
	int		n;
	int		l;

	tmp = e.v;
	cord.x = -1;
	cord.y = -1;
	n = 0;
	l = 0;
	while (tmp)
	{
		draw_a(cord, tmp, &l, e);
		cord.x = tmp->v_x;
		cord.y = tmp->v_y;
		n++;
		if (n == e.nb_c)
		{
			n = 0;
			cord.x = -1;
		}
		tmp = tmp->next;
	}
	draw_2(tmp, cord, e);
}

t_vect	*draw_a(t_coord cord, t_vect *tmp, int *l, t_env e)
{
	if (cord.x == -1)
		draw_point(e, tmp->v_x + LAR/2, tmp->v_y + LON/2, 0xFF0000);
	else
	{
		if (tmp->v_z || *l)
		{
			if (tmp->v_z)
				*l = 1;
			else
				*l = 0;
			cord.color = 0xFFFFFF;
		}
		else
			cord.color = 0xFF0000;
		draw_seg(e, tmp->v_x + LAR/2, tmp->v_y + LON/2, cord);
	}
	return (tmp);
}

void	draw_2(t_vect *tmp, t_coord cord, t_env e)
{
	int		j;

	j = 0;
	while (j < e.nb_c)
	{
		tmp = e.v;
		cord.x = 0;
		while (cord.x < j)
		{
			cord.x++;
			tmp = tmp->next;
		}
		cord.x = tmp->v_x;
		cord.y = tmp->v_y;
		tmp = draw_2_a(e, tmp);
		if (tmp->v_z)
			cord.color = 0xFFFFFF;
		else
			cord.color = 0xFF0000;
		draw_seg(e, tmp->v_x + LAR / 2, tmp->v_y + LON / 2, cord);
		j++;
	}
}

t_vect	*draw_2_a(t_env e, t_vect *tmp)
{
	int		i;
	i = 0;
	while (i < (e.nb_c * (e.nb_l - 1)))
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}