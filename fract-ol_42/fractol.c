/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrb <ohrb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:47:15 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/03 16:58:22 by ohrb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	string(t_fractol *fractol)
{
	fractol->error = "Hello, something is wrong!!\nif you want to run Mandelbrot, use it like this.\n\
	./fractol mandelbrot\nAnd if you want to run Julia, use it like this.\n\
	./fractol julia <real number> <imaginary number>\n";
	fractol->parse = "Hello, something is wrong with your julia numbers.\n\
The numbers must be correct without any characters or a decimal point it the end, just decimal numbers.\n\
NOTE : YOU CAN ADD MULTIPLE DECIMAL POINTS.\nExample ==> ./fractol julia -0.8.35 -0.23.0\n";
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.zoom = 1.0;
	fractol.iter = 550;
	fractol.av = av;
	fractol.ac = ac;
	string(&fractol);
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4 && !ft_strcmp(av[1], "julia") && ft_parse(av[2]) && ft_parse(av[3])))
	{
		fractol.title = av[1];
		f_init(&fractol);
		f_build(&fractol);
		mlx_loop(fractol.init);
	}
	else
	{
		if (ac == 4)
		{
			write(2, fractol.parse, 243);
			exit(1);
		}
		write(2, fractol.error, 197);
		exit(1);
	}
}
