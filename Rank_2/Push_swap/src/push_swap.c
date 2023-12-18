/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2023/12/18 19:38:20 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 1)
		return (0);
	else if (ac == 2)
		data->arg = ft_split(av[1], ' ');
	else
		data->arg = av;
	ft_check_ifnum(data);
	if (ft_check_repeat(data) == 1 || ft_check_order(data) == 1)
		ft_error();
	free(data);
	return (0);
}
