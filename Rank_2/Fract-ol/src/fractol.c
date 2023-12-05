/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:58:11 by yfang             #+#    #+#             */
/*   Updated: 2023/12/05 14:16:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_check_arg(int ac, char **av, t_fractal *f)
{
	if (ac != 2)
	{
		if (ac != 4 || av[1][0] != '1' || av[1][1])
			ft_error_usage();
		else if (ft_double_check(av[2]) == 1 && ft_double_check(av[3]) == 1)
			f->jul_arg = (t_ncom){ft_atof(av[2]), ft_atof(av[3])};
		else
			ft_error_usage();
	}
	else if (av[1][0] == '1')
		f->jul_arg = (t_ncom){-0.8, 0.156};
	else if (av[1][0] < '1' || av[1][0] > '3' || av[1][1])
		ft_error_usage();
	ft_control();
	f->f_type = ft_atoi(av[1]);
}

void	ft_init_f(t_fractal *f)
{
	f->color = 0;
	f->smooth = false;
	ft_name(f);
	ft_f_type(f);
	f->zoom = 3.5;
	f->max_iter = 35;
}

void	ft_opwindow(t_fractal *f)
{
	ft_init_f(f);
	f->mlx = mlx_init(WIDTH, HEIGHT, f->name, false);
	if (!f->mlx)
		ft_error(MLX_ERR, f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(IMG_ERR, f);
	ft_fractol(f);
	mlx_loop_hook(f->mlx, &ft_hook, f);
	mlx_loop(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
}

int	main(int ac, char **av)
{
	t_fractal	f;

	ft_check_arg(ac, av, &f);
	ft_opwindow(&f);
	return (0);
}
