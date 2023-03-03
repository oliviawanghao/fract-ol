/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:17:51 by hwang         #+#    #+#                 */
/*   Updated: 2022/10/19 16:00:03 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_fractol(t_fractol *fractol)
{
	if (fractol->type == JULIA)
		free(fractol->julia);
	free(fractol);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (ydelta > 0)
	{
		fractol->scale = fractol->scale * 1.1;
		put_fractol(fractol);
	}
	else if (ydelta < 0)
	{
		fractol->scale = fractol->scale * 0.9;
		put_fractol(fractol);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(fractol->mlx, fractol->g_img);
		mlx_close_window(fractol->mlx);
		mlx_terminate(fractol->mlx);
		free_fractol(fractol);
		exit(EXIT_SUCCESS);
	}
}

/*
1.检查argument是否valid，如果不valid，input_error。
2.初始化fractol，如果失败，exit。
3.再初始化type和julia数字，如果失败，exit。
4.mlx_init，在窗口标题上写上Mandelbrot或者Julia的名字，如果初始化mlx失败，exit。
5.mlx_new_image，创建新的image，如果初始化img失败，exit。
6.mlx_image_to_window，将image加入render queue.
7.put_fractol，把fractol中的type和数字传递给g_img。
8.需要一个scroll_hook来缩放，需要一个key_hook来valid ESC！
9.mlx_delete_image，Once the application request an exit, cleanup.
*/
int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (!arg_check(argc, argv))
		input_error();
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit (EXIT_FAILURE);
	arg_set(fractol, argc, argv);
	fractol->mlx = mlx_init(WIDTH, HEIGHT, argv[1], true);
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->g_img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->g_img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(fractol->mlx, fractol->g_img, 0, 0);
	fractol->scale = 6.0;
	put_fractol(fractol);
	mlx_scroll_hook(fractol->mlx, &scroll_hook, fractol);
	mlx_key_hook(fractol->mlx, &key_hook, fractol);
	mlx_loop(fractol->mlx);
	mlx_delete_image(fractol->mlx, fractol->g_img);
	mlx_terminate(fractol->mlx);
	free_fractol(fractol);
	return (EXIT_SUCCESS);
	return (0);
}
