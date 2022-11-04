/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:34 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/02 09:01:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort2
void ft_sort2(t_list **stack_a)
{
	if ((*stack_a)->index == 2)
		sname(stack_a, 'a');
	else
		return;
}

int maxindex(t_list *stack_a)
{
	t_list *iterator;
	int max;

	max = stack_a->index;
	iterator = stack_a;
	while(iterator != NULL)
	{	
		if(iterator->index > max)
			max = iterator->index;
		iterator = iterator->next;
	}
	return(max);
}


//Sort 3 numeros finalizada.
void ft_sort3(t_list **stack_a)
{
	int max;
	max = maxindex(*stack_a);
	if(ft_issorted(stack_a))
			return;
	if((*stack_a)->index == max)
		rname(stack_a, 'a');
	else if((*stack_a)->next->index == max)
		rrname(stack_a, 'a');
	if(((*stack_a)->index > (*stack_a)->next->index))
		sname(stack_a, 'a');
}

//sort 4
void ft_sort4(t_list **stack_a, t_list **stack_b)
{
	while((*stack_a)->index != 1)
	{
		if((*stack_a)->index == 1)
			pname(stack_a, stack_b, 'b');
		rname(stack_a, 'a');
	}
	pname(stack_a, stack_b, 'b');
	ft_sort3(stack_a);
	pname(stack_b,stack_a, 'a');
}

// Sort 5
void ft_sort5(t_list **stack_a, t_list **stack_b)
{
	while((*stack_a)->index != 1)
		rname(stack_a, 'a');
	pname(stack_a, stack_b, 'b');
	while((*stack_a)->index != 2)
		rname(stack_a, 'a');
	pname(stack_a, stack_b, 'b');
	ft_sort3(stack_a);
	pname(stack_b,stack_a, 'a');
	pname(stack_b,stack_a, 'a');
}
