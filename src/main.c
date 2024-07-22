/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:09:35 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/23 20:31:00 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alt_input(int argc, char **argv, t_handler *data)
{
	char	**new_argv;

	new_argv = NULL;
	new_argv = switch_argv(argv[1]);
	if (!new_argv[2])
		return (0);
	if (!new_argv)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (error_handler(argc, new_argv, data))
		return (1);
	ft_free_argv(&new_argv);
	return (2);
}

int	main(int argc, char **argv)
{
	t_handler	data;
	int			alt;

	if (argc == 1)
		return (0);
	init_data(&data);
	if (argc == 2)
	{
		alt = alt_input(argc, argv, &data);
		if (alt == 0)
			return (0);
		if (alt == 1)
			return (1);
	}
	else if (error_handler(argc, argv, &data))
		return (1);
	sort_handler(&data);
	ft_free(&(data.array_a->head), &data);
	return (0);
}
