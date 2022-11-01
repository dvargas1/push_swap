/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/01 09:24:32 by dvargas          ###   ########.fr       */
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

int inrange(t_list *stack, int start, int end)
{
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		if(iterator->index >= start && iterator->index <= end)
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
	int index;
	t_list *iterator = stack;

	while(iterator != NULL)
	{
		index = iterator->index;
		iterator = iterator->next;
	}
	return(index);
}

int findup(t_list *stack, int find, int up)
{
	t_list *iterator = stack;
	while(up > 0)
	{
		if(iterator->index == find)
			return(1);
		iterator = iterator->next;
		up--;
	}
	return(0);
}

int jeff(t_list *stack, int nb)
{
	t_list *iterator = stack;
	int position = 0;

	while(iterator != NULL)
	{
		if(iterator->index == nb)
			break;
		position++;
		iterator = iterator->next;
	}
		printf("nb: %d   indiceatual: %d\n", nb, iterator->index);
	return(position);
}

void sortmore(t_list **stack_a, t_list **stack_b)
{
	int sizeoflist = ft_lstsize(*stack_a);
	int n = bestn(sizeoflist);
	int middle = sizeoflist / 2;
	int offset = sizeoflist / n;
    int start  = sizeoflist / 2 - offset;
    int end = sizeoflist / 2 + offset;
	//int up = 0;
	//int down = 0;
	//int search = ft_lstsize(*stack_a);
	//int pos = 0;
// If para start e end (se start menor que 1 volta ele pra 1) mesma coisa com o topo. Dentro do else de fora
	while(ft_lstsize(*stack_a) != 3)
	{
		//RNAME ESTA COM UM GRANDE PROBLEMA QUANDO ESTÁ SOZINHO, RESOLVA ISSO PFVR.
		printf("\n\níndice no topo :%d \n valor de start:%d \n valor de end:%d \n", (*stack_a)->index, start, end);
		printf("\nStackA:");
		printindex(*stack_a);
		printf("\nSTACKB: ");
		printindex(*stack_b);
		printf("\n");
		if(inrange(*stack_a, start, end))
		{
			if((*stack_a)->index >= start && ((*stack_a)->index <= end))
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
			if(start < 1)
				start = 1;
			if(end > sizeoflist)
				end = sizeoflist;
		}
	}
}

/*
	while(*stack_b != NULL)
	{
		if((*stack_b)->index == search)
		{
			pname(stack_b, stack_a, 'a');
			search--;
		}
		else
		{
			pos = jeff(*stack_b, search);
			if(pos <= (search / 2))
			{
				while(pos > 0)
				{
					rname(stack_b, 'b');
					pos--;
				}
			}
			else
			{
				pos = search - pos + 1;
				while(pos > 0)
				{
					rrname(stack_b, 'b');
					pos--;
				}
			}
		}

	}
	

printf("VAI RODAR SORT3 \n");
	ft_sort3(&*stack_a);
printindex(*stack_a);
printf("\n");
printindex(*stack_b);
printf("search:%d    ", search);
pname(stack_a, stack_b, 'b');
printf("VAI COMEÇAR A PUTARIA \n");
	while(search > 0)
	{
		//Se estiver na stack A
		if(contain(*stack_a, search) == 1)
		{
			//Verificar se o número está na área UP (area up precisa existir)
			if(findup(*stack_a, search, up) == 1 && up > 0)
			{
				search--;
				up--;
			}
			//Verifique se é o último número da área down (area down precisa existir)
			else if((checklastnode(*stack_a) == search) && down > 0)
			{
				rrname(stack_a, 'a');
				down--;
				search--;
			}
			else
				search--;
		}
		//Se está na STACK B
		else if(contain(*stack_b, search) == 1)
		{
			//Número não está na cabeça da stack B
			if((*stack_b)->index != search)
			{
				//o Número no topo da B é maior que o número na base de down?
				if((*stack_b)->index > checklastnode(*stack_a) || down == 0)
				{
					// Se TOPO B menor que TOPO A
					if((*stack_b)->index < ((*stack_a)->index))
					{
						pname(stack_b, stack_a, '1');
						up++;
					}
					//enquanto TOPO B for maior que TOPO A 
					if(((*stack_b)->index) > ((*stack_a)->index))
					{
						rname(stack_a, 'm');
						up--;
						down++;
					}
					// enquanto TOPO B maior que último número da stack A
					if(((*stack_b)->index < checklastnode(*stack_a)) && down > 0)
					{
						rrname(stack_a, 'a');
						down--;
						up++;
					}
				}
			}
			//Número está na cabeça da stack B
			else if((*stack_b)->index == search)
			{
				//Se up estiver vazia, mande o número para o topo de A
				if(up == 0)
					pname(stack_b, stack_a, 'a');
				//Rotacione a pilha A ate ter somente 1 elemento na àrea up
				if(up > 1)
				{
					if(up > 1)
					{
						printf("%d", up);
						rname(stack_a, 't');
						up--;
						down++;
					}
					pname(stack_b, stack_a, 'a');
					sname(stack_a, 'a');
				}
			}

		}
	}
}
*/

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = NULL;
	stack_b = NULL;
	
	int i = 1;
//	int k = 0;
//	int *intv;
//	intv = malloc(sizeof(int) * argc);

	if(argc - 1 == 0)
		return (0);
/*
	while(i<argc)
	{
		intv[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
*/
	i = 1;
	while(i<argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_index(stack_a);
	printf("\nSTACK_A:");
	print(stack_a);
	printf("\n--------- Index: ");
	printindex(stack_a);

	sortmore(&stack_a, &stack_b);


	printf("\n---------");
	printf("\nSTACK_A:");
	printindex(stack_a);
	printf("\n---------");
	printf("\n---------");
	printf("\n---------");
	printf("\nSTACK_B:");
	printindex(stack_b);
	printf("\n---------");

//	free(intv);
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

		search--;
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
