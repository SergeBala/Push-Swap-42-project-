/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:52:44 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/06 17:52:47 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	sort_two(t_node *stack_x, char *stack_name)
{
	if (node_counter(stack_x) != 2)
	{
		ft_putstr_fd("sort two: the number of nodes is not 2!\n", 1);
		return ;
	}
	if (!stack_is_sorted(stack_x))
		op_sx_print(stack_x, stack_name);
	return ;
}

void	rev_sort_two(t_node *stack_x, char *stack_name)
{
	if (node_counter(stack_x) != 2)
	{
		ft_putstr_fd("sort two: the number of nodes is not 2!\n", 1);
		return ;
	}
	if (stack_is_sorted(stack_x))
		op_sx_print(stack_x, stack_name);
	return ;
}

void	sort_three(t_node **stack_x, char *stack_name, int five_flag)
{
	int	i;

	if (node_counter(*stack_x) != 3)
		return ;
	i = (*stack_x)->next->index;
	if (!stack_is_sorted(*stack_x))
	{
		if ((*stack_x)->index == (1 + five_flag) && i == (0 + five_flag))
			op_sx_print(*stack_x, stack_name);
		if ((*stack_x)->index == (2 + five_flag) && i == (0 + five_flag))
			op_rx_print(stack_x, stack_name);
		if ((*stack_x)->index == (1 + five_flag) && i == (2 + five_flag))
			op_rrx_print(stack_x, stack_name);
		if ((*stack_x)->index == (2 + five_flag) && i == (1 + five_flag))
		{
			op_rx_print(stack_x, stack_name);
			op_sx_print(*stack_x, stack_name);
		}
		if ((*stack_x)->index == (0 + five_flag) && i == (2 + five_flag))
		{
			op_rrx_print(stack_x, stack_name);
			op_sx_print(*stack_x, stack_name);
		}
	}
}

void	five_two_min_pusher(t_node **stack_a, t_node **stack_b)
{
	int	pb_count;

	pb_count = 0;
	while (pb_count < 2)
	{
		while ((*stack_a)->index > 1)
		{
			op_rx_print(stack_a, "a");
		}
		op_px_print(stack_b, stack_a, "b");
		pb_count++;
	}
}

void	sort_five_in_stack_a(t_node **stack_a, t_node **stack_b)
{
	if (node_counter(*stack_a) != 5)
	{
		ft_putstr_fd("sort five: the number of nodes is not 5!\n", 1);
		return ;
	}
	five_two_min_pusher(stack_a, stack_b);
	rev_sort_two(*stack_b, "b");
	sort_three(stack_a, "a", 2);
	op_px_print(stack_a, stack_b, "a");
	op_px_print(stack_a, stack_b, "a");
}

	// if (node_counter(*stack_x) != 3)
	// {
	// 	ft_putstr_fd("sort two: the number of nodes is not 3!\n", 1);
	// 	return ;
	// }