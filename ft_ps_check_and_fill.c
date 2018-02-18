/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_check_and_fill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:43:00 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 22:43:00 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

int	ft_int_tab_len(char *av)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1 && ft_isdigit(av[i + 1]) == 0)
			n++;
		i++;
	}
	return (n);
}

int	ft_check_arg(char **av)
{
	int i;
	int j;
	int n;

	j = 1;
	n = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 0 && (av[j][i] != ' '
			&& av[j][i] != '-'))
				return (0);
			i++;
		}
		if (ft_int_tab_len(av[j]) == 0)
			return (0);
		n += ft_int_tab_len(av[j]);
		j++;
	}
	return (n);
}

int	check_and_fill(t_stacks *stacks, int ac, char **av)
{
	if (ft_check_arg(av) == 0 || ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		if (!(stacks->stack_a = (int*)malloc(sizeof(int) * ft_check_arg(av))))
			return (0);
		stacks->size_a = ft_check_arg(av);
		if (!(stacks->stack_b = (int*)malloc(sizeof(int) * ft_check_arg(av))))
			return (0);
		stacks->size_b = 0;
		if (ft_fill_stack(av, stacks->stack_a) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
