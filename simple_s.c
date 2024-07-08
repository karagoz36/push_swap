/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:47:38 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/14 13:31:39 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_sort_3_v2(t_list *head, t_list **stack_a, int min)
{
	if (head->next->index == min)
		ft_ra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}

void static	ft_sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		min2;

	head = *stack_a;
	min = ft_min_sort(stack_a, -1);
	min2 = ft_min_sort(stack_a, min);
	if (head->index == min)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (head->index == min2)
	{
		if (head->next->index == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
		ft_sort_3_v2(head, stack_a, min);
}

void static	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dst;

	dst = ft_distance(stack_a, ft_min_sort(stack_a, -1));
	if (dst == 1)
		ft_ra(stack_a);
	else if (dst == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (dst == 3)
		ft_rra(stack_a);
	if (ft_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void static	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dst;

	dst = ft_distance(stack_a, ft_min_sort(stack_a, -1));
	if (dst == 1)
		ft_ra(stack_a);
	else if (dst == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (dst == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (dst == 4)
		ft_rra(stack_a);
	if (ft_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_s_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else
		ft_sort_5(stack_a, stack_b);
}
