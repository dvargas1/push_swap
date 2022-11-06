/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:53:44 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 18:53:46 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rposition(t_list **stack, int pos)
{
	while (pos > 0)
	{
		rname(stack, 'b');
		pos--;
	}
	return (pos);
}

int	rrposition(t_list **stack, int search, int pos)
{
	pos = search - pos;
	while (pos > 0)
	{
		rrname(stack, 'b');
		pos--;
	}
	return (pos);
}

void	ft_createb(t_list **stack_a, t_list **stack_b, int sizeoflist)
{
	t_chunk	i;

	createchunk(&i, sizeoflist);
	while (ft_lstsize(*stack_a) != 0)
	{
		if (inrange(*stack_a, i.start, i.end))
		{
			if ((*stack_a)->index >= i.start && ((*stack_a)->index <= i.end))
			{
				if ((*stack_a)->index > i.middle)
					pname(stack_a, stack_b, 'b');
				else
				{
					pname(stack_a, stack_b, 'b');
					rname(stack_b, 'b');
				}
			}
			else
				rname(stack_a, 'a');
		}
		else
			sidecontrol(&i, sizeoflist);
	}
}

void	ft_sortmore(t_list **stack_a, t_list **stack_b)
{
	int	search;
	int	pos;

	search = ft_lstsize(*stack_a);
	pos = 0;
	ft_createb(&*stack_a, &*stack_b, ft_lstsize(*stack_a));
	while (*stack_b != NULL)
	{
		if ((*stack_b)->index == search)
		{
			pname(stack_b, stack_a, 'a');
			search--;
		}
		else
		{
			pos = findindexposition(*stack_b, search);
			if (pos <= (search / 2))
				pos = rposition(stack_b, pos);
			else
				pos = rrposition(stack_b, search, pos);
		}
	}
}
