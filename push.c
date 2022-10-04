/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/10/04 10:09:36 by dvargas          ###   ########.fr       */
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

void printarr(int *print, int size)
{
	int j = 1;
	while(j < (size))
	{
		printf("%d ", print[j]);
		j++;
	}
}

void ft_index(t_list *stack)
{
	t_list *tmp = stack;
	t_list *highest;
	int i = ft_lstsize(stack);
	int j;
	
	while(i > 0)
	{
		tmp = stack;
		j = -100;
	//	highest = NULL;
		while(tmp)
		{
			if(tmp->content > j && tmp->index == 0)
			{
				j = tmp->content;
				highest = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		if(highest != NULL)
			highest->index = i;
		--i;
	}
}


void ft_sort3(t_list **stack_a)
{
	if(ft_issorted(stack_a))
			return;
	if((*stack_a)->index == 3)
		rname(stack_a, 'a');
	else if((*stack_a)->next->index == 3)
		rrname(stack_a, 'a');
	if(((*stack_a)->index > (*stack_a)->next->index))
		sname(stack_a, 'a');
}


/*
ft_letsort(t_list **stack_a, t_list **stack_b)
{
	



}
*/
int main(int argc, char **argv)
{
	t_list *stack_a;
//	t_list *stack_b;
	stack_a = NULL;
//	stack_b = NULL;
	
	int i = 1;
	int k = 0;
	int *intv;
	intv = malloc(sizeof(int) * argc);

	if(argc - 1 == 0)
		return (0);

	while(i<argc)
	{
		intv[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}

	i = 1;
	while(i<argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	print(stack_a);
	ft_index(stack_a);
	if (argc == 4)
	{
		ft_sort3(&stack_a);
		printf("\nSTACK A SORTADA\n");
		print(stack_a);
	}
/*
	printindex(stack_a);
	sortargs(intv, argc);
	printarr(intv, argc);
	printf("AO LADO OS ARGUMENTOS DEPOIS DO SORT\n\n");
	print(stack_a);
	printf("   AO LADO A STACK PRONTA\n\n\n");
	printf("AGORA VAMOS TENTAR FAZER O SORT E PRINTAR\n");

	ft_simplesort(&stack_a, &stack_b, intv);
	printf("\nSTACK A\n");
	print(stack_a);
	printf("\nSTACK B\n");
	print(stack_b);
*/
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
