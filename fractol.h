/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:50:16 by hwang         #+#    #+#                 */
/*   Updated: 2022/10/31 11:36:01 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"

# define WIDTH 900
# define HEIGHT 600
# define MANDELBROT 0
# define JULIA 1

typedef struct s_complex_nb
{
	double	real;
	double	imag;
}	t_complex_nb;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	double			scale;
	int				type;
	t_complex_nb	*julia;
}	t_fractol;

void		input_error(void);
int			arg_check(int argc, char **argv);
void		arg_set(t_fractol *fractol, int argc, char **argv);
void		put_fractol(t_fractol *fractol);
uint32_t	get_mandelbrot_color(double real_x, double real_y);
uint32_t	get_julia_color(double real_x, double real_y,
				double julia_real, double julia_imag);

#endif