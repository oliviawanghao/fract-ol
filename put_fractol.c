/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_fractol.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:39:27 by hwang         #+#    #+#                 */
/*   Updated: 2022/10/18 17:38:05 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_real_x(int pixel_x, double scale)
{
	double	real_x;

	real_x = ((double)pixel_x - (double)WIDTH / 2) * (double)scale
		/ (double)WIDTH;
	return (real_x);
}

double	get_real_y(int pixel_y, double scale)
{
	double	real_y;

	real_y = ((double)HEIGHT / 2 - (double)pixel_y) * (double)scale
		/ (double)WIDTH;
	return (real_y);
}

void	put_fractol(t_fractol *fractol)
{
	int		pixel_x;
	int		pixel_y;
	double	real_x;
	double	real_y;

	pixel_x = 0;
	while (pixel_x < WIDTH)
	{
		real_x = get_real_x(pixel_x, fractol->scale);
		pixel_y = 0;
		while (pixel_y < HEIGHT)
		{
			real_y = get_real_y(pixel_y, fractol->scale);
			if (fractol->type == MANDELBROT)
				mlx_put_pixel(fractol->g_img, pixel_x, pixel_y,
					get_mandelbrot_color(real_x, real_y));
			else
				mlx_put_pixel(fractol->g_img, pixel_x, pixel_y,
					get_julia_color(real_x, real_y, fractol->julia->real,
						fractol->julia->imag));
			pixel_y++;
		}
		pixel_x++;
	}
}
