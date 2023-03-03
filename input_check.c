/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:43:06 by hwang         #+#    #+#                 */
/*   Updated: 2022/10/31 15:31:12 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(void)
{
	write(2, "Please put valid argument!\n", 28);
	write(2, "eg: Mandelbrot\n", 16);
	write(2, "eg: Julia 0.285 0.01\n", 22);
	exit(1);
}

/*
检查Julia的input是否为合格的float。
小数点后最多6位，不掺杂其他字母或符号。
返回0，input合格，返回1，input不合格。
*/
int	check_float(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
		str++;
	if (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (*str && i < 6)
	{
		if (ft_isdigit(*str))
			str++;
		i++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		return (1);
	if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		if (check_float(argv[2]) && check_float(argv[3]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	arg_set(t_fractol *fractol, int argc, char **argv)
{
	if (argc == 2)
		fractol->type = MANDELBROT;
	else
	{
		fractol->type = JULIA;
		fractol->julia = malloc(sizeof(t_complex_nb));
		if (!fractol->julia)
			exit (EXIT_FAILURE);
		fractol->julia->real = ft_atof(argv[2]);
		fractol->julia->imag = ft_atof(argv[3]);
	}
}
