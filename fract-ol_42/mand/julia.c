


#include "fractol.h"

int	ft_julia(t_complex cnst, t_complex julia, t_fractol *fractol)
{
	int     i;
	double  x;
	double  y;

	i = 0;
	while (i < fractol->iter)
	{
		x = cnst.real * cnst.real;
		y = cnst.imagine * cnst.imagine;
		if (x + y > 4)
			return (i * 0.3);
		cnst.imagine = 2 * cnst.real * cnst.imagine - julia.imagine;
		cnst.real = x - y + julia.real;
		i++;
	}
	return (0);
}

double	ft_atod(char *str)
{
	double	res;
	double	frac;
	int		i;
	int		sign;

	res = 0.0;
	frac = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res *= 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			res += (str[i++] - '0') * frac;
			frac /= 10.0;
		}
	}
	return (sign * res);
}
