/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_algo_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:42:08 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 21:42:08 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

static void	ft_ps_less_then_three(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		ft_ps_oper_var("sa", stacks);
	if (ft_is_sort(*stacks) == 1)
		return ;
	ft_ps_oper_var("rra", stacks);
	ft_ps_less_then_three(stacks);
}

void		ft_ps_for_five(t_stacks *stacks, int pb)
{
	if (stacks->size_a <= 3)
	{
		ft_ps_less_then_three(stacks);
		return ;
	}
	while (stacks->size_a > 3)
	{
		if (stacks->stack_a[0] < ft_ps_mediane(stacks->stack_a, stacks->size_a))
		{
			ft_ps_oper_var("pb", stacks);
			pb++;
		}
		else
			ft_ps_oper_var("ra", stacks);
	}
	ft_ps_less_then_three(stacks);
	while (pb > 0)
	{
		if (stacks->size_b == 2 && stacks->stack_b[0] < stacks->stack_b[1])
			ft_ps_oper_var("sb", stacks);
		ft_ps_oper_var("pa", stacks);
		pb--;
	}
}
