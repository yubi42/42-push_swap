/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:56:48 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 22:39:14 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node **head)
{
	ft_swap(head);
	ft_printf("sa\n");
}

void	ft_swap_b(t_node **head)
{
	ft_swap(head);
	ft_printf("sb\n");
}

void	ft_swap_both(t_node **head1, t_node **head2)
{
	ft_swap(head1);
	ft_swap(head2);
	ft_printf("ss\n");
}

void	ft_swap(t_node **head)
{
	t_node	*old;
	t_node	*new;

	old = *head;
	new = (*head)->next;
	new->prev = old->prev;
	old->prev->next = new;
	old->prev = new;
	old->next = new->next;
	new->next->prev = old;
	new->next = old;
	*head = new;
}
