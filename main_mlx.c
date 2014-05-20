/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:36:52 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/17 20:11:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	int		nb_ca;
	int		nb_la;

	if (ac != 2)
		return (0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, LON, LAR, "42");
	e.tab = ft_lecture(av[1], &nb_la, &nb_ca);
	e.nb_l = nb_la;
	e.nb_c = nb_ca;
	e.v = remplir_vect(e);
	e.v = multi_rot(e.v);
	e.v = multi_scale(e.v);
	e.v = multi_napoli(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}