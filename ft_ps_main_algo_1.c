/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_main_algo_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:54:55 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:54:55 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

static void	ft_main_sort_a_help2(t_stacks *stacks, int len,
	int turn, int side_s)
{
	if (len / 2 != stacks->size_a)
	{
		while (turn > 0)
		{
			side_s == 1 ? ft_ps_oper_var("rra", stacks) :
			ft_ps_oper_var("ra", stacks);
			turn--;
		}
	}
}

static void	ft_main_sort_a_help(t_stacks *stacks, int len, int mediane, int i)
{
	int half_len;
	int turn;
	int side_s;

	half_len = 0;
	turn = 0;
	while (++i < len && half_len < (len / 2 + len % 2))
	{
		if (stacks->stack_a[0] <= mediane)
		{
			ft_ps_oper_var("pb", stacks);
			half_len++;
		}
		else
		{
			side_s = fs_ps_side(stacks->stack_a, stacks->size_a, mediane);
			side_s == 1 ? ft_ps_oper_var("ra", stacks) :
			ft_ps_oper_var("rra", stacks);
			turn++;
			i = -2;
		}
	}
	ft_main_sort_a_help2(stacks, len, turn, side_s);
}

void		ft_main_sort_a(t_stacks *stacks, int len)
{
	int i;
	int mediane;

	if (ft_is_sort(*stacks) == 1)
		return ;
	if (len <= 2)
	{
		if (len == 2 && stacks->stack_a[0] > stacks->stack_a[1])
			ft_ps_oper_var("sa", stacks);
	}
	else
	{
		mediane = ft_ps_mediane(stacks->stack_a, len);
		i = -1;
		ft_main_sort_a_help(stacks, len, mediane, i);
		ft_main_sort_a(stacks, len / 2);
		ft_main_sort_b(stacks, len / 2 + len % 2);
	}
}
