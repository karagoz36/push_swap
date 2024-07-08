/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_s_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:11:04 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/14 13:51:29 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_distance(t_list	**stack_a, int index)
{
	t_list	*head;
	int		cnt;

	cnt = 0;
	head = *stack_a;
	while (head)
	{
		if (head->index == index)
			break ;
		head = head->next;
		cnt++;
	}
	return (cnt);
}

int	ft_min_sort(t_list **stack_a, int x)
{
	t_list	*head;
	int		min;

	head = *stack_a;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != x)
			min = head->index;
	}
	return (min);
}
