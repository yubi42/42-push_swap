/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:51:16 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 11:25:26 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_up_a(t_node **head)
{
	ft_rotate_up(head);
	ft_printf("ra\n");
}

void	ft_rotate_up_b(t_node **head)
{
	ft_rotate_up(head);
	ft_printf("rb\n");
}

void	ft_rotate_up_both(t_node **head1, t_node **head2)
{
	ft_rotate_up(head1);
	ft_rotate_up(head2);
	ft_printf("rr\n");
}

void	ft_rotate_up(t_node **head)
{
	*head = (*head)->next;
}
