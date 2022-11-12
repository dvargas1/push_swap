/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:47 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/11 17:54:59 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *stack, int i, long int j)
{
	t_list	*tmp;
	t_list	*highest;

	tmp = stack;
	i = ft_lstsize(stack);
	while (i > 0)
	{
		tmp = stack;
		j = -2147483649;
		highest = NULL;
		while (tmp != NULL)
		{
			if (tmp->content > j && tmp->index == 0)
			{
				j = tmp->content;
				highest = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = i;
		--i;
	}
}

int	ft_issorted(t_list **stack)
{
	t_list	*compare1;
	t_list	*compare2;

	compare1 = *stack;
	compare2 = compare1->next;
	while (compare2 != NULL)
	{
		if (compare2->content < compare1->content)
			return (1);
		compare1 = compare1->next;
		compare2 = compare2->next;
	}
	return (0);
}

int	inrange(t_list *stack, int start, int end)
{
	t_list	*iterator;

	iterator = stack;
	while (iterator != NULL)
	{
		if (iterator->index >= start && iterator->index <= end)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}
