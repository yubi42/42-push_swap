/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:33:24 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 10:26:38 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move(t_moves moves, t_handler *data)
{
	if (moves.push_a == 1)
		ft_push_a_to_b(data->array_a, data->array_b);
	else if (moves.swap == 3)
		ft_swap_both(&(data->array_a->head), &(data->array_b->head));
	else if (moves.rotate_up == 3)
		ft_rotate_up_both(&(data->array_a->head), &(data->array_b->head));
	else if (moves.rotate_down == 3)
		ft_rotate_down_both(&(data->array_a->head), &(data->array_b->head));
	else if (moves.swap == 1)
		ft_swap_a(&(data->array_a->head));
	else if (moves.rotate_up == 1)
		ft_rotate_up_a(&(data->array_a->head));
	else if (moves.rotate_down == 1)
		ft_rotate_down_a(&(data->array_a->head));
	else if (moves.swap == 2)
		ft_swap_b(&(data->array_b->head));
	else if (moves.rotate_up == 2)
		ft_rotate_up_b(&(data->array_b->head));
	else if (moves.rotate_down == 2)
		ft_rotate_down_b(&(data->array_b->head));
	else if (moves.push_b == 1)
		ft_push_b_to_a(data->array_b, data->array_a);
}
