/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:53:14 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/11 15:53:18 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*find_last_node(t_node *stack_x)
{
	while (stack_x && stack_x->next)
	{
		stack_x = stack_x->next;
	}
	return (stack_x);
}

int	n_finder(int len)
{
	int	i;

	i = 2;
	while (i * i <= len)
		i++;
	return (i + 7);
}

void	butterfly(t_node **stack_a, t_node **stack_b, int counter, int n)
{
	while (*stack_a)
	{
		if ((*stack_a)->index <= counter)
		{
			op_px_print(stack_b, stack_a, "b");
			op_rx_print(stack_b, "b");
			counter++;
		}
		else if ((*stack_a)->index <= counter + n)
		{
			op_px_print(stack_b, stack_a, "b");
			counter++;
		}
		else
			op_rx_print(stack_a, "a");
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b, int len)
{
	butterfly(stack_a, stack_b, 0, n_finder(len));
	while (*stack_b && len)
	{
		if ((*stack_b)->index == len - 1)
		{
			op_px_print(stack_a, stack_b, "a");
			len--;
		}
		else if ((find_last_node(*stack_b))->index == len - 1)
		{
			op_rrx_print(stack_b, "b");
			op_px_print(stack_a, stack_b, "a");
			len--;
		}
		else
		{
			if (find_pos(len - 1, *stack_b) < (len - 1) / 2)
				op_rx_print(stack_b, "b");
			else
				op_rrx_print(stack_b, "b");
		}
	}
}
