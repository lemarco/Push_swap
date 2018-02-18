/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:14:59 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 22:15:00 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

int	ft_is_sort(t_stacks stacks)
{
	int i;

	i = 0;
	while (i < stacks.size_a - 1)
	{
		if (stacks.stack_a[i] < stacks.stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
