/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 01:32:49 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/13 22:03:36 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <mlx.h>

# define PI 3.1415926
# define LON 1500
# define LAR 1500

typedef struct s_segment
{
	int		x;
	int		y;
	int		Dx;
	int		Dy;
	int		x_inc;
	int		y_inc;
}	t_segment;

typedef struct s_coord
{
	double	x;
	double	y;
	int		color;
}	t_coord;

typedef struct	s_vecteur
{
	double				v_x;
	double				v_y;
	double				v_z;
	struct s_vecteur	*next;
}	t_vect;

typedef struct	s_env
{
	int		nb_l;
	int		nb_c;
	int		**tab;
	void	*mlx;
	void	*win;
	t_vect	*v;
}	t_env;

typedef struct 	s_compteur
{
	int		i;
	int		j;
}	t_compt;

typedef struct	s_matrice
{
	double		m_a1;
	double		m_a2;
	double		m_a3;
	double		m_a4;
	double		m_b1;
	double		m_b2;
	double		m_b3;
	double		m_b4;
	double		m_c1;
	double		m_c2;
	double		m_c3;
	double		m_c4;
	double		m_d1;
	double		m_d2;
	double		m_d3;
	double		m_d4;
}	t_mat;

int		**ft_lecture(char *file, int *nb_l, int *nb_c);
int		line_nb(char *file);
int		**remplir(int fd, int nb_l, int **tab, int *nb_c);
int		space_nb(char *str);
void	draw(t_env e);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
void	draw_point(t_env e, int x, int y, int color);
void	draw_seg(t_env e, int x, int y, t_coord cord);
t_vect	*remplir_vect(t_env e);
t_vect	*multi_trans(t_vect *v);
t_vect	*multi_rot(t_vect *v);
double	sinus(int n);
double	cosinus(int n);
t_vect	*multi_scale(t_vect *v);
double	cotangente(int n);
double	tangente(int n);
t_vect	*multi_perspective(t_vect *v);
t_vect	*multiplication(t_mat m, t_vect *v);
t_vect	*multi_napoli(t_env *e);

void	rotation(t_mat *rotate, char axe);
t_mat	translation(t_mat trans);
t_mat	scale(t_mat s, double x);
void	dddd(int color, t_env e, t_segment seg);
void	dessin(t_env e, t_segment seg, int color);
void	draw_vert(t_env e);
double 	square_suite(double rst, double j, double a);
double 	square(double a);
void	draw_2(t_vect *tmp, t_coord cord, t_env e);
t_vect	*draw_2_a(t_env e, t_vect *tmp);
t_vect	*draw_a(t_coord cord, t_vect *tmp, int *l, t_env e);
t_vect	*remplir_vect_3(t_compt comp, t_env *e, t_vect *tmp, t_vect *tmp2);
t_vect	*remplir_vect_2(t_vect *tmp, t_env e, t_compt comp);

#endif /* FDF_H  */
