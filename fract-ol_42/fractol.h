/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrb <ohrb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:52:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/03 16:54:26 by ohrb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx_linux/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_complex
{
	double real;
	double imagine;
} t_complex;

typedef struct s_image
{
	void	*image;
	char	*pixels;
	int		bits;
	int		end;
	int		size_line;
} t_image;

typedef struct s_fractol
{
	void	*init;
	void	*window;
	t_image	image;
	char	*title;
	double	lost;
	int		iter;
	double	zoom;
	char	**av;
	int		ac;
	char	*error;
	char	*parse;
} t_fractol;

#define 	HEIGHT	800
#define 	WIDTH	800

int			change_color(int i);
int			ft_strcmp(char *s1, char *s2);
void		f_init(t_fractol *fractol);
void		ft_error(void);
void		f_build(t_fractol *fractol);
int	ft_pixels(t_complex cnst, t_complex julia, t_fractol *fractol);
double		new_dimensions(double axe, double new_min, double new_max, double old_min, double old_max);
t_complex	ft_sum(t_complex z1, t_complex z2);
t_complex	ft_squere(t_complex z);
void		ft_data(t_fractol *fractol);
void		my_pixel_put(int x, int y, t_image *image, int color);
void		ft_events(t_fractol *fractol);
int			zoom(int key, int x, int y, t_fractol *fractol);
int			key_handle(int key, t_fractol *fractol);
int ft_julia(t_complex cnst, t_complex julia, t_fractol *fractol);
double  ft_atod(char *str);
int check_decimal(char *str, int i);
int ft_parse(char *str);


#endif