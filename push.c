/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/05 17:28:52 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isstackalign(t_list *stack)
{
	t_list	*iterator;
	int		index;

	iterator = stack;
	index = 1;
	while (iterator != NULL)
	{
		if (iterator->index == index)
		{
			iterator = iterator->next;
			index++;
		}
		else
			return (0);
	}
	return (1);
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
	position = 0
	while (iterator != NULL)
	{
		if (iterator->index == nb)
			break ;
		position++;
		iterator = iterator->next;
	}
	return (position);
}

void	ft_createb(t_list **stack_a, t_list **stack_b)
{
	int	sizeoflist = ft_lstsize(*stack_a);
	int	n = bestn(sizeoflist);
	int	middle = sizeoflist / 2;
	int	offset = sizeoflist / n;
    int	start  = sizeoflist / 2 - offset;
    int	end = sizeoflist / 2 + offset;

	while (ft_lstsize(*stack_a) != 0)
	{
		if (inrange(*stack_a, start, end))
		{
			if ((*stack_a)->index >= start && ((*stack_a)->index <= end))
			{
				if ((*stack_a)->index > middle)
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
		{
			start = start - offset;
			end = end + offset;
			if (start < 1)
				start = 1;
			if (end > sizeoflist)
				end = sizeoflist;
		}
	}
}

void	ft_sortmore(t_list **stack_a, t_list **stack_b)
{
	int	search;
	int	pos;

	search = ft_lstsize(*stack_a);
	pos = 0;
	ft_createB(&*stack_a, &*stack_b);
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
			{
				while (pos > 0)
				{
					rname(stack_b, 'b');
					pos--;
				}
			}
			else
			{
				pos = search - pos;
				while (pos > 0)
				{
					rrname(stack_b, 'b');
					pos--;
				}
			}
		}
	}
}

int *ft_load(char **argv, int argc)
{
	

}

void ft_checktwins(char **argv, int argc)
{
	int i;
	int j;

	int i = 1;
	while (i < argc)
	{
		while 
	}

}

// checar argumentos
// passar para inteiro, checando os limites de int
// enfiar na stack

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_index(stack_a, 0, 0);
	if (argc - 1 == 0)
		return (0);
	if (argc - 1 == 1)
		return (0);
	if (argc - 1 == 2)
		ft_sort2(&stack_a);
	if (argc - 1 == 3)
		ft_sort3(&stack_a);
	if (argc - 1 == 4)
		ft_sort4(&stack_a, &stack_b);
	if (argc - 1 == 5)
		ft_sort5(&stack_a, &stack_b);
	if (argc - 1 > 5)
		ft_sortmore(&stack_a, &stack_b);
}
