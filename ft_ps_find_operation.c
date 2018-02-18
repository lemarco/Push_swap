/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_find_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:56:01 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:56:01 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

void	ft_ps_checklist2(char *sort, t_stacks *stacks)
{
	if (ft_strequ(sort, "ss"))
		ft_ps_ss(stacks);
	if (ft_strequ(sort, "pa"))
		ft_ps_pa(stacks);
	if (ft_strequ(sort, "pb"))
		ft_ps_pb(stacks);
}

int		ft_ps_checklist(char *sort, t_stacks *stacks)
{
	if (ft_strequ(sort, "sa"))
		ft_ps_sa(&stacks->stack_a, stacks->size_a);
	else if (ft_strequ(sort, "sb"))
		ft_ps_sa(&stacks->stack_b, stacks->size_b);
	else if (ft_strequ(sort, "ss") || ft_strequ(sort, "pa")
	|| ft_strequ(sort, "pb"))
		ft_ps_checklist2(sort, stacks);
	else if (ft_strequ(sort, "ra"))
		ft_ps_ra(&stacks->stack_a, stacks->size_a);
	else if (ft_strequ(sort, "rb"))
		ft_ps_ra(&stacks->stack_b, stacks->size_b);
	else if (ft_strequ(sort, "rr"))
		ft_ps_rr(stacks);
	else if (ft_strequ(sort, "rra"))
		ft_ps_rra(&stacks->stack_a, stacks->size_a);
	else if (ft_strequ(sort, "rrb"))
		ft_ps_rra(&stacks->stack_b, stacks->size_b);
	else
	{
		ft_printf("Error!\n");
		return (0);
	}
	return (1);
}

void	ft_ps_oper_var(char *sort, t_stacks *stacks)
{
	if (ft_strequ(sort, "sa"))
		ft_ps_sa(&stacks->stack_a, stacks->size_a);
	if (ft_strequ(sort, "sb"))
		ft_ps_sa(&stacks->stack_b, stacks->size_b);
	if (ft_strequ(sort, "ss"))
		ft_ps_ss(stacks);
	if (ft_strequ(sort, "pa"))
		ft_ps_pa(stacks);
	if (ft_strequ(sort, "pb"))
		ft_ps_pb(stacks);
	if (ft_strequ(sort, "ra"))
		ft_ps_ra(&stacks->stack_a, stacks->size_a);
	if (ft_strequ(sort, "rb"))
		ft_ps_ra(&stacks->stack_b, stacks->size_b);
	if (ft_strequ(sort, "rr"))
		ft_ps_rr(stacks);
	if (ft_strequ(sort, "rra"))
		ft_ps_rra(&stacks->stack_a, stacks->size_a);
	if (ft_strequ(sort, "rrb"))
		ft_ps_rra(&stacks->stack_b, stacks->size_b);
	ft_printf("%s\n", sort);
}
