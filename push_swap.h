/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:57:33 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/20 17:00:52 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);

int			ft_sa(t_list **stack_a);
int			ft_ra(t_list **stack_a);
int			ft_rra(t_list **stack_a);
int			ft_pb(t_list **stack_a, t_list **stack_b);
int			ft_pa(t_list **stack_b, t_list **stack_a);

void		ft_radix(t_list **stack_a, t_list **stack_b);

void		ft_s_sort(t_list **stack_a, t_list **stack_b);
int			ft_distance(t_list	**stack_a, int index);
int			ft_min_sort(t_list **stack_a, int x);

int			ft_is_sorted(t_list **stack_a);
long long	ft_ps_atoi(char *str);
void		ft_ps_free(char **dest);

void		ft_error(char	*str);
void		ft_check(int argc, char **argv_org);

#endif