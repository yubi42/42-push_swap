/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:25:45 by jborner           #+#    #+#             */
/*   Updated: 2023/06/18 18:32:43 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>

// printf

int		ft_printf(const char *str, ...);
void	check_type(char c, va_list list, int *count);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned long num, char c, int *count);
void	ft_putnbr(long num, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putpoint(unsigned long num, int *count);

#endif