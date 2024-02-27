/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:47:15 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/27 01:57:19 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.zoom = 1.0;
	fractol.iter = 150;
	
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol.title = av[1];
		f_init(&fractol);
		f_build(&fractol);
		mlx_loop(fractol.init);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
