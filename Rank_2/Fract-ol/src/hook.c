/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:43:42 by yfang             #+#    #+#             */
/*   Updated: 2023/11/28 13:07:21 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_key_down(t_fractal *f)
{
	double	x;
	double	y;

	x = 2 * 0.02 * f->zoom;
	y = -2 * 0.02 * f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->max_iter = (f->max_iter * 1.1) + 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->max_iter /= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_X))
		f->zoom *= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Z))
		f->zoom /= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->ymv += y;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->ymv -= y;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->xmv += x;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->xmv -= x;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		f->smooth = !f->smooth;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		if (f->color == 4)
			f->color = 0;
		f->color++;
	}
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		movex;
	double		movey;

	f = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (mouse_x < 0 || mouse_x >= WIDTH || mouse_y < 0 || mouse_y >= HEIGHT)
		return ;
	movex = (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	movey = (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->xmv += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	f->ymv += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
}

void	ft_hook(void *param)
{
	t_fractal	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	ft_key_down(f);
	mlx_key_hook(f->mlx, &ft_key_hook, f);
	mlx_scroll_hook(f->mlx, &ft_scroll_hook, f);
	ft_fractol(f);
}
