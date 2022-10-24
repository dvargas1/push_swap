/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/10/24 18:40:09 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_haveatribution(t_list *stack)
{
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->keepinA == 0)
			return(1);
		iterator = iterator->next;
	}
	return(0);
}


int minindex(t_list *stack)
{
	int index = stack->index;
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index < index)
			index = iterator->index;
		iterator = iterator->next;
	}
	return(index);
}

int maxindex(t_list *stack)
{
	int index = stack->index;
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index > index)
			index = iterator->index;
		iterator = iterator->next;
	}
	return(index);
}

int isstackalign(t_list *stack)
{
	t_list *iterator = stack;
	int index = minindex(stack);

	while(iterator != NULL)
	{
		if(iterator->index == index)
		{
			iterator = iterator->next;
			index++;
		}
		else
			return(0);
	}
	return(1);
}

int contain(t_list *stack, int nb)
{
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index == nb)
			return(1);
		iterator = iterator->next;
	}
	return(0);
}

int inrange(t_list *stack,int start,int end)
{
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index > start && iterator->index < end)
			return(1);
		iterator=iterator->next;
	}
	return(0);
}

int bestn(int size)
{
    int n;
    if (size <= 10)
        n = 5;
    else if (size <= 150)
        n = 8;
    else
	{
        n = 18;
	}
	return(n);
}

int checklastnode(t_list *stack)
{
	int content;
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		content = iterator->content;
		iterator = iterator->next;
	}
	return(content);
}

int findup(t_list *stack, int find, int up)
{
	t_list *iterator = stack;
	while(up > 0)
	{
		if(iterator->content == find)
			return(1);
		iterator = iterator->next;
		up--;
	}
	return(0);
}

void sortmore(t_list **stack_a, t_list **stack_b)
{
	int n = bestn(ft_lstsize(*stack_a));
	int middle = ft_lstsize(*stack_a) / 2;
	int offset = ft_lstsize(*stack_a) / n;
    int start  = ft_lstsize(*stack_a) / 2 - offset;
    int end = ft_lstsize(*stack_a) / 2 + offset;
	unsigned int up = 0;
	unsigned int down = 0;
	int search = maxindex(*stack_a);

	printf("offset: %d, start: %d, end: %d", offset, start, end);
	while(ft_lstsize(*stack_a) != 3)
	{
		if(inrange(*stack_a, start, end))
		{
			if((*stack_a)->index > start && ((*stack_a)->index < end))
				{
					if((*stack_a)->index > middle)
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
		}
	}
	ft_sort3(&*stack_a);

	while(search > 0)
	{
			if(findup(*stack_a, search, up) == 1)
			{
				search--;
				up--;
			}
			else if(findup(*stack_a, search, up) == 0 && down > 0)
			{
				rrname(stack_a, 'a');
				down--;
				search--;
			}
			if((*stack_b)->content == search)
			{
				if(up == 0)
					pname(stack_b, stack_a, 'b');
				else
				{
					while(up > 1)
					{
						rname(stack_a, 'a');
						up--;
					}
					pname(stack_b, stack_a, 'b');
					sname(stack_a, 'a');
				}
			}
			else
				if((*stack_b)->content > checklastnode(*stack_a))
				{
					while((*stack_b)->content > ((*stack_a)->content))
					{
						rname(stack_a, 'a');
						up--;
						down++;
					}	
				
				if((*stack_b)->content < ((*stack_a)->content))
					pname(stack_b, stack_a, 'b');
				}
			search--;
	}
}

/*
void sortmore(t_list **stack_a, t_list **stack_b)
	while(ft_haveatribution(*stack_a))
	{
		if((*stack_a)->keepinA == 1)
			rname(stack_a, 'a');
		else
			pname(stack_a, stack_b, 'b');
	}
	while(!(isstackalign(*stack_a)))
		rname(stack_a, 'a');
}
*/

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = NULL;
	stack_b = NULL;
	
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
	ft_index(stack_a);
//	printf("\nSTACK_A:");
//	print(stack_a);
//	printf("\n--------- Index: ");
//	printindex(stack_a);
//	printf("-----Best index Index:%d", findbestindex(stack_a,argc));
//	printf("\n---------");
//	keepatribution(stack_a, argc);

	sortmore(&stack_a, &stack_b);
/*
	printf("\n---------");
	printf("\nSTACK_A:");
	printindex(stack_a);
	printf("\n---------");
	printf("\n---------");
	printf("\n---------");
	printf("\nSTACK_B:");
	printindex(stack_b);
	printf("\n---------");
	*/
}






/*
	// IF FINAL AQUI EMBAIXO
	if (argc == 4)
	{
		ft_sort3(&stack_a);
		printf("\nSTACK A SORTADA\n");
		print(stack_a);
	}
*/


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

}
*/

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



/*
 *
 * Montar a lista encadeada com índices alocar na stack A;
 * Atribuir na lista A todos os números que estão ordenados
 * a começar por indice 1
 * Passar para a stack B todos números menos 3;
 * aplicar "ft_sort3" na stack A;
 * Verificar qual número precisamos trazer para a stack A;
 * Buscar na stack B e trazer para A;
 * A lista esta Sortada.
 */
