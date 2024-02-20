/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:43:00 by sbalasho          #+#    #+#             */
/*   Updated: 2023/06/07 18:43:15 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	check_sign(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		i++;
		i *= -1;
		return (i);
	}
	if (str[i] == '+')
		i++;
	return (i);
}

int	ps_atoi(const char *str, char **str_arr, int *nb_arr)
{
	int		j;
	long	numb;
	int		minus;

	j = check_sign(str);
	numb = 0;
	minus = 1;
	if (j < 0)
	{
		j *= -1;
		minus = -1;
	}
	if (!(str[j] >= 48 && str[j] <= 57))
		return (0);
	while (str[j] >= 48 && str[j] <= 57)
	{
		numb *= 10;
		numb = numb + str[j] - 48;
		j++;
	}
	numb = numb * minus;
	if (numb > INT_MAX || numb < INT_MIN)
		free_err_exit(str_arr, nb_arr, 1);
	return ((int)numb);
}

int	is_a_num_string(char *str)
{
	int	i;
	int	post_o_switch;
	int	dig_counter;

	i = 0;
	dig_counter = 0;
	post_o_switch = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			post_o_switch = 1;
		if (i == 0 && str[i] != '-' && !ft_isdigit(str[i]))
			return (0);
		if (i != 0 && !ft_isdigit(str[i]))
			return (0);
		if (post_o_switch == 1)
			dig_counter++;
		if (dig_counter > 10)
			return (0);
		i++;
	}
	return (1);
}

// int	is_a_num_string(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (i == 0 && str[i] != '-' && !ft_isdigit(str[i]))
// 			return (0);
// 		if (i != 0 && !ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
