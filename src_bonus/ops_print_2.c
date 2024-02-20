/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:42:52 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/07 17:42:56 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	op_rr_print(t_node **stack_a, t_node **stack_b)
{
	op_rr(stack_a, stack_b);
	ft_printf("rr\n");
}

void	op_rrr_print(t_node **stack_a, t_node **stack_b)
{
	op_rrr(stack_a, stack_b);
	ft_printf("rrr\n");
}
