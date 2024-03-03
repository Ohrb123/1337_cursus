/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrb <ohrb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:41 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/03 15:06:15 by ohrb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int	f_exit(t_fractol *fractol)
{
	mlx_destroy_window(fractol->init, fractol->window);
	exit(0);
}

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	i;

	i = (y * image->size_line) + (x * (image->bits / 8));
	*(unsigned int *)(image->pixels + i) = color;
}

int	key_handle(int key, t_fractol *fractol)
{
	if (key == 65307) //Need to correct with mac key!!!
	{
		write(1, "Good bye!\n", 10);
		f_exit(fractol);
	}
	else
		return (0);
	f_build(fractol);
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (key == 4)
		fractol->zoom *= 0.80; //need to be smooth
	else if (key == 5)
		fractol->zoom *= 1.07; //need to be smooth
	else
		return (0);
	f_build (fractol);
	return (0);
}

void	ft_events(t_fractol *fractol)
{
	mlx_mouse_hook (fractol->window, zoom, fractol);
	mlx_key_hook(fractol->window, key_handle, fractol);
	mlx_hook(fractol->window, 17, 0, f_exit, fractol);
}