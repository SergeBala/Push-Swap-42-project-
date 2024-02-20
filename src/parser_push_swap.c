/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:01:51 by sbalasho          #+#    #+#             */
/*   Updated: 2023/08/19 18:39:47 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**ft_join_split(int ac, char **av)
{
	int		i;
	char	*big_str;
	char	*tmp;
	char	**str_arr;

	i = 1;
	if (ac < 2)
		no_args_exit();
	big_str = malloc(1 * sizeof(char));
	big_str[0] = '\0';
	while (i < ac)
	{
		tmp = ft_strjoin(big_str, " ");
		free(big_str);
		big_str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	str_arr = ft_split(big_str, ' ');
	free(big_str);
	return (str_arr);
}

void	free_err_exit(char **str_arr, int *nb_arr, int error_flag)
{
	free_double_char_arr(str_arr);
	free(nb_arr);
	if (error_flag == 1)
		ft_putstr_fd("Error\n", 2);
	exit(error_flag);
}

int	ft_no_dups(int *nb_arr, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (nb_arr[i] == nb_arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_arr_int	ft_arg_validator(char **str_arr)
{
	t_arr_int	arr_int;
	int			i;

	arr_int.arr_len = 0;
	i = 0;
	arr_int.nb_arr = NULL;
	while (str_arr[arr_int.arr_len])
		arr_int.arr_len++;
	arr_int.nb_arr = malloc((arr_int.arr_len) * sizeof(int));
	while (i < arr_int.arr_len)
	{
		arr_int.nb_arr[i] = ps_atoi(str_arr[i], str_arr, arr_int.nb_arr);
		if (!is_a_num_string(str_arr[i])
			|| (!ft_strncmp(str_arr[i], "-", 1) && ft_strlen(str_arr[i]) == 1))
			free_err_exit(str_arr, arr_int.nb_arr, 1);
		i++;
	}
	if (arr_int.arr_len == 1)
		free_err_exit(str_arr, arr_int.nb_arr, 0);
	if (ft_no_dups(arr_int.nb_arr, arr_int.arr_len) == 0)
		return (arr_int);
	free_err_exit(str_arr, arr_int.nb_arr, 1);
	arr_int.arr_len = 0;
	arr_int.nb_arr = NULL;
	return (arr_int);
}

int	main(int ac, char **av)
{
	t_arr_int	arr_int;
	t_node		*stack_a;
	t_node		*stack_b;
	char		**str_arr;

	stack_b = NULL;
	str_arr = ft_join_split(ac, av);
	arr_int = ft_arg_validator(str_arr);
	stack_a = list_init(arr_int.nb_arr, arr_int.arr_len);
	if (!stack_is_sorted(stack_a))
	{
		if (arr_int.arr_len == 3)
			sort_three(&stack_a, "a", 0);
		else if (arr_int.arr_len == 2)
			sort_two(stack_a, "a");
		else if (arr_int.arr_len == 5)
			sort_five_in_stack_a(&stack_a, &stack_b);
		else
			sort_big(&stack_a, &stack_b, arr_int.arr_len);
	}
	free_double_char_arr(str_arr);
	free(arr_int.nb_arr);
	free_list(&stack_a);
	return (0);
}
	// system("leaks push_swap");
	// printf("stack sorted? %i\n", stack_is_sorted(stack_a));
	// printf("stack sorted? %i\n", stack_is_sorted(stack_a));
	// print_list(stack_a);
	// printf("\n\n");
	// rev_print_list(stack_a);
	// // int arr[] = {11, 12, 13};
	// // int *arr_ptr = arr;
	// // stack_b = list_init(arr_ptr, 3);
	// op_rrx(&stack_a);
	// op_rrx(&stack_a);
	// // op_px(&stack_b, &stack_a);
	// // op_px(&stack_b, &stack_a);
	// // op_px(&stack_b, &stack_a);
	// // op_px(&stack_b, &stack_a);
	// ft_putstr_fd("\nhere is A from head to tail:\n", 1);
	// print_list(stack_a);
	// ft_putstr_fd("\nhere is A in reversed order:\n", 1);
	// rev_print_list(stack_a);
	// ft_putstr_fd("\nhere is B from head to tail:\n", 1);
	// print_list(stack_b);
	// ft_putstr_fd("\nhere is B in reversed order:\n", 1);
	// rev_print_list(stack_b);
	// int	i = 0;
	// while (i < arr_int.arr_len)
	// {
	// 	ft_putnbr_fd(arr_int.nb_arr[i], 1);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// op_ss(stack_a, stack_b);
	// op_px(&stack_a, &stack_b);
	// op_px(&stack_b, &stack_a);
	// op_rr(&stack_a, &stack_b);
	// op_rrr(&stack_a, &stack_b); 
