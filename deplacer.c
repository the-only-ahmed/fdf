/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 16:46:43 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/17 20:07:07 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect	*multiplication(t_mat m, t_vect *v)
{
	int		x;
	int		y;
	int		z;

	x = v->v_x;
	y = v->v_y;
	z = v->v_z;

	v->v_x = (x * m.m_a1) + (y * m.m_a2) + (z * m.m_a3) + m.m_a4;
	v->v_y = (x * m.m_b1) + (y * m.m_b2) + (z * m.m_b3) + m.m_b4;
	v->v_z = (x * m.m_c1) + (y * m.m_c2) + (z * m.m_c3) + m.m_c4;
	return (v);
}

t_vect	*multi_trans(t_vect *v)
{
	t_vect	*tmp;
	t_mat	trans;
	int		i;

	i = 0;
	tmp = v;
	trans = translation(trans);
	while (tmp)
	{
		tmp = multiplication(trans, tmp);
		tmp = tmp->next;
		i++;
	}
	return (v);
}

t_vect	*multi_rot(t_vect *v)
{
	t_vect	*tmp;
	t_mat	rotate;
	int		i;

	i = 0;
	tmp = v;
	rotation(&rotate, 'z');
	while (tmp)
	{
		tmp = multiplication(rotate, tmp);
		tmp = tmp->next;
		i++;
	}
	return (v);
}

t_vect	*multi_scale(t_vect *v)
{
	t_vect	*tmp;
	t_mat	s;
	int		i;

	i = 0;
	tmp = v;
	while (tmp)
	{
		s = scale(s, 3);
		tmp = multiplication(s, tmp);
		tmp = tmp->next;
		i++;
	}
	return (v);
}
