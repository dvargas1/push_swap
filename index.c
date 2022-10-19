/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:56 by dvargas           #+#    #+#             */
/*   Updated: 2022/10/18 09:44:40 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Atribui os índices do menor valor para o maior.
void ft_index(t_list *stack)
{
	t_list *tmp = stack;
	t_list *highest;
	int i = ft_lstsize(stack);
	int j;
	
	while(i > 0)
	{
		tmp = stack;
		j = -2147483648;
		highest = NULL;
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

// encontra a melhor possibilidade de retorno para o indice dado
int bestpossible(t_list *stack, int index)
{
	int count = 0;
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index == index)
		{
			count++;
			index++;
		}
		iterator = iterator->next;
	}
	return(count);
}

// encontra o melhor indice da lista
int findbestindex(t_list *stack, int argc)
{
	int i = 1;
	int bestindex = 1;
	
	while(i < argc)
	{
		if(bestpossible(stack,i) > bestpossible(stack,bestindex))
			bestindex = i;
		i++;
	}
	return(bestindex);
}

// atribui se o valor fica ou nao na stack_a
void keepatribution(t_list *stack, int argc)
{
	int bestindex = findbestindex(stack, argc);
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index == bestindex)
		{
			iterator->keepinA = 1;
			bestindex++;
		}
		iterator = iterator->next;
	}
}








/*
 *
 *
 *
 * Loucura da cabeça de fazer marcaçao com content, ta quase pronto mas no
 * meio do caminho nao vi utilidade.
int bestpossiblecontent(t_list *stack, int content)
{
	int count = 0;
	t_list *iterator = stack;

	printf("content: %d ", content);
	while(iterator != NULL)
	{
		if(iterator->content > content)
		{
			count++;
			content = iterator->content;
		}
		iterator = iterator->next;
	}
	printf("possible: %d\n", count);
	return(count);
}

int findbestcontent(t_list *stack, int *intv)
{
	int i = 0;
	int bestnbr = intv[2];

	while(intv[i])
	{
		if(bestpossiblecontent(stack, intv[i]) > bestpossiblecontent(stack, bestnbr))
		{
			bestnbr = intv[i];
			printf("Bestnbr Result change to : %d", bestnbr);
		}
		i++;
	}
	printf("result of this: %d", bestnbr);
	return(bestnbr);
}

 *\
 */





