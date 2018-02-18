/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:47:19 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 21:47:19 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

void	ft_ps_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_ps_sa(int **stack_a, int size_a)
{
	int *tmp;

	tmp = *stack_a;
	if (size_a == 0)
		return ;
	ft_ps_swap(&tmp[0], &tmp[1]);
	*stack_a = tmp;
}

void	ft_ps_ss(t_stacks *stacks)
{
	int *tmp_a;
	int *tmp_b;

	tmp_a = stacks->stack_a;
	tmp_b = stacks->stack_b;
	if (stacks->size_a != 0)
	{
		ft_ps_swap(&tmp_a[0], &tmp_a[1]);
		stacks->stack_a = tmp_a;
	}
	if (stacks->size_b != 0)
	{
		ft_ps_swap(&tmp_b[0], &tmp_b[1]);
		stacks->stack_b = tmp_a;
	}
}

void	ft_ps_pa(t_stacks *stacks)
{
	int *stack_a;
	int *stack_b;
	int i;
	int size_a;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	if (stacks->size_b == 0)
		return ;
	size_a = stacks->size_a + 1;
	while (--size_a > 0)
		stack_a[size_a] = stack_a[size_a - 1];
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < stacks->size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stacks->stack_b = stack_b;
	stacks->stack_a = stack_a;
	stacks->size_b = stacks->size_b - 1;
	stacks->size_a = stacks->size_a + 1;
}

void	ft_ps_pb(t_stacks *stacks)
{
	int *stack_a;
	int *stack_b;
	int i;
	int	size_b;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	if (stacks->size_a == 0)
		return ;
	size_b = stacks->size_b + 1;
	while (--size_b > 0)
		stack_b[size_b] = stack_b[size_b - 1];
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < stacks->size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stacks->size_b = stacks->size_b + 1;
	stacks->size_a = stacks->size_a - 1;
	stacks->stack_b = stack_b;
	stacks->stack_a = stack_a;
}
