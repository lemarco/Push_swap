/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:56:25 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:56:25 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

int	main(int ac, char **av)
{
	t_stacks		stacks;

	if (check_and_fill(&stacks, ac, av) == 0)
		return (0);
	if (ft_is_sort(stacks) == 1)
	{
		ft_memdel((void**)&stacks);
		return (0);
	}
	if (stacks.size_a <= 5)
	{
		ft_ps_for_five(&stacks, 0);
		return (0);
	}
	ft_main_sort_a(&stacks, stacks.size_a);
	return (0);
}
