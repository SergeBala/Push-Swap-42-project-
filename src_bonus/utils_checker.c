/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:08 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/15 16:37:17 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	instruct_executor(t_node **a, t_node **b, char *str, int *ko)
{
	if (ft_strlen(str) == 3 && ft_strncmp(str, "sa\n", 3) == 0)
		op_sx(*a);
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "sb\n", 3) == 0)
		op_sx(*b);
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "ss\n", 3) == 0)
	{	
		op_sx(*a);
		op_sx(*b);
	}
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "ra\n", 3) == 0)
		op_rx(a);
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "rb\n", 3) == 0)
		op_rx(b);
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "rr\n", 3) == 0)
	{
		op_rx(a);
		op_rx(b);
	}
	else if (ft_strlen(str) == 4 && ft_strncmp(str, "rra\n", 4) == 0)
		op_rrx(a);
	else if (ft_strlen(str) == 4 && ft_strncmp(str, "rrb\n", 4) == 0)
		op_rrx(b);
	else
		instruct_executor_2(a, b, str, ko);
}

void	instruct_executor_2(t_node **a, t_node **b, char *str, int *ko)
{
	if (ft_strlen(str) == 4 && ft_strncmp(str, "rrr\n", 4) == 0)
	{
		op_rrx(a);
		op_rrx(b);
	}
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "pb\n", 3) == 0)
		op_px(b, a);
	else if (ft_strlen(str) == 3 && ft_strncmp(str, "pa\n", 3) == 0)
		op_px(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		(*ko)++;
	}
}

int	read_execute_lines(t_node **a, t_node **b)
{
	char	*str;
	int		ko;

	ko = 0;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		instruct_executor(a, b, str, &ko);
		free(str);
		if (ko)
			return (ko);
	}
	if (stack_is_sorted(*a) && (*b) == NULL)
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		return (1);
	}
}
