/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_operations_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:49:46 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/04 15:49:53 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	op_rrx(t_node **stack_x)
{
	t_node	*temp;
	t_node	*last_node;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	last_node = (*stack_x)->next;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = *stack_x;
	(*stack_x)->prev = last_node;
	temp = last_node->prev;
	last_node->prev = NULL;
	temp->next = NULL;
	*stack_x = last_node;
}

void	op_rrr(t_node **stack_a, t_node **stack_b)
{
	op_rrx(stack_a);
	op_rrx(stack_b);
}

t_arr_int	ft_arr_int_cpy(int *nb_arr, int arr_len)
{
	t_arr_int	sorted_arr_int;
	int			i;

	i = 0;
	if (arr_len)
	{
		sorted_arr_int.nb_arr = malloc((arr_len) * sizeof(int));
		while (i < arr_len)
		{
			sorted_arr_int.nb_arr[i] = nb_arr[i];
			i++;
		}
		sorted_arr_int.arr_len = arr_len;
	}
	else
	{
		sorted_arr_int.nb_arr = NULL;
		sorted_arr_int.arr_len = 0;
	}
	return (sorted_arr_int);
}

void	bubble_sorter(t_arr_int *sorted_arr_int)
{
	int	temp;
	int	i;
	int	break_flag;

	while (1)
	{
		i = 0;
		break_flag = 1;
		while (i < (sorted_arr_int->arr_len - 1))
		{
			if (sorted_arr_int->nb_arr[i] > sorted_arr_int->nb_arr[i + 1])
			{
				temp = sorted_arr_int->nb_arr[i];
				sorted_arr_int->nb_arr[i] = sorted_arr_int->nb_arr[i + 1];
				sorted_arr_int->nb_arr[i + 1] = temp;
				break_flag = 0;
			}
			i++;
		}
		if (break_flag)
			break ;
	}
}

int	find_index(int nb, t_arr_int sorted_arr_int)
{
	int	i;

	i = 0;
	while (i < sorted_arr_int.arr_len)
	{
		if (nb == sorted_arr_int.nb_arr[i])
			return (i);
		i++;
	}
	ft_putstr_fd("WTF? number not found in sorted array", 1);
	return (-1);
}
