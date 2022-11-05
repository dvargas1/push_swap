/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:47 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/05 15:42:59 by dvargas          ###   ########.fr       */
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

void	print(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->content);
		node = node->next;
	}
}

void	printindex(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->index);
		node = node->next;
	}
}

void	printarr(int *print, int size)
{
	int	j;

	j = 1;
	while (j < (size))
	{
		printf("%d ", print[j]);
		j++;
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
			return (0);
		compare1 = compare1->next;
		compare2 = compare2->next;
	}
	return (1);
}
