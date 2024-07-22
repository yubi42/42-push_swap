/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:42:26 by yubi42            #+#    #+#             */
/*   Updated: 2023/07/21 11:07:15 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*mal_str(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* char	**create_arr(char *str, char **argv)
{
	int	i;
	int	j;
	int	new_word;

	new_word = 0;
	i = 0;
	argv[0] = mal_str("placeholder ");
	j = 1;
	while (str[i])
	{
		if (str[i] != ' ' && new_word == 0)
		{
			argv[j] = mal_str(&str[i]);
			if (!argv[j])
			{
				j--;
				while (j >= 0)
					free(argv[j--]);
				free(argv);
				return (NULL);
			}
			new_word = 1;
			j++;
		}
		if (str[i] == ' ')
			new_word = 0;
		i++;
	}
	argv[j] = NULL;
	return (argv);
} */
void	no_mal_free(char **argv, int j)
{
	while (j >= 0)
		free(argv[j--]);
	free(argv);
}

char	**create_arr(char *str, char **argv)
{
	int	j;
	int	new_word;

	new_word = 0;
	argv[0] = mal_str("placeholder ");
	j = 1;
	while (*str)
	{
		if (*str != ' ' && new_word == 0)
		{
			argv[j] = mal_str(&(*str));
			if (!argv[j])
			{
				no_mal_free(argv, j--);
				return (NULL);
			}
			new_word = 1;
			j++;
		}
		if (*str == ' ')
			new_word = 0;
		str++;
	}
	argv[j] = NULL;
	return (argv);
}

char	**switch_argv(char *str)
{
	int		i;
	int		array_size;
	char	**argv;

	array_size = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			array_size++;
			i++;
			if (str[i] == ' ')
				return (NULL);
		}
		else
			i++;
	}
	if (str[0] == ' ' || str[i - 1] == ' ')
		return (NULL);
	argv = (char **)malloc(sizeof(char *) * (array_size + 2));
	if (!argv)
		return (NULL);
	argv = create_arr(str, argv);
	return (argv);
}

void	ft_free_argv(char ***new_argv)
{
	char	**args;
	int		i;

	args = *new_argv;
	i = 0;
	while (args[i])
		i++;
	while (i > 0)
	{
		free(args[i]);
		i--;
	}
	free(args[i]);
	args[i] = NULL;
	free(args);
	*new_argv = NULL;
}
