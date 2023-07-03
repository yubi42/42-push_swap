/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:09:35 by yubi42            #+#    #+#             */
/*   Updated: 2023/06/28 21:09:38 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int array_error(long **array, int *array_size)
{
    int i;
    int j;

    i = 0;
    while (i < *array_size)
    {
        j = i + 1;
        if ((*array)[i] > INT_MAX || (*array)[i] < INT_MIN)
            return (1);
        while (j < *array_size)
        {
            if ((*array)[i] == (*array)[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

long	ft_atol(const char *nptr)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*nptr == 9 || *nptr == 10 || *nptr == 11 || *nptr == 12
		|| *nptr == 13 || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	return (result * sign);
}

void	fill_array(char **argv, long **array, int *array_size)
{
	int	i;

	while (argv[*array_size])
		(*array_size)++;
    (*array_size)--;
	*array = (long *)malloc(sizeof(long) * (*array_size));
	if (*array == NULL)
		return ;
	i = 1;
	while (i <= *array_size)
	{
		(*array)[i - 1] = ft_atol(argv[i]);
		i++;
	}
}

int	digit_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))))
				return (1);
            if (j > 10)
                return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_handler(int argc, char **argv, long **array, int *array_size)
{
	if (digit_error(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fill_array(argv, array, array_size);
    if (array_error(array, array_size))
    {
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	long	*array;
    int     array_size;

	array = NULL;
    array_size = 0;
	if (error_handler(argc, argv, &array, &array_size))
		return (1);
	ft_printf("good :)\n");
	return (0);
}
