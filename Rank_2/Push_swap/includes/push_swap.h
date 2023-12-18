/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:22:06 by yfang             #+#    #+#             */
/*   Updated: 2023/12/18 19:29:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "Libft/libft.h"
// Global
# include <unistd.h>
# include <stdlib.h>

/*--------------------------------   MACROS   --------------------------------*/
// Int max min
# define MAX 2147483647
# define MIN -2147483648

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	char		**arg;
	int			lst_size;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_data;

/*-------------------------------   FUNCTIONS   ------------------------------*/
//	Errors
void	ft_error(void);
//	Utils_check
void	ft_check_ifnum(t_data *data);

#endif