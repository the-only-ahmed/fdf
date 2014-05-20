/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 06:32:14 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/21 01:32:30 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat	perspective(t_mat per)
{
	double	f;
	double	zfar;

	f = cotangente(60 / 2);
	zfar = 1000;

	per.m_a1 = 60 / 1.3333;
	per.m_a2 = 0;
	per.m_a3 = 0;
	per.m_a4 = 0;
		per.m_b1 = 0;
		per.m_b2 = f;
		per.m_b3 = 0;
		per.m_b4 = 0;
			per.m_c1 = 0;
			per.m_c2 = 0;
			per.m_c3 = (zfar + 1) / (1 - zfar);
			per.m_c4 = (2 * zfar * 1) / (1 - zfar);
				per.m_d1 = 0;
				per.m_d2 = 0;
				per.m_d3 = -1;
				per.m_d4 = 0;

	return (per);
}

t_vect	*multi_napoli(t_env *e)
{
	t_vect	*tmp;

	tmp = e->v;
	while (tmp)
	{
		tmp->v_x = ((square(2) / (float) 2) *
			(tmp->v_x - tmp->v_y)) + e->nb_c / 2;
		tmp->v_y = (square((float) 2 / (float) 3) * (- tmp->v_z) -
			((float) 1 / square(6)) * (tmp->v_x + tmp->v_y) + e->nb_l / 2);
		tmp = tmp->next;
	}
	return (e->v);
}

t_vect	*multi_perspective(t_vect *v)
{
	t_vect	*tmp;
	t_mat	per;
	int		i;

	i = 0;
	tmp = v;
	while (tmp)
	{
		per = perspective(per);
		tmp = multiplication(per, tmp);
		tmp = tmp->next;
		i++;
	}
	return (v);
}
