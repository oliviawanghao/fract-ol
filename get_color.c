/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:48:14 by hwang         #+#    #+#                 */
/*   Updated: 2022/10/19 14:55:57 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(int n)
{
	uint32_t	color;

	if (n == 50)
		color = 0x000000FF;
	if (n < 50 && n >= 30)
		color = 0xFF0000FF;
	if (n < 38 && n >= 30)
		color = 0xFF6961FF;
	if (n < 30 && n >= 23)
		color = 0xFFFF00FF;
	if (n < 23 && n >= 17)
		color = 0x00FF00FF;
	if (n < 17 && n >= 12)
		color = 0xCFF0CCFF;
	if (n < 12 && n >= 8)
		color = 0x00FFFFFF;
	if (n < 8 && n >= 5)
		color = 0xCCCCFFFF;
	if (n < 5 && n >= 3)
		color = 0xB5EAD7FF;
	if (n < 3 && n >= 2)
		color = 0x00FFFFFF;
	if (n < 2)
		color = 0x0000FFFF;
	return (color);
}

uint32_t	get_mandelbrot_color(double real_x, double real_y)
{
	double		temp;
	double		a;
	double		b;
	int			n;
	uint32_t	color;

	a = 0;
	b = 0;
	n = 0;
	while (pow(a, 2) + pow(b, 2) < 4 && n < 50)
	{
		temp = pow(a, 2) - pow(b, 2) + real_x;
		b = 2 * a * b + real_y;
		a = temp;
		n++;
	}
	color = get_color(n);
	return (color);
}

uint32_t	get_julia_color(double real_x, double real_y,
				double julia_real, double julia_imag)
{
	double		temp;
	double		a;
	double		b;
	int			n;
	uint32_t	color;

	n = 0;
	a = real_x;
	b = real_y;
	while (pow(a, 2) + pow(b, 2) < 4 && n < 50)
	{
		temp = pow(a, 2) - pow(b, 2) + julia_real;
		b = 2 * a * b + julia_imag;
		a = temp;
		n++;
	}
	color = get_color(n);
	return (color);
}
