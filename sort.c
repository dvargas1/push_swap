/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:34 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 19:21:51 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_list **stack_a)
{
	if ((*stack_a)->index == 2)
		sname(stack_a, "sa");
	else
		return ;
}

int	maxindex(t_list *stack_a)
{
	t_list	*iterator;
	int		max;

	max = stack_a->index;
	iterator = stack_a;
	while (iterator != NULL)
	{	
		if (iterator->index > max)
			max = iterator->index;
		iterator = iterator->next;
	}
	return (max);
}

void	ft_sort3(t_list **stack_a)
{
	int	max;

	max = maxindex(*stack_a);
	if (ft_issorted(stack_a) == 0)
		return ;
	if ((*stack_a)->index == max)
		rname(stack_a, "ra");
	else if ((*stack_a)->next->index == max)
		rrname(stack_a, "rra");
	if (((*stack_a)->index > (*stack_a)->next->index))
		sname(stack_a, "sa");
}

void	ft_sort4(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 1)
	{
		if ((*stack_a)->index == 1)
			pname(stack_a, stack_b, "pb");
		rname(stack_a, "ra");
	}
	pname(stack_a, stack_b, "pb");
	ft_sort3(stack_a);
	pname(stack_b, stack_a, "pa");
}

void	ft_sort5(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			pname(stack_a, stack_b, "pb");
			i++;
		}
		else
			rname(stack_a, "ra");
	}
	ft_sort3(stack_a);
	if ((*stack_b)->index < ((*stack_b)->next)->index)
		sname(stack_b, "sb");
	pname(stack_b, stack_a, "pa");
	pname(stack_b, stack_a, "pa");
}
