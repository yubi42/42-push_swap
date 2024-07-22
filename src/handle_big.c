/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:40:45 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 23:05:08 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int counter, int divider)
{
	int	i;

	i = 2;
	while (i++ < counter)
	{
		divider *= divider;
	}
	return (divider);
}

void	choose_nor_rev(t_handler *data, t_it_info *it, int *array_sizes, int i)
{
	int		j;

	j = 0;
	while (i > 0)
	{
		if (it->num_arrays != 1)
		{
			it->array_size = array_sizes[j++];
			if (it->counter != 1)
			{
				while (!(j % ft_pow(it->counter, it->divider) == 0))
					it->array_size += array_sizes[j++];
			}
		}
		if (it->counter % 2 && i % 2)
			reverse_sort_a_to_b(data, it->array_size);
		else if (it->counter % 2 && !(i % 2))
			normal_sort_a_to_b(data, it->array_size);
		else if (!(it->counter % 2) && i % 2)
			normal_sort_b_to_a(data, it->array_size);
		else if (!(it->counter % 2) && !(i % 2))
			reverse_sort_b_to_a(data, it->array_size);
		i--;
	}
}

void	big_handler(t_handler *data, t_it_info *it, int *array_sizes)
{
	int	i;

	i = it->num_arrays;
	it->array_size = data->size;
	choose_nor_rev(data, it, array_sizes, i);
	if (it->num_arrays == 1)
		return ;
	it->num_arrays = it->num_arrays / it->divider;
	it->counter++;
	big_handler(data, it, array_sizes);
}

void	calc_array_size(int **array, t_it_info *it, t_handler *data)
{
	t_size_array	sizes;

	init_sizes(&sizes, it, data);
	while (sizes.i < it->num_arrays)
	{
		(*array)[sizes.i] = data->size / it->num_arrays;
		if (sizes.modulo != 0)
			if (sizes.i % sizes.div == (sizes.div - 1))
				(*array)[sizes.i] = (data->size / it->num_arrays) + 1;
		if (sizes.rest != 0)
		{
			if (sizes.i % sizes.div2 == (sizes.div - (sizes.div / 2))
				&& sizes.counter < sizes.rest)
			{
				if (sizes.i % sizes.div == (sizes.div - 1))
					sizes.i++;
				(*array)[sizes.i] = (data->size / it->num_arrays) + 1;
				sizes.counter++;
			}
		}
		if ((*array)[sizes.i] == 0)
			(*array)[sizes.i] = (data->size / it->num_arrays) + 1;
		sizes.i++;
	}
}

void	big_sort_handler(t_handler *data)
{
	t_it_info	it;
	int			*array_sizes;

	init_it(&it);
	array_sizes = NULL;
	if (data->array_a->size > 49)
	{
		it.num_arrays = 7;
		it.divider = 7;
	}
	if (data->array_a->size > 149)
	{
		it.num_arrays = 45;
		it.divider = 3;
	}
	array_sizes = malloc(sizeof(int) * it.num_arrays);
	if (!array_sizes)
		return ;
	calc_array_size(&array_sizes, &it, data);
	big_handler(data, &it, array_sizes);
	free(array_sizes);
}
