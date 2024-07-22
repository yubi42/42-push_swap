/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:42:08 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 22:11:31 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_handler *data)
{
	data->array_a = (t_array *)malloc(sizeof(t_array));
	data->array_b = (t_array *)malloc(sizeof(t_array));
	data->array_a->head = NULL;
	data->array_b->head = NULL;
	data->array_a->size = 0;
	data->array_b->size = 0;
	data->size = 0;
	data->mid = 0;
}

void	init_moves(t_moves *moves)
{
	moves->swap = 0;
	moves->rotate_up = 0;
	moves->rotate_down = 0;
	moves->push_a = 0;
	moves->push_b = 0;
}

void	init_it(t_it_info *it)
{
	it->counter = 1;
	it->num_arrays = 3;
	it->divider = 3;
	it->array_size = 0;
}

void	init_new_node(t_node **new_node, long *array, int i)
{
	(*new_node)->value = array[i];
	(*new_node)->index = 0;
	(*new_node)->next = NULL;
	(*new_node)->prev = NULL;
}

void	init_sizes(t_size_array *sizes, t_it_info *it, t_handler *data)
{
	sizes->modulo = data->size % it->num_arrays;
	sizes->div = 0;
	sizes->rest = 0;
	sizes->div2 = 0;
	sizes->i = 0;
	sizes->counter = 0;
	if (sizes->modulo != 0)
		sizes->div = (it->num_arrays / sizes->modulo) + 1;
	if (sizes->modulo == 1)
		sizes->div = (it->num_arrays / 2) + 1;
	if (sizes->div != 0)
		sizes->rest = data->size - ((data->size / it->num_arrays)
				* it->num_arrays + (it->num_arrays / sizes->div));
	if (sizes->rest != 0)
		sizes->div2 = (it->num_arrays / sizes->rest);
}
