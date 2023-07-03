/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:31:45 by yubi42            #+#    #+#             */
/*   Updated: 2023/06/28 22:51:48 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int		ft_printf(const char *str, ...);
void	check_type(char c, va_list list, int *count);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned long num, char c, int *count);
void	ft_putnbr(long num, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putpoint(unsigned long num, int *count); */

void create_linked_list(t_node **head, int *array, int array_size)
{
t_node  *new_node;
t_node  *current_node;
int i;

    *head = NULL; 
    i = -1;
    while (++i < array_size)
    {
        new_node = malloc(sizeof(t_node));
        if (new_node == NULL)
            return;
        new_node->value = array[i];
        new_node->next = NULL;
        if (*head == NULL)
            *head = new_node;
        else
        {
            t_node *current = *head;
            while (current->next != NULL)
                current = current->next;
            current->next = new_node;
        }
    }
}

void    init_data(t_handler *data)
{
	data->array_a = NULL;
	data->array_b = NULL;
	data->array_size = 0;
	data->array_mid = 0;
	data->switch_a = FALSE;
	data->switch_b = FALSE;
	data->rotate_a = FALSE;
	data->rotate_b = FALSE;
}

void print_linked_list(t_node *head)
{
    t_node *current = head;
    while (current != NULL)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    int array[] = {3, 2, 1};
    t_handler   data;
    int array_size;

    array_size = sizeof(array) / sizeof(array[0]);
    init_data(&data);
    create_linked_list(&data.array_a, array, array_size);
    ft_printf("Array A: ");
    print_linked_list(data.array_a);
    return (0);
}