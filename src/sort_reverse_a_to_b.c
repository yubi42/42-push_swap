/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_a_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:24:15 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 13:42:27 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_check_small_a_to_b(t_array *a, t_array *b, int *cur_pos)
{
	t_node	*temp;

	temp = b->head;
	while (*cur_pos > 0 && a->head->index > temp->prev->index)
	{
		if (a->head->index < temp->prev->index)
		{
			ft_push_a_to_b(a, b);
			return (1);
		}
		ft_rotate_down_b(&b->head);
		temp = temp->prev;
		(*cur_pos)--;
	}
	return (0);
}

int	reverse_check_big_a_to_b(t_array *a, t_array *b, int *cur_pos,
		int array_size)
{
	t_node	*temp;

	temp = b->head;
	while ((*cur_pos > 0 && *cur_pos < array_size
			&& a->head->index < temp->prev->index) || *cur_pos == 0)
	{
		if (a->head->index > temp->index)
		{
			ft_push_a_to_b(a, b);
			return (1);
		}
		ft_rotate_up_b(&b->head);
		temp = temp->next;
		(*cur_pos)++;
	}
	return (0);
}

void	op_reverse_push_a_to_b(t_handler *data, int *cur_pos, int array_size)
{
	if (reverse_check_small_a_to_b(data->array_a, data->array_b, cur_pos))
		return ;
	if (reverse_check_big_a_to_b(data->array_a, data->array_b, cur_pos,
			array_size))
		return ;
	ft_push_a_to_b(data->array_a, data->array_b);
}

void	reverse_sort_a_to_b(t_handler *data, int array_size)
{
	int	cur_pos;
	int	i;

	cur_pos = 0;
	ft_push_a_to_b(data->array_a, data->array_b);
	i = 1;
	array_size = array_size - 1;
	while (array_size-- > 0)
	{
		op_reverse_push_a_to_b(data, &cur_pos, i++);
		if (data->array_a->head == NULL)
			break ;
	}
	while (cur_pos-- > 0)
		ft_rotate_down_b(&data->array_b->head);
}
