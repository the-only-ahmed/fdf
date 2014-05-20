/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:33:51 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/20 17:43:46 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect	*remplir_vect_2(t_vect *tmp, t_env e, t_compt comp)
{
	tmp = (t_vect*)malloc(sizeof(t_vect));
	tmp->v_x = comp.i * 25 + e.tab[comp.i][comp.j] - ((double) e.nb_c / 2);
	tmp->v_y = ((comp.j * 25 + e.tab[comp.i][comp.j]) / 2) -
				(double) (e.nb_l / 2);
	tmp->v_z = e.tab[comp.i][comp.j] * 3;
	tmp->next = NULL;
	return (tmp);
}

t_vect	*remplir_vect_3(t_compt comp, t_env *e, t_vect *tmp, t_vect *tmp2)
{
	if (comp.i == 0 && comp.j == 0)
	{
		tmp2 = tmp;
		e->v = tmp;
	}
	else
	{
		tmp2->next = tmp;
		tmp2 = tmp2->next;
	}
	return (tmp2);
}

t_vect	*remplir_vect(t_env e)
{
	t_vect	*tmp;
	t_vect	*tmp2;
	t_compt	comp;

	comp.i = 0;
	tmp = e.v;
	tmp2 = NULL;
	while (comp.i < e.nb_l)
	{
		comp.j = 0;
		while (comp.j < e.nb_c)
		{
			tmp = remplir_vect_2(tmp2, e, comp);
			tmp2 = remplir_vect_3(comp, &e, tmp, tmp2);
			comp.j++;
			tmp = tmp->next;
		}
		comp.i++;
	}
	return (e.v);
}
