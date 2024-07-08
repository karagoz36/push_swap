/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:56:01 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:15 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list static	*ft_get_min(t_list	**stack_a)
{
	t_list	*head;
	t_list	*min_l;
	int		if_min;

	min_l = NULL;
	head = *stack_a;
	if_min = 0;
	if (!head)
		return (min_l);
	while (head)
	{
		if (head->index == -1 && (!if_min || (head->value < min_l->value)))
		{
			min_l = head;
			if_min = 1;
		}
		head = head->next;
	}
	return (min_l);
}

void static	ft_index(t_list **stack_a)
{
	t_list	*head;
	int		index;

	index = 0;
	head = ft_get_min(stack_a);
	while (head)
	{
		head->index = index++;
		head = ft_get_min(stack_a);
	}
}

void static	ft_init(t_list **stack_a, int argc, char **argv_org)
{
	t_list	*new;
	char	**argv;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv_org[1], ' ');
	else
	{
		i = 1;
		argv = argv_org;
	}
	while (argv[i])
	{
		new = ft_lstnew(ft_ps_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	ft_index(stack_a);
	if (argc == 2)
		ft_ps_free(argv);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (-1);
	ft_check(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init(&stack_a, argc, argv);
	if (ft_is_sorted(&stack_a))
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		return (0);
	}
	if (ft_lstsize(stack_a) <= 5)
		ft_s_sort(&stack_a, &stack_b);
	else
		ft_radix(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
