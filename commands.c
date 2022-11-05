/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:57:03 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/05 15:26:24 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sname(t_list **stack_a, char name)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!stack_a)
		return ;
	first = *stack_a;
	second = NULL;
	if (first)
		second = first->next;
	if (second)
	{
		third = second->next;
		first->next = third;
		second->next = first;
		*stack_a = second;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	pname(t_list **stack_a, t_list **stack_b, char name)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	if (!first)
		return ;
	second = first->next;
	*stack_a = second;
	first->next = *stack_b;
	*stack_b = first;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	rrname(t_list **stack, char name)
{
	t_list	*last;
	t_list	*lastbutone;
	t_list	*node;
	t_list	*iterator;

	if (!stack)
		return ;
	iterator = *stack;
	if (iterator->next == NULL)
		return ;
	while (iterator != NULL)
	{
		lastbutone = last;
		last = iterator;
		iterator = iterator->next;
	}
	node = *stack;
	*stack = last;
	last->next = node;
	lastbutone->next = NULL;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	rname(t_list **stack, char name)
{
	t_list	*last;
	t_list	*node;
	t_list	*node2;
	t_list	*iterator;

	if (!stack)
		return ;
	iterator = *stack;
	if (iterator->next == NULL)
		return ;
	while (iterator != NULL)
	{
		last = iterator;
		iterator = iterator->next;
	}
	node = *stack;
	node2 = node->next;
	*stack = node2;
	last->next = node;
	node->next = NULL;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}
