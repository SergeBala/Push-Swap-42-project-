/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_aux_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:43 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/14 15:14:17 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	stack_is_sorted(t_node *stack_x)
{
	while (stack_x)
	{
		if (stack_x->prev && stack_x->prev->index > stack_x->index)
			return (0);
		stack_x = stack_x->next;
	}
	return (1);
}

int	find_pos(int index, t_node	*stack_x)
{
	int	i;

	i = 0;
	if (index < 0)
		return (-1);
	while (stack_x)
	{
		if (stack_x->index == index)
			return (i);
		i++;
		stack_x = stack_x->next;
	}
	return (-1);
}

int	free_list(t_node **stack_a)
{
	t_node	*temp;

	while (*stack_a)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
	stack_a = NULL;
	return (0);
}

int	free_double_char_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (0);
}

void	no_args_exit(void)
{
	exit(0);
}
