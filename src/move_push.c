/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:45:22 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 11:24:16 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_to_b(t_array *a, t_array *b)
{
	ft_push(&a->head, &b->head, &a->size, &b->size);
	ft_printf("pb\n");
}

void	ft_push_b_to_a(t_array *b, t_array *a)
{
	ft_push(&b->head, &a->head, &b->size, &a->size);
	ft_printf("pa\n");
}

void	ft_push(t_node **head1, t_node **head2, int *size1, int *size2)
{
	t_node	*temp;

	temp = *head1;
	if (--(*size1) == 0)
		*head1 = NULL;
	else
	{
		*head1 = (*head1)->next;
		(*head1)->prev = temp->prev;
		(*head1)->prev->next = *head1;
	}
	if (++(*size2) == 1)
	{
		*head2 = temp;
		(*head2)->next = *head2;
		(*head2)->prev = *head2;
	}
	else if (*size2 > 1)
	{
		temp->next = *head2;
		temp->prev = (*head2)->prev;
		(*head2)->prev->next = temp;
		(*head2)->prev = temp;
		*head2 = temp;
	}
}
