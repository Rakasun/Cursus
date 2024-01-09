/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:22:06 by yfang             #+#    #+#             */
/*   Updated: 2024/01/09 18:55:18 by yfang            ###   ########.fr       */
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
	int			numarg;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_data;

/*-------------------------------   FUNCTIONS   ------------------------------*/
//	Errors
void	ft_error(void);
//	Utils_check
void	ft_checks(t_data *data);
int		ft_check_order(t_stack **stack_a);
//	Utils_utils
long	ft_atol(const char *str);
void	ft_algorithm(t_data *data);
//	Utils_stack
int		ft_stacksize(t_stack *lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stckadd_back(t_stack **stck, t_stack *new);
t_stack	*ft_stcklast(t_stack *stck);
t_stack	*ft_stcknew(int value);
//	Init
void	ft_target_pos(t_stack *stack_a, t_stack *stack_b);
void	ft_pos(t_stack *stack);
t_stack	*ft_init_a(t_data *data);
//	Moves:
//		-Swap
void	ft_swap_sa(t_data *data);
void	ft_swap_sb(t_data *data);
void	ft_swap_ss(t_data *data);
//		-Push
void	ft_push_pa(t_data *data);
void	ft_push_pb(t_data *data);
//		-Rotate
void	ft_rotate_ra(t_data *data);
void	ft_rotate_rb(t_data *data);
void	ft_rotate_rr(t_data *data);
//		-Rrotate
void	ft_rrotate_rra(t_data *data);
void	ft_rrotate_rrb(t_data *data);
void	ft_rrotate_rrr(t_data *data);
//		-Move
void	ft_algostep(t_data *data);
void	ft_short3(t_data *data);

void	ft_visual(t_data *data);

#endif