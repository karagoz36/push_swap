/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:56 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/14 13:29:07 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **stack_a)
{
	t_list	*head;
	t_list	*next;
	int		tmp_v;
	int		tmp_i;

	head = *stack_a;
	next = head->next;
	tmp_v = head->value;
	tmp_i = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_v;
	next->index = tmp_i;
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ft_ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;

	head = *stack_a;
	tail = ft_lstlast(head);
	*stack_a = head->next;
	head->next = NULL;
	tail->next = head;
	ft_putendl_fd("ra", 1);
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;

	head = *stack_a;
	tail = ft_lstlast(head);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	tail->next = *stack_a;
	*stack_a = tail;
	ft_putendl_fd("rra", 1);
	return (0);
}
