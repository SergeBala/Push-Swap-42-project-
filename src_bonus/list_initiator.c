/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initiator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:53:55 by sbalasho          #+#    #+#             */
/*   Updated: 2023/05/30 13:54:01 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

t_node	*make_new_node(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_putstr_fd("Malloc failed, line 21\n", 2);
		return (NULL);
	}
	new_node->nb = value;
	new_node->index = index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_node **head, int value, int index)
{
	t_node	*new_node;
	t_node	*traverse;

	new_node = make_new_node(value, index);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	traverse = *head;
	while (traverse->next != NULL)
	{
		traverse = traverse->next;
	}
	traverse->next = new_node;
	new_node->prev = traverse;
}

// void	add_node_front(t_node **head, int value)
// {
// 	t_node	*new_node;

// 	new_node = make_new_node(value);
// 	if (*head == NULL)
// 	{
// 		*head = new_node;
// 		return ;
// 	}
// 	new_node->next = *head;
// 	(*head)->prev = new_node;
// }

t_node	*list_init(int *nb_arr, int arr_len)
{
	int			i;
	t_node		*head;
	t_arr_int	sorted_arr_int;

	i = 0;
	head = NULL;
	sorted_arr_int = ft_arr_int_cpy(nb_arr, arr_len);
	bubble_sorter(&sorted_arr_int);
	while (i < arr_len)
	{
		add_node_back(&head, nb_arr[i], find_index(nb_arr[i], sorted_arr_int));
		i++;
	}
	free(sorted_arr_int.nb_arr);
	return (head);
}

int	node_counter(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

void	print_list(t_node *head)
{
	if (head == NULL)
	{
		ft_putstr_fd("print list: nothing to print: empty list\n", 1);
		return ;
	}
	while (head)
	{
		ft_putnbr_fd(head->index, 1);
		write(1, "\n", 1);
		head = head->next;
	}
}

// void	rev_print_list(t_node *head)
// {
// 	t_node	*tail;

// 	if (head == NULL)
// 	{
// 		ft_putstr_fd("rev_print_list: nothing to print: empty list\n", 1);
// 		return ;
// 	}
// 	tail = head;
// 	while (tail->next)
// 	{
// 		tail = tail->next;
// 	}
// 	while (tail)
// 	{
// 		ft_putnbr_fd(tail->index, 1);
// 		write(1, "\n", 1);
// 		tail = tail->prev;
// 	}
// }

// void	change_each_sign(t_node **head)
// {
// 	while (*head)
// 	{
// 		if ((*head)->nb > -2147483648)
// 		(*head)->nb *= -1;
// 		*head = (*head)->next;
// 	}
// }
