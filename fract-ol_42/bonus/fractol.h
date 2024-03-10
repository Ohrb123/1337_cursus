/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:52:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/10 13:41:52 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "/usr/local/include/mlx.h"
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
	double	right_left;
	double	up_down;
	int		color;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	
} t_fractol;

#define 	HEIGHT	800
#define 	WIDTH	800

int			change_color(int i);
int			ft_strcmp(char *s1, char *s2);
void		f_init(t_fractol *fractol);
void		ft_error(void);
void		f_build(t_fractol *fractol);
int			ft_pixels(t_complex cnst, t_complex julia, t_fractol *fractol);
void		my_pixel_put(int x, int y, t_image *image, int color);
void		ft_events(t_fractol *fractol);
int			zoom(int key, int x, int y, t_fractol *fractol);
int			key_handle(int key, t_fractol *fractol);
int			ft_julia(t_complex cnst, t_complex julia, t_fractol *fractol);
double		ft_atod(char *str);
int			check_decimal(char *str, int i);
int			ft_parse(char *str);

#endif