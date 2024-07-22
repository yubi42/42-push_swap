/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:44:04 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 13:42:59 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_check_small_b_to_a(t_array *b, t_array *a, int *cur_pos)
{
	t_node	*temp;

	temp = a->head;
	while (*cur_pos > 0 && b->head->index > temp->prev->index)
	{
		if (b->head->index < temp->prev->index)
		{
			ft_push_b_to_a(b, a);
			return (1);
		}
		ft_rotate_down_a(&a->head);
		temp = temp->prev;
		(*cur_pos)--;
	}
	return (0);
}

int	reverse_check_big_b_to_a(t_array *b, t_array *a, int *cur_pos,
		int array_size)
{
	t_node	*temp;

	temp = a->head;
	while ((*cur_pos > 0 && *cur_pos < array_size
			&& b->head->index < temp->prev->index) || *cur_pos == 0)
	{
		if (b->head->index > temp->index)
		{
			ft_push_b_to_a(b, a);
			return (1);
		}
		ft_rotate_up_a(&a->head);
		temp = temp->next;
		(*cur_pos)++;
	}
	return (0);
}

void	op_reverse_push_b_to_a(t_handler *data, int *cur_pos, int array_size)
{
	if (reverse_check_small_b_to_a(data->array_b, data->array_a, cur_pos))
		return ;
	if (reverse_check_big_b_to_a(data->array_b, data->array_a, cur_pos,
			array_size))
		return ;
	ft_push_b_to_a(data->array_b, data->array_a);
}

void	reverse_sort_b_to_a(t_handler *data, int array_size)
{
	int	cur_pos;
	int	i;

	cur_pos = 0;
	ft_push_b_to_a(data->array_b, data->array_a);
	array_size = array_size - 1;
	i = 1;
	while (array_size-- > 0)
	{
		op_reverse_push_b_to_a(data, &cur_pos, i++);
		if (data->array_b->head == NULL)
			break ;
	}
	while (cur_pos-- > 0)
		ft_rotate_down_a(&data->array_a->head);
}
