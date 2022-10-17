/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:47 by dvargas           #+#    #+#             */
/*   Updated: 2022/10/17 09:01:41 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->content);
		node = node->next;	
	}
}
void printindex(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->index);
		node = node->next;	
	}
}

void printarr(int *print, int size)
{
	int j = 1;
	while(j < (size))
	{
		printf("%d ", print[j]);
		j++;
	}
}

int ft_issorted(t_list **stack)
{
	t_list *compare1 = *stack;
	t_list *compare2 = compare1->next;

	while(compare2 != NULL)
	{
		if(compare2->content < compare1->content)
			return(0);
		compare1 = compare1->next;
		compare2 = compare2->next;
	}
	return(1);
}


void sortargs(int *arg, int size)
{
	int i = 0;
	int swap;

	while(i < size-1)
	{
		if(arg[i] > arg[i+1])
		{
			swap=arg[i+1];
			arg[i+1] = arg[i];
			arg[i] = swap;
			i = -1;
		}
		i++;
	}
}

void ft_simplesort(t_list **stack_a, t_list **stack_b, int *sorted)
{
	int i = 1;

	while((*stack_a) != NULL)
	{
		if((*stack_a)->content == sorted[i])
		{
			pname(stack_a, stack_b, 'b');
			i++;
		}
		else
			rname(stack_a, 'a');
	}
	while((*stack_b) != NULL)
		pname(stack_b, stack_a, 'a');
}

