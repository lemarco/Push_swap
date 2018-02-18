/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:46:44 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 21:46:45 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

void	ft_ps_rra(int **stack_a, int size_a)
{
	int tmp;
	int n;
	int *tmp_a;

	tmp_a = *stack_a;
	if (size_a == 0)
		return ;
	n = size_a - 1;
	tmp = tmp_a[n];
	while (n > 0)
	{
		tmp_a[n] = tmp_a[n - 1];
		n--;
	}
	tmp_a[0] = tmp;
	*stack_a = tmp_a;
}

void	ft_ps_ra(int **stack_a, int size_a)
{
	int tmp;
	int	i;
	int *tmp_a;

	tmp_a = *stack_a;
	if (size_a == 0)
		return ;
	tmp = tmp_a[0];
	i = 0;
	while (i < size_a - 1)
	{
		tmp_a[i] = tmp_a[i + 1];
		i++;
	}
	tmp_a[size_a - 1] = tmp;
	*stack_a = tmp_a;
}

void	ft_ps_rr(t_stacks *stacks)
{
	int tmp;
	int	i;
	int *tmp_a;

	tmp_a = stacks->stack_a;
	i = 0;
	if (stacks->size_a != 0)
	{
		tmp = tmp_a[0];
		while (i < stacks->size_a - 1)
		{
			tmp_a[i] = tmp_a[i + 1];
			i++;
		}
		tmp_a[stacks->size_a - 1] = tmp;
		stacks->stack_a = tmp_a;
	}
	ft_ps_ra(&stacks->stack_b, stacks->size_b);
}
