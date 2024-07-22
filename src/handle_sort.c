/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:04:01 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 22:53:52 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_wrong_start(t_handler *data, int checker_a, int checker_b,
		t_moves *moves)
{
	if (checker_a == WRONG_START)
	{
		if (data->array_a->head->index <= data->mid)
			moves->rotate_down += 1;
		else
			moves->rotate_up += 1;
	}
	if (checker_b == WRONG_START)
	{
		if (data->array_b->head->index >= data->mid)
			moves->rotate_down += 2;
		else
			moves->rotate_up += 2;
	}
}

int	check_order_a(t_node *head, int array_size, int total_size)
{
	int		i;
	int		gap;
	t_node	*temp;

	i = 0;
	gap = 0;
	temp = head;
	while (i++ < array_size)
	{
		if (temp->index > temp->next->index)
			gap++;
		temp = temp->next;
	}
	if (gap == 1 && head->prev->index == (total_size - 1))
		return (DONE);
	if (gap == 1)
		return (WRONG_START);
	return (WRONG_ORDER);
}

int	check_order_b(t_node *head, int array_size)
{
	int	i;
	int	gap;

	i = 0;
	gap = 0;
	if (head->value == head->next->value)
		gap = 1;
	else
	{
		while (i++ < array_size)
		{
			head = head->next;
			if (head->value < head->next->value)
				gap++;
		}
	}
	if (gap == 1 && (head->value > head->prev->value
			|| head->value == head->next->value))
		return (DONE);
	if (gap == 1)
		return (WRONG_START);
	return (WRONG_ORDER);
}

void	small_handler(t_handler *data)
{
	int		checker_a;
	int		checker_b;
	t_moves	moves;

	init_moves(&moves);
	checker_b = 0;
	checker_a = check_order_a(data->array_a->head, data->array_a->size,
			data->size);
	if (data->array_b->head != NULL)
		checker_b = check_order_b(data->array_b->head, data->array_b->size);
	if (checker_a == DONE && checker_b == 0)
		return ;
	sort_wrong_start(data, checker_a, checker_b, &moves);
	if (checker_a == WRONG_ORDER || (checker_b != 0
			&& data->array_a->head->value < data->array_b->head->value))
		operation_a(data, &moves);
	if (checker_b == WRONG_ORDER)
		operation_b(data, &moves);
	if (checker_a == DONE && checker_b == DONE)
		moves.push_b += 1;
	print_move(moves, data);
	small_handler(data);
}

void	sort_handler(t_handler *data)
{
	if (data->array_a->size < 15)
		small_handler(data);
	else
	{
		big_sort_handler(data);
	}
}
