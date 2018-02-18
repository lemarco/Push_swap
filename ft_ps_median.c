/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:55:40 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:55:41 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

int	fs_ps_side(int *tab, int size, int mediane)
{
	int	left;
	int	rigth;
	int	i;

	i = 0;
	left = 0;
	rigth = 0;
	while (tab[i] > mediane)
	{
		left++;
		i++;
	}
	i = size - 1;
	while (tab[i] > mediane)
	{
		rigth++;
		i--;
	}
	if (rigth < left)
		return (2);
	else
		return (1);
}

int	ft_ps_mediane(int *tab_a, int len)
{
	int	i;
	int	j;
	int	upper;
	int	lower;

	j = 0;
	while (j < len)
	{
		upper = 0;
		lower = 0;
		i = 0;
		while (i < len)
		{
			if (tab_a[i] < tab_a[j])
				lower++;
			else if (tab_a[i] > tab_a[j])
				upper++;
			i++;
		}
		if (lower == upper || lower + 1 == upper)
			return (tab_a[j]);
		j++;
	}
	return (0);
}
