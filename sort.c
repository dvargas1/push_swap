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

//Sort 3 numeros finalizada.
void ft_sort3(t_list **stack_a)
{
	int max = 3;
	if(ft_issorted(stack_a))
			return;
	if((*stack_a)->index == max)
		rname(stack_a, 'a');
	else if((*stack_a)->next->index == max)
		rrname(stack_a, 'a');
	if(((*stack_a)->index > (*stack_a)->next->index))
		sname(stack_a, 'a');
}


// Sort 5 falta trabalhar em cima
void ft_sort5(t_list **stack_a, t_list **stack_b)
{
	pname(stack_a, stack_b, 'b');
	pname(stack_a, stack_b, 'b');
	ft_sort3(stack_a);
	if((*stack_b)->index > (*stack_b)->next->index)
		sname(stack_b, 'b');
}
