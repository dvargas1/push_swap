/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neveruse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:26:50 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/05 15:29:40 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rname(stack_a, "ra");
	rname(stack_b, "rb");
	ft_putstr_fd("rrr\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rrname(stack_a, "rra");
	rrname(stack_b, "rrb");
	ft_putstr_fd("rrr\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	sname(stack_a, "sa");
	sname(stack_b, "sb");
}

void	ft_printcmd(char *name)
{
	static char		*toprint;

	if (!toprint)
	{
		toprint = name;
		return ;
	}
	if ((ft_strcmp(name, "ra") == 0 && ft_strcmp(toprint, "rb") == 0) \
			|| (ft_strcmp(name, "rb") == 0 && ft_strcmp(toprint, "ra") == 0))
	{
		ft_putstr_fd("rr\n", 1);
		name = NULL;
	}
	else
	{
		ft_putstr_fd(toprint, 1);
		ft_putchar_fd('\n', 1);
	}
	toprint = name;
}
