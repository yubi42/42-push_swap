/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:09:46 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 22:51:40 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_a(t_handler *data, t_moves *moves)
{
	if (data->array_a->head->index > data->array_a->head->next->index
		&& data->array_a->head->index < (data->size - 1))
		moves->swap += 1;
	if (data->array_a->head->prev->index < data->mid)
		moves->rotate_down += 1;
	if (data->array_a->head->index < data->mid)
		moves->push_a += 1;
	if (data->array_a->size > 2)
		moves->rotate_up += 1;
}

void	operation_b(t_handler *data, t_moves *moves)
{
	if (data->array_b->head->index < data->array_b->head->next->index && data->array_b->head->index > 0)
		moves->swap += 2;
	else
	{
		moves->rotate_up += 2;
	}
}
