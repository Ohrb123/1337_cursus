/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:02:51 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/26 18:33:38 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	new_dimensions(double axe, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (axe - old_min) / (old_max - old_min) + new_min);
}

t_complex	ft_squere(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imagine * z.imagine);
	res.imagine = 2 * z.real * z.imagine;
	return (res);
}

t_complex	ft_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = (z1.real + z2.real);
	res.imagine = (z1.imagine + z2.imagine);
	return (res);
}
