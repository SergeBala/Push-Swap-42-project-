/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:38:39 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/15 16:38:47 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_arr_int
{
	int	*nb_arr;
	int	arr_len;
}	t_arr_int;

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

char		**ft_join_split(int ac, char **av);
t_arr_int	ft_arg_validator(char **str_arr);
int			ft_no_dups(int *nb_arr, int arr_len);
void		free_err_exit(char **str_arr, int *nb_arr, int error_flag);
t_node		*make_new_node(int value, int index);
void		add_node_back(t_node **head, int value, int index);
t_node		*list_init(int *nb_arr, int arr_len);
void		print_list(t_node *head);
void		rev_print_list(t_node *head);
void		op_sx(t_node *stack_x);
void		op_ss(t_node *stack_a, t_node *stack_b);
void		op_px(t_node **stack_to, t_node **stack_from);
void		op_rx(t_node **stack_x);
void		op_rr(t_node **stack_a, t_node **stack_b);
void		op_rrx(t_node **stack_x);
void		op_rrr(t_node **stack_a, t_node **stack_b);
void		op_sx_print(t_node *stack_x, char *stack_name);
void		op_ss_print(t_node *stack_a, t_node *stack_b);
void		op_px_print(t_node **stack_to, t_node **stack_from, char *name);
void		op_rx_print(t_node **stack_x, char *stack_name);
void		op_rr_print(t_node **stack_a, t_node **stack_b);
void		op_rrx_print(t_node **stack_x, char *stack_name);
void		op_rrr_print(t_node **stack_a, t_node **stack_b);
t_arr_int	ft_arr_int_cpy(int *nb_arr, int arr_len);
void		bubble_sorter(t_arr_int *sorted_arr_int);
int			find_index(int nb, t_arr_int sorted_arr_int);
int			stack_is_sorted(t_node *stack_x);
int			node_counter(t_node *head);
void		sort_two(t_node *stack_x, char *stack_name);
void		rev_sort_two(t_node *stack_x, char *stack_name);
void		sort_three(t_node **stack_x, char *stack_name, int five_flag);
void		sort_five_in_stack_a(t_node **stack_a, t_node **stack_b);
void		sort_big(t_node **stack_a, t_node **stack_b, int len);
void		butterfly(t_node **stack_a, t_node **stack_b, int counter, int n);
int			find_pos(int index, t_node	*stack_x);
void		five_two_min_pusher(t_node **stack_a, t_node **stack_b);
int			ps_atoi(const char *str, char **str_arr, int *nb_arr);
int			is_a_num_string(char *str);
t_node		*find_last_node(t_node *stack_x);
int			n_finder(int len);
int			free_list(t_node **stack_a);
int			free_double_char_arr(char **arr);
void		no_args_exit(void);
void		instruct_executor(t_node **a, t_node **b, char *str, int *ko);
void		instruct_executor_2(t_node **a, t_node **b, char *str, int *ko);
int			read_execute_lines(t_node **a, t_node **b);
#endif
