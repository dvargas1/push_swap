/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:53:52 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 18:53:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	createchunk(t_chunk *i, int sizeoflist)
{
	i->n = bestn(sizeoflist);
	i->middle = sizeoflist / 2;
	i->offset = sizeoflist / i->n;
	i->start = sizeoflist / 2 - i->offset;
	i->end = sizeoflist / 2 + i->offset;
}

void	sidecontrol(t_chunk *i, int sizeoflist)
{
	i->start -= i->offset;
	i->end += i->offset;
	if (i->start < 1)
		i->start = 1;
	if (i->end > sizeoflist)
		i->end = sizeoflist;
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
