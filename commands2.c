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
	char	r;

	r = 'r';
	if (!stack_a || !stack_b)
		return ;
	rname(stack_a, r);
	rname(stack_b, r);
	ft_putstr_fd("rrr\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	char	r;

	r = 'r';
	if (!stack_a || !stack_b)
		return ;
	rrname(stack_a, r);
	rrname(stack_b, r);
	ft_putstr_fd("rrr\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	char	s;

	s = 's';
	if (!stack_a || !stack_b)
		return ;
	sname(stack_a, s);
	sname(stack_b, s);
	ft_putstr_fd("ss\n", 1);
}
