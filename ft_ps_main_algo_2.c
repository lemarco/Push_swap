/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main_algo_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:54:59 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:55:00 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

static void	ft_main_sort_b_help_2(t_stacks *stacks, int len,
	int rb, int side_s)
{
	if (len / 2 + len % 2 != stacks->size_b)
	{
		while (rb > 0)
		{
			side_s == 1 ? ft_ps_oper_var("rrb", stacks) :
			ft_ps_oper_var("rb", stacks);
			rb--;
		}
	}
}

static void	ft_main_sort_b_help(t_stacks *stacks, int len, int mediane, int i)
{
	int	rb;
	int	half_len;
	int	side_s;

	rb = 0;
	half_len = 0;
	while (++i < len && half_len < (len / 2))
	{
		if (stacks->stack_b[0] > mediane)
		{
			ft_ps_oper_var("pa", stacks);
			half_len++;
		}
		else
		{
			side_s = fs_ps_side(stacks->stack_b, stacks->size_b, mediane);
			side_s == 1 ? ft_ps_oper_var("rb", stacks) :
			ft_ps_oper_var("rrb", stacks);
			rb++;
			i = -2;
		}
	}
	ft_main_sort_b_help_2(stacks, len, rb, side_s);
}

void		ft_main_sort_b(t_stacks *stacks, int len)
{
	int	i;
	int	mediane;

	i = -1;
	if (len <= 2)
	{
		if (len == 2 && stacks->stack_b[0] < stacks->stack_b[1])
			ft_ps_oper_var("sb", stacks);
		while (++i < len)
			ft_ps_oper_var("pa", stacks);
	}
	else
	{
		mediane = ft_ps_mediane(stacks->stack_b, len);
		ft_main_sort_b_help(stacks, len, mediane, i);
		ft_main_sort_a(stacks, len / 2);
		ft_main_sort_b(stacks, len / 2 + len % 2);
	}
}
