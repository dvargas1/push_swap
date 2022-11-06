/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:47 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 15:29:01 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *stack, int i, int j)
{
	t_list	*tmp;
	t_list	*highest;

	tmp = stack;
	i = ft_lstsize(stack);
	while (i > 0)
	{
		tmp = stack;
		j = -2147483648;
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

int	bestn(int size)
{
	int	n;

	if (size <= 10)
		n = 5;
	else if (size <= 150)
		n = 8;
	else
	{
		n = 18;
	}
	return (n);
}

int	findindexposition(t_list *stack, int nb)
{
	t_list	*iterator;
	int		position;

	iterator = stack;
	position = 0;
	while (iterator != NULL)
	{
		if (iterator->index == nb)
			break ;
		position++;
		iterator = iterator->next;
	}
	return (position);
}
