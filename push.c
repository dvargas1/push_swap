/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/09/12 11:01:30 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

void print(t_list *node)
{
	while (node != NULL)
	{
		printf("%d", node->content);
		node = node->next;	
	}
}

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
	if(first)
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
// size 
int issorted(t_list **stack)
{
	//t_list *ctr = *stack;
	t_list *compare1 = *stack;
	t_list *compare2 = compare1->next;

	while(compare2 != NULL)
	{
		if(compare2->content < compare1->content)
			return(1);
		compare1 = compare1->next;
		compare2 = compare2->next;
	}
	return(0);
}

void bsort(t_list **stack_a, t_list **stack_b)
{
	t_list *compare1 = *stack_a;
	t_list *compare2 = *stack_a->next;
	t_list *bcompare1 = *stack_b;
	t_list *bcompare2 = *stack_b->next;
	int i = 10;
	int j = 10;

	while(i > 0)
	{
		if(issorted(stack_a) == 0)
			return;
		if(compare1->content > compare2->content)
		{
			sname(stack_a, 'a');
			pname(stack_a, stack_b, 'b');
		}
		else
			pname(stack_a,stack_b, 'b');
		i--;
	}
	while(i > 0)
	{
		if(issorted(stack_a) == 0)
			return;
		if(compare1->content > compare2->content)
		{
			sname(stack_a, 'a');
			pname(stack_a, stack_b, 'b');
		}
		else
			pname(stack_a,stack_b, 'b');
		i--;
	}
}


int main(int argc, char **argv)
{
	t_list *stack_a;
	//t_list *stack_b;
	stack_a = NULL;
	//stack_b = NULL;
	int i = 1;

	if(argc - 1 ==0)
		return (0);

	while(i<argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}

	print(stack_a);
	printf("\n");
	printf("\n");

	bsort(&stack_a);
	print(stack_a);

}



/*
	-------- ROTATE TESTE----------
	print(stack_b);
	printf("\n");
	rname(&stack_b, 'b');
	print(stack_b);

	-------------PNAME TESTER-------------------
	pname(&stack_a, &stack_b, 'b');
	print(stack_a);
	printf("\n");
	print(stack_b);

//	--------------SA TESTER------------------
//	
	printf("PRINTING STACK A\n");
	print(stack_a);
	printf("\nSA IN STACK A\n");
	sa(&stack_a, 'a');
	print(stack_a);
	printf("\n----------------------------\n");
	printf("PRINTING STACK B\n");
	print(stack_b);
	printf("\nSB IN STACK b\n");
	sa(&stack_b, 'b');
	print(stack_b);
	printf("\n----------------------------\n");

	printf("\nSS IN STACKs\n");
	ss(&stack_a, &stack_b);
	print(stack_a);
	printf("\n");
	print(stack_b);

//TEstes loucos de pedra
//

void swapa(t_list **stack_a)
{
	t_list *antipenultimo = NULL;
	t_list *penultimo = NULL;
	t_list *ultimo = NULL;
	t_list *node = *stack_a;

	while(node != NULL)
	{
		antipenultimo = penultimo;
		penultimo = ultimo;
		ultimo = node;
		node = node->next;
	}
	if(antipenultimo != NULL)
		antipenultimo->next = ultimo;
	if(penultimo != NULL)
	{
		penultimo->next = NULL;
		if(!antipenultimo)
			*stack_a = ultimo;
	}
	if(ultimo != NULL)
		ultimo->next = penultimo;
}
*/
