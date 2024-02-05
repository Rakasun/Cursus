/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:34:45 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 18:25:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_messages(t_data *data, char *order)
{
	if (ft_strncmp(order, "sa\n", 3) == 0)
		return (ft_swap_sa(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "sb\n", 3) == 0)
		return (ft_swap_sb(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "ss\n", 3) == 0)
		return (ft_swap_ss(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "pa\n", 3) == 0)
		return (ft_push_pa(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "pb\n", 3) == 0)
		return (ft_push_pb(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "ra\n", 3) == 0)
		return (ft_rotate_ra(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "rb\n", 3) == 0)
		return (ft_rotate_rb(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "rr\n", 3) == 0)
		return (ft_rotate_rr(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "rra\n", 4) == 0)
		return (ft_rrotate_rra(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrb\n", 4) == 0)
		return (ft_rrotate_rrb(data, 1), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrr\n", 4) == 0)
		return (ft_rrotate_rrr(data, 1), EXIT_SUCCESS);
	return (ft_printf("Error\n"), EXIT_FAILURE);
}

void	ft_checker(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_messages(data, line) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
		free(line);
		line = get_next_line(0);
	}
}

void	ft_check_ok(t_data *data)
{
	if (ft_check_order(&data->stack_a) && data->stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (0);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (0);
	else if (ac == 2)
		data->arg = ft_split(av[1], ' ');
	else
		data->arg = ++av;
	ft_checks(data);
	data->stack_a = ft_init_a(data);
	ft_checker(data);
	ft_check_ok(data);
	ft_free_stack(&data->stack_a);
	ft_free_stack(&data->stack_b);
	if (ac == 2)
		ft_free2(data->arg);
	free(data);
	return (0);
}
