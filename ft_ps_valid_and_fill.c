/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_valid_and_fill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:55:51 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:55:52 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

static int	ft_check_d(int n, int *tab, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (n == tab[i])
			return (0);
		i++;
	}
	tab[j] = n;
	return (1);
}

static int	ft_ps_fill_stack_val(char *av, int i, int j, int *tab)
{
	int n;
	int neg;

	n = 0;
	neg = 1;
	if (av[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (ft_isdigit(av[i]) == 1 && av[i])
	{
		n = n * 10 + av[i] - '0';
		if ((n > INT_MIN && n < 0 && neg == -1) ||
		(n >= INT_MIN && n < 0 && neg == 1))
			return (0);
		i++;
	}
	n = n * neg;
	if (ft_check_d(n, tab, j) == 0)
		return (0);
	else
		j++;
	return (i);
}

int			ft_fill_stack(char **av, int *tab)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 1;
	while (av[k])
	{
		i = 0;
		while (av[k][i])
		{
			if ((ft_isdigit(av[k][i]) == 1 || av[k][i] == '-'))
			{
				if (ft_ps_fill_stack_val(av[k], i, j, tab) == 0)
					return (0);
				i = ft_ps_fill_stack_val(av[k], i, j, tab);
				j++;
			}
			else
				i++;
		}
		k++;
	}
	return (1);
}
