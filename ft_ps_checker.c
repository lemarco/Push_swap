/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:54:44 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 20:54:44 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ps.h"

int	ft_ps_stack_len(char *av)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1 && ft_isdigit(av[i + 1]) == 0)
			n++;
		i++;
	}
	return (n);
}

int	ft_ps_validator(char **av)
{
	int i;
	int j;
	int n;

	j = 1;
	n = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 0 && (av[j][i] != ' '
			&& av[j][i] != '-'))
				return (0);
			i++;
		}
		if (ft_ps_stack_len(av[j]) == 0)
			return (0);
		n += ft_ps_stack_len(av[j]);
		j++;
	}
	return (n);
}

int	ft_is_sort(t_stacks stacks)
{
	int	i;

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

int	ft_ps_first_checker(t_stacks *stacks, int ac, char **av)
{
	if (ft_ps_validator(av) == 0 || ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		if (!(stacks->stack_a = (int*)malloc(sizeof(int) *
			ft_ps_validator(av))))
			return (0);
		stacks->size_a = ft_ps_validator(av);
		if (!(stacks->stack_b = (int*)malloc(sizeof(int) *
			ft_ps_validator(av))))
			return (0);
		stacks->size_b = 0;
		if (ft_fill_stack(av, stacks->stack_a) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			ret;
	char		*sort;

	if (!av[1])
		return (0);
	if (ft_ps_first_checker(&stacks, ac, av) == 0)
		return (0);
	while ((ret = get_next_line(0, &sort)) == 1)
	{
		if (ft_ps_checklist(sort, &stacks) == 0)
			return (0);
		ft_memdel((void **)&sort);
	}
	if (stacks.size_b == 0 && ft_is_sort(stacks) == 1)
	{
		ft_printf("OK\n");
		return (0);
	}
	if (ft_is_sort(stacks) == 0)
		ft_printf("KO\n");
	return (0);
}
