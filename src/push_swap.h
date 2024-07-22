/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:25:45 by jborner           #+#    #+#             */
/*   Updated: 2023/07/23 22:11:56 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// macros

# define TRUE 1
# define FALSE 0
# define DONE 1
# define WRONG_START 2
# define WRONG_ORDER -1
# define UP 1
# define DOWN 2

// structs

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_array
{
	struct s_node	*head;
	int				size;
}					t_array;

typedef struct s_handler
{
	struct s_array	*array_a;
	struct s_array	*array_b;
	int				size;
	int				mid;
}					t_handler;

// values of each move: 1 == a moves, 2 == b moves, 3 == both move

typedef struct s_moves
{
	int				swap;
	int				rotate_up;
	int				rotate_down;
	int				push_a;
	int				push_b;
}					t_moves;

typedef struct s_it_info
{
	int				counter;
	int				num_arrays;
	int				divider;
	int				array_size;
}					t_it_info;

typedef struct s_size_array
{
	int				modulo;
	int				div;
	int				rest;
	int				div2;
	int				i;
	int				counter;
}					t_size_array;

// alt input

char				*mal_str(char *str);
void				no_mal_free(char **argv, int j);
char				**create_arr(char *str, char **argv);
char				**switch_argv(char *str);
void				ft_free_argv(char ***new_argv);

// choose operation

void				operation_a(t_handler *data, t_moves *moves);
void				operation_b(t_handler *data, t_moves *moves);

// error handling

int					array_error(long **array, int *array_size);
long				ft_atol(const char *nptr);
void				fill_array(char **argv, long **array, int *array_size);
int					digit_error(int argc, char **argv);
int					error_handler(int argc, char **argv, t_handler *data);

// init structs

void				init_data(t_handler *data);
void				init_moves(t_moves *moves);
void				init_it(t_it_info *it);
void				init_new_node(t_node **new_node, long *array, int i);
void				init_sizes(t_size_array *sizes, t_it_info *it,
						t_handler *data);

// handle big

int					ft_pow(int counter, int divider);
void				choose_nor_rev(t_handler *data, t_it_info *it,
						int *array_sizes, int i);
void				big_handler(t_handler *data, t_it_info *it,
						int *array_sizes);
void				calc_array_size(int **array, t_it_info *it,
						t_handler *data);
void				big_sort_handler(t_handler *data);

// handle sort

void				sort_wrong_start(t_handler *data, int checker_a,
						int checker_b, t_moves *moves);
int					check_order_a(t_node *head, int array_size, int total_size);
int					check_order_b(t_node *head, int array_size);
void				small_handler(t_handler *data);
void				sort_handler(t_handler *data);

// link list

void				create_linked_list(t_node **head, long *array,
						int array_size);
void				ft_free(t_node **head, t_handler *data);
void				print_linked_list(t_node *head, int size);
void				fill_index(t_node **head, int *array, int array_size,
						t_handler *data);
void				sort_array(long *array, int array_size, t_handler *data,
						int **sorted_array);

// move_push

void				ft_push_a_to_b(t_array *a, t_array *b);
void				ft_push_b_to_a(t_array *b, t_array *a);
void				ft_push(t_node **head1, t_node **head2, int *size1,
						int *size2);

// move_rotate_down

void				ft_rotate_down_a(t_node **head);
void				ft_rotate_down_b(t_node **head);
void				ft_rotate_down_both(t_node **head1, t_node **head2);
void				ft_rotate_down(t_node **head);

// move_rotate_up

void				ft_rotate_up_a(t_node **head);
void				ft_rotate_up_b(t_node **head);
void				ft_rotate_up_both(t_node **head1, t_node **head2);
void				ft_rotate_up(t_node **head);

// move_swap

void				ft_swap_a(t_node **head);
void				ft_swap_b(t_node **head);
void				ft_swap_both(t_node **head1, t_node **head2);
void				ft_swap(t_node **head);

// print_move

void				print_move(t_moves moves, t_handler *data);

// reverse sort

void				reverse_sort_a_to_b(t_handler *data, int array_size);
void				reverse_sort_b_to_a(t_handler *data, int array_size);
void				op_reverse_push_a_to_b(t_handler *data, int *cur_pos,
						int array_size);
void				op_reverse_push_b_to_a(t_handler *data, int *cur_pos,
						int array_size);

// sort normal a to b

int					normal_check_small_a_to_b(t_array *a, t_array *b,
						int *cur_pos);
int					normal_check_big_a_to_b(t_array *a, t_array *b,
						int *cur_pos, int array_size);
void				op_normal_push_a_to_b(t_handler *data, int *cur_pos,
						int array_size);
void				normal_sort_a_to_b(t_handler *data, int array_size);

// sort normal b to a

int					normal_check_small_b_to_a(t_array *b, t_array *a,
						int *cur_pos);
int					normal_check_big_b_to_a(t_array *b, t_array *a,
						int *cur_pos, int array_size);
void				op_normal_push_b_to_a(t_handler *data, int *cur_pos,
						int array_size);
void				normal_sort_b_to_a(t_handler *data, int array_size);

// sort reverse a to b

int					reverse_check_small_a_to_b(t_array *a, t_array *b,
						int *cur_pos);
int					reverse_check_big_a_to_b(t_array *a, t_array *b,
						int *cur_pos, int array_size);
void				op_reverse_push_a_to_b(t_handler *data, int *cur_pos,
						int array_size);
void				reverse_sort_a_to_b(t_handler *data, int array_size);

// sort reverse b to a

int					reverse_check_small_b_to_a(t_array *b, t_array *a,
						int *cur_pos);
int					reverse_check_big_b_to_a(t_array *b, t_array *a,
						int *cur_pos, int array_size);
void				op_reverse_push_b_to_a(t_handler *data, int *cur_pos,
						int array_size);
void				reverse_sort_b_to_a(t_handler *data, int array_size);

// printf

int					ft_printf(const char *str, ...);
void				check_type(char c, va_list list, int *count);
void				ft_putchar(char c, int *count);
void				ft_puthex(unsigned long num, char c, int *count);
void				ft_putnbr(long num, int *count);
void				ft_putstr(char *s, int *count);
void				ft_putpoint(unsigned long num, int *count);

#endif