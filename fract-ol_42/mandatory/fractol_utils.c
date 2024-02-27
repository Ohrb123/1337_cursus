/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:02:49 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/27 01:20:31 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	perror("Allocation problem!\n");
	exit(1);
}

void	f_init(t_fractol *fractol)
{
	fractol->init = mlx_init();
	if (!fractol->init)
		ft_error();
	fractol->window = mlx_new_window(fractol->init, HEIGHT, WIDTH, fractol->title);
	if (!fractol->window)
	{
		free (fractol->init);
		ft_error();
	}
	fractol->image.image = mlx_new_image(fractol->init, HEIGHT, WIDTH);
	if (!fractol->image.image)
	{
		mlx_destroy_window(fractol->init, fractol->window);
		free (fractol->init);
		ft_error();
	}
	fractol->image.pixels = mlx_get_data_addr(fractol->image.image, &fractol->image.bits, &fractol->image.size_line, &fractol->image.end);
	ft_events(fractol);
}

int	change_color(int i)
{
	int	red;
	int	green;
	int	blue;

	red = (i * 11) % 256;
	green = (i * 5) % 256;
	blue = (i * 13) % 256;
	return ((red << 16) | (green << 8) | blue);
}

int	ft_pixels(t_complex cnst, t_fractol *fractol)
{
	t_complex	z;
	int			i;
	double		x;
	double		y;

	z.real = 0;
	z.imagine = 0;
	i = 0;
	while (i < fractol->iter)
	{
		x = z.real * z.real;
		y = z.imagine * z.imagine;
		if (x + y > 4)
			return (change_color(i * 0.5));
		else
			z.imagine = 2 * z.imagine * z.real + cnst.imagine;
		z.real = x - y + cnst.real;
		i++;
	}
	return (change_color(0));
}

void	f_build(t_fractol *fractol)
{
	int			x;
	int			y;
	int			color;
	t_complex	z;
	t_complex	point;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH * fractol->zoom;
			z.imagine = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * fractol->zoom;
			color = ft_pixels(z, fractol);
			my_pixel_put(x, y, &fractol->image, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->init, fractol->window, fractol->image.image, 0, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}