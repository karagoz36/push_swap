/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:30:20 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/06/20 16:54:25 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char	*str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int static	ft_is_num(char *nmb)
{
	int	i;

	i = 0;
	if (nmb[0] == '-' && (nmb[1] >= '0' && nmb[1] <= '9'))
		i = 1;
	while (nmb[i])
	{
		if (nmb[i] < '0' || nmb[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_double(int nmb, char **argv)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_ps_atoi(argv[i]) == nmb)
			cnt++;
		if (cnt == 2)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check2(int i, int argc, char **argv)
{
	int			error;
	long long	nmb;

	error = 0;
	while (argv[i])
	{
		if (!ft_is_num(argv[i]))
			error = 1;
		nmb = ft_ps_atoi(argv[i]);
		if (ft_strlen(argv[i]) > 11)
			error = 1;
		if (nmb < -2147483648 || nmb > 2147483647)
			error = 1;
		if (ft_is_double(nmb, argv))
			error = 1;
		if (error)
		{
			if (argc == 2)
				ft_ps_free(argv);
			ft_error("Error");
		}
		i++;
	}
}

void	ft_check(int argc, char **argv_org)
{
	int			i;
	char		**argv;

	i = 0;
	if (argc == 2)
	{
		if (argv_org[1][0] == '\0')
			ft_error("Error");
		argv = ft_split(argv_org[1], ' ');
	}
	else
	{
		i = 1;
		argv = argv_org;
	}
	ft_check2(i, argc, argv);
	if (argc == 2)
		ft_ps_free(argv);
}
