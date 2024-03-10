/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:47:41 by oelharbi          #+#    #+#             */
/*   Updated: 2024/03/10 13:50:25 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int	f_exit(t_fractol *fractol)
{
	write(1, "Good bye!\n", 10);
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
	double	move;

	move = 0.1 / fractol->zoom;
	if (fractol->zoom < 1.0)
		move = 0.1 * fractol->zoom;
	printf("key ==> %d\n", key);
	if (key == 53) 
		f_exit(fractol);
	else if (key == 124)
		fractol->right_left += move;
	else if (key == 123)
		fractol->right_left -= move;
	else if (key == 125)
		fractol->up_down += move;
	else if (key == 126)
		fractol->up_down -= move;
	else if (key == 48)
		fractol->color += 1000;
	else if (key == 50)
		fractol->color -= 1000;
	else if (key == 69 && fractol->iter <= 500)
		fractol->iter += 20;
	else if (key == 78 && fractol->iter > 20)
		fractol->iter -= 20;
	else
		return (0);
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 69 || key == 78 || key == 48 || key == 50)
		f_build(fractol);
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	double	x_axis;
	double	y_axis;

	if (x >= 0 && y >= 0 && (key == 4 || key == 5))
	{
		x_axis = fractol->x_min + x * ((fractol->x_max - fractol->x_min) / WIDTH);
		y_axis = fractol->y_min + y * ((fractol->y_max - fractol->y_min) / HEIGHT);
		if (key == 4)
			fractol->zoom *= 0.89;
		else if (key == 5)
			fractol->zoom *= 1.07;
		fractol->x_min = x_axis + fractol->zoom * (fractol->x_min - x_axis);
		fractol->x_max = x_axis + fractol->zoom * (fractol->x_max - x_axis);
		fractol->y_min = y_axis + fractol->zoom * (fractol->y_min - y_axis);
		fractol->y_max = y_axis + fractol->zoom * (fractol->y_max - y_axis);
		if (key == 4 || key == 5)
			f_build (fractol);
	}
	return (0);
}

void	ft_events(t_fractol *fractol)
{
	mlx_mouse_hook (fractol->window, zoom, fractol);
	mlx_key_hook(fractol->window, key_handle, fractol);
	mlx_hook(fractol->window, 17, 0, f_exit, fractol);
}

// int    ft_zoom(int keycode, int x, int y, t_data *img)
// {
//     double    mx;
//     double    my;

//     if (y >= 0 && x >= 0 && (keycode == 5 || keycode == 4))
//     {
//         mx = img->x_min + x * ((img->x_max - img->x_min) / img->width);
//         my = img->y_min + y * ((img->y_max - img->y_min) / img->height);
//         if (keycode == 4)
//         {
//             img->zoom = 0.95;
//             img->z1 *= 0.95;
//         }
//         else if (keycode == 5)
//         {
//             img->zoom = 1.05;
//             img->z1 *= 1.05;
//         }
//         img->x_min = mx + img->zoom * (img->x_min - mx);
//         img->x_max = mx + img->zoom * (img->x_max - mx);
//         img->y_min = my + img->zoom * (img->y_min - my);
//         img->y_max = my + img->zoom * (img->y_max - my);
//         ft_draw(*img);
//     }
//     return (0);
// }