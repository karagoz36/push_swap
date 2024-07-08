/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:29:17 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/14 13:50:46 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	ft_push(t_list **stack_1, t_list **stack_2)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack_1;
	tmp = head->next;
	if (!*stack_2)
	{
		*stack_2 = head;
		head->next = NULL;
		*stack_1 = tmp;
	}
	else
	{
		head->next = *stack_2;
		*stack_2 = head;
	}
	*stack_1 = tmp;
	return (0);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	return (0);
}
