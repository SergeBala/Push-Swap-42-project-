/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:42:36 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/07 17:42:41 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	op_sx_print(t_node *stack_x, char *stack_name)
{
	op_sx(stack_x);
	ft_printf("s%s\n", stack_name);
}

void	op_ss_print(t_node *stack_a, t_node *stack_b)
{
	op_ss(stack_a, stack_b);
	ft_printf("ss\n");
}

void	op_px_print(t_node **stack_to, t_node **stack_from, char *name)
{
	op_px(stack_to, stack_from);
	ft_printf("p%s\n", name);
}

void	op_rx_print(t_node **stack_x, char *stack_name)
{
	op_rx(stack_x);
	ft_printf("r%s\n", stack_name);
}

void	op_rrx_print(t_node **stack_x, char *stack_name)
{
	op_rrx(stack_x);
	ft_printf("rr%s\n", stack_name);
}
