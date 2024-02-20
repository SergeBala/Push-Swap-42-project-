/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_operations_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:37:34 by sbalasho          #+#    #+#             */
/*   Updated: 2023/05/31 17:40:01 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	op_sx(t_node *stack_x)
{
	int	temp_index;
	int	temp_nb;

	if (stack_x == NULL)
		return ;
	if (stack_x->next == NULL)
		return ;
	temp_nb = stack_x->nb;
	temp_index = stack_x->index;
	stack_x->nb = stack_x->next->nb;
	stack_x->index = stack_x->next->index;
	stack_x->next->nb = temp_nb;
	stack_x->next->index = temp_index;
}

void	op_ss(t_node *stack_a, t_node *stack_b)
{
	op_sx(stack_a);
	op_sx(stack_b);
}

void	op_px(t_node **stack_to, t_node **stack_from)
{
	t_node	*temp_1;

	if (*stack_from == NULL)
		return ;
	temp_1 = (*stack_from)->next;
	(*stack_from)->next = *stack_to;
	if (*stack_to)
		(*stack_to)->prev = *stack_from;
	if (temp_1 && temp_1->prev)
		temp_1->prev = NULL;
	*stack_to = *stack_from;
	*stack_from = temp_1;
}

void	op_rx(t_node **stack_x)
{
	t_node	*temp;
	t_node	*last_node;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	last_node = (*stack_x)->next;
	temp = (*stack_x)->next;
	while (last_node->next)
		last_node = last_node->next;
	(*stack_x)->prev = last_node;
	(*stack_x)->next = NULL;
	last_node->next = *stack_x;
	temp->prev = NULL;
	*stack_x = temp;
}

void	op_rr(t_node **stack_a, t_node **stack_b)
{
	op_rx(stack_a);
	op_rx(stack_b);
}
