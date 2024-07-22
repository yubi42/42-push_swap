/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:51:16 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 11:24:53 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_down_a(t_node **head)
{
	ft_rotate_down(head);
	ft_printf("rra\n");
}

void	ft_rotate_down_b(t_node **head)
{
	ft_rotate_down(head);
	ft_printf("rrb\n");
}

void	ft_rotate_down_both(t_node **head1, t_node **head2)
{
	ft_rotate_down(head1);
	ft_rotate_down(head2);
	ft_printf("rrr\n");
}

void	ft_rotate_down(t_node **head)
{
	*head = (*head)->prev;
}
