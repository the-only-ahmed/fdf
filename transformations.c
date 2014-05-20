/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 00:00:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/22 00:00:41 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	scale(t_mat s, double x)
{
	s.m_a1 = x;
	s.m_a2 = 0;
	s.m_a3 = 0;
	s.m_a4 = 0;
		s.m_b1 = 0;
		s.m_b2 = x;
		s.m_b3 = 0;
		s.m_b4 = 0;
			s.m_c1 = 0;
			s.m_c2 = 0;
			s.m_c3 = x;
			s.m_c4 = 0;
				s.m_d1 = 0;
				s.m_d2 = 0;
				s.m_d3 = 0;
				s.m_d4 = 1;
	return (s);
}

t_mat	translation(t_mat trans)
{
	trans.m_a1 = 1;
	trans.m_a2 = 0;
	trans.m_a3 = 0;
	trans.m_a4 = 850;
		trans.m_b1 = 0;
		trans.m_b2 = 1;
		trans.m_b3 = 0;
		trans.m_b4 = 500;
			trans.m_c1 = 0;
			trans.m_c2 = 0;
			trans.m_c3 = 1;
			trans.m_c4 = 0;
				trans.m_d1 = 0;
				trans.m_d2 = 0;
				trans.m_d3 = 0;
				trans.m_d4 = 1;

	return (trans);
}

static void		rot_y(t_mat *rotate, int x)
{
	rotate->m_a1 = cosinus(x);
		rotate->m_a2 = 0;
		rotate->m_a3 = sinus(x);
			rotate->m_b1 = 0;
			rotate->m_b2 = 1;
			rotate->m_b3 = 0;
				rotate->m_c1 = sinus(x) * -1;
				rotate->m_c2 = 0;
				rotate->m_c3 = cosinus(x);
}

static void		rot_z(t_mat *rotate, int x)
{
	rotate->m_a1 = cosinus(x);
		rotate->m_a2 = sinus(x) * -1;
		rotate->m_a3 = 0;
			rotate->m_b1 = sinus(x);
			rotate->m_b2 = cosinus(x);
			rotate->m_b3 = 0;
				rotate->m_c1 = 0;
				rotate->m_c2 = 0;
				rotate->m_c3 = 1;
}

void	rotation(t_mat *rotate, char axe)
{
	float	x = 180;

	if (axe == 'x')
	{
		rotate->m_a1 = 1;
		rotate->m_a2 = 0;
		rotate->m_a3 = 0;
			rotate->m_b1 = 0;
			rotate->m_b2 = cosinus(x);
			rotate->m_b3 = sinus(x) * -1;
				rotate->m_c1 = 0;
				rotate->m_c2 = sinus(x);
				rotate->m_c3 = cosinus(x);
	}
	else if (axe == 'y')
		rot_y(rotate, x);
	else
		rot_z(rotate, x);
	rotate->m_a4 = 0;
			rotate->m_b4 = 0;
				rotate->m_c4 = 0;
					rotate->m_d1 = 0;
					rotate->m_d2 = 0;
					rotate->m_d3 = 0;
					rotate->m_d4 = 1;
}

