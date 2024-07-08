/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:51:13 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/17 10:35:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	ft_max_bits(t_list **stack_a)
{
	t_list	*head;
	int		max;
	int		bits;

	bits = 0;
	max = -1;
	head = *stack_a;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	while (max >> bits)
		bits++;
	return (bits);
}

static void	ft_empty_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		b_len;

	b_len = ft_lstsize(*stack_b);
	while (b_len)
	{
		ft_pa(stack_a, stack_b);
		b_len--;
	}
}

void	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int		a_len;
	int		bits_i;
	int		bits_n;
	int		j;

	bits_i = 0;
	bits_n = ft_max_bits(stack_a);
	a_len = ft_lstsize(*stack_a);
	while (bits_i < bits_n)
	{
		j = 0;
		while (j < a_len)
		{
			if ((((*stack_a)->index >> bits_i) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			j++;
		}
		ft_empty_stack_b(stack_a, stack_b);
		bits_i++;
	}
}
