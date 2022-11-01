/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:57:03 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/01 18:39:33 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//swap a(SA)
// trocar os dois elementos do topo da stack A
// swap b(SB)
// trocar os dois elementos do topo da stack B
void sname(t_list **stack_a, char name)
{
	t_list *primeiro = NULL;
	t_list *segundo = NULL;
	t_list *terceiro = NULL;

	if(!stack_a)
		return;
	primeiro = *stack_a;
	if(primeiro)
		segundo = primeiro->next;
	if(segundo)
	{
		terceiro = segundo->next;
		primeiro->next = terceiro;
		segundo->next = primeiro;
		*stack_a = segundo;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return;
}
// ss
// faz SA e SB ao mesmo tempo
void ss(t_list **stack_a, t_list **stack_b)
{
	if(!stack_a || !stack_b)
		return;
	char s = 's';
	sname(stack_a,s);
	sname(stack_b,s);
	ft_putstr_fd("ss\n", 1);
}

// push a (PA)
// coloca o primeiro elemento de b no topo da pilha A
// push b(PB)
// coloca o primeiro elemento de a no topo da pilha B
void pname(t_list **stack_a, t_list **stack_b, char name)
{
	t_list *first;
	t_list *second;

	first = *stack_a;
	if(!first)
		return;

	second = first->next;
	*stack_a = second;
	first->next = *stack_b;
	*stack_b = first;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return;
}
// rotate a(RA)
// o primeiro elemento da stack A vira o ultimo
// rotate b(RB)
// o primeiro elemento da stack B vira o ultimo
void rrname(t_list **stack, char name)
{
	t_list *last;
	t_list *lastbutone;
	t_list *node;
	t_list *teste;

	if(!stack)
		return;
	teste = *stack;
	if(teste->next == NULL)
		return;
	while(teste != NULL)
	{
		lastbutone = last;
		last = teste;
		teste = teste->next;
	}
	node = *stack;
	*stack = last;
	last->next = node;
	lastbutone->next = NULL;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return;
}
// RR
// faz RA e RB ao mesmo tempo

// reverse rotate a(RRA)
// o ultimo elemento da stack A vira o primeiro
// reverse rotate b(RRB)
// o ultimo elemento da stack B vira o primeiro
void rname(t_list **stack, char name)
{
	t_list *last;
	t_list *node;
	t_list *node2;
	t_list *teste;

	if(!stack)
		return;
	teste = *stack;
	if(teste->next == NULL)
		return ;
	while(teste != NULL)
	{
		last = teste;
		teste = teste->next;
	}
	node = *stack;
	node2 = node->next;
	*stack = node2;
	last->next = node;
	node->next = NULL;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	return;
}
// RRR
// faz rra e rrb ao mesmo tempo
