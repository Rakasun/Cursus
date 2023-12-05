/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:42:13 by yfang             #+#    #+#             */
/*   Updated: 2023/12/05 14:25:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_control(void)
{
	ft_printf("\033[32m╒═════════════════════════════════════╕\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│     +INTERACTION --> I              │\n");
	ft_printf("\033[32m│     -INTERACTION --> O              │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│ ----------------------------------- │\n");
	ft_printf("\033[0m│                                     │\n");
	ft_printf("\033[0m│               UP --> UP             │\n");
	ft_printf("\033[0m│             DOWN --> DOWN           │\n");
	ft_printf("\033[0m│             LEFT --> LEFT           │\n");
	ft_printf("\033[0m│            RIGHT --> RIGHT          │\n");
	ft_printf("\033[0m│                                     │\n");
	ft_printf("\033[32m│ ----------------------------------- │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│           SMOOTH --> S              │\n");
	ft_printf("\033[32m│            COLOR --> C              │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m╘═════════════════════════════════════╛\n");
}

void	ft_error_usage(void)
{
	ft_printf("\033[32m╒════════╡\033[0m◦•●◉✿ FRA");
	ft_printf("CTOL ✿◉●•◦\033[32m╞════════╕\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│       USAGE: ./fractol [INDEX]      │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│ ----------------------------------- │\n");
	ft_printf("\033[0m│                                     │\n");
	ft_printf("\033[0m│       INDEX  |  FRACTAL             │\n");
	ft_printf("\033[0m│           1 ――> JULIA               │\n");
	ft_printf("\033[0m│           2 ――> MANDELBROT          │\n");
	ft_printf("\033[0m│           3 ――> BURNING SHIP        │\n");
	ft_printf("\033[0m│                                     │\n");
	ft_printf("\033[32m│ ----------------------------------- │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m│       JULIA USAGE:                  │\n");
	ft_printf("\033[32m│           ./fractol 1 -0.8 0.156    │\n");
	ft_printf("\033[32m│                                     │\n");
	ft_printf("\033[32m╘═════════════════════════════════════╛\n");
	exit(0);
}

void	ft_error(int err, t_fractal *f)
{
	if (err == MLX_ERR)
		mlx_terminate(f->mlx);
	if (err == IMG_ERR)
	{
		mlx_delete_image(f->mlx, f->img);
		mlx_terminate(f->mlx);
	}
	perror(mlx_strerror(mlx_errno));
}
