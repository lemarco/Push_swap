/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:50:44 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/02 21:50:44 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PS_H
# define FT_PS_H

# include "../libft/libft.h"
# define INT_MIN -2147483648

typedef struct	s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

void			ft_ps_sa(int **tab_a, int size_a);
void			ft_ps_ss(t_stacks *stacks);
void			ft_ps_pa(t_stacks *stacks);
void			ft_ps_oper_var(char *sort, t_stacks *stacks);
void			ft_ps_swap(int *a, int *b);
void			ft_ps_for_five(t_stacks *stacks, int pb);
void			ft_ps_pb(t_stacks *stacks);
void			ft_ps_ra(int **tab_a, int size_a);
void			ft_ps_rr(t_stacks *stacks);
void			ft_ps_rra(int **tab_a, int size_a);
void			ft_main_sort_a(t_stacks *stacks, int len);
void			ft_main_sort_b(t_stacks *stacks, int len);
int				fs_ps_side(int *tab, int size, int mediane);
int				ft_ps_mediane(int *tab_a, int len);
int				ft_ps_checklist(char *sort, t_stacks *stacks);
int				ft_is_sort(t_stacks stacks);
int				ft_fill_stack(char **av, int *tab);
int				ft_check_arg(char **av);
int				ft_int_tab_len(char *av);
int				check_and_fill(t_stacks *stacks, int ac, char **av);
#endif
