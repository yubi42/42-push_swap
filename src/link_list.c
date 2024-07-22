/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:31:45 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 22:12:21 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_node **head, int *array, int array_size, t_handler *data)
{
	int		i;
	t_node	*temp;

	temp = *head;
	i = 0;
	while (i < array_size)
	{
		while (1)
		{
			if (array[i] == temp->value)
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
	data->size = array_size;
}

void	sort_array(long *array, int array_size, t_handler *data,
		int **sorted_array)
{
	int	i;
	int	j;

	*sorted_array = (int *)malloc(sizeof(int) * array_size);
	(*sorted_array)[0] = array[0];
	i = 1;
	while (i < array_size)
	{
		if (array[i] > (*sorted_array)[i - 1])
			(*sorted_array)[i] = array[i];
		else
		{
			j = i - 1;
			while (j >= 0 && (*sorted_array)[j] > array[i])
			{
				(*sorted_array)[j + 1] = (*sorted_array)[j];
				j--;
			}
			(*sorted_array)[j + 1] = array[i];
		}
		i++;
	}
	data->mid = (array_size / 2);
}

void	create_linked_list(t_node **head, long *array, int array_size)
{
	t_node	*new_node;
	t_node	*temp;
	int		i;

	*head = NULL;
	i = -1;
	while (++i < array_size)
	{
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return ;
		init_new_node(&new_node, array, i);
		if (*head == NULL)
			*head = new_node;
		else
		{
			temp = *head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
	}
	new_node->next = *head;
	(*head)->prev = new_node;
}

void	ft_free(t_node **head, t_handler *data)
{
	t_node	*temp;

	(*head)->prev->next = NULL;
	while ((*head))
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	free(data->array_a);
	free(data->array_b);
}

void	print_linked_list(t_node *head, int size)
{
	t_node	*current;
	int		size2;

	size2 = size;
	current = head;
	while (size)
	{
		ft_printf("%d ", current->value);
		current = current->next;
		size--;
	}
	ft_printf("\n");
	while (size2)
	{
		ft_printf("%d ", current->index);
		current = current->next;
		size2--;
	}
	ft_printf("\n");
}
