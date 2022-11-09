/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/09 20:14:37 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_letsort(t_list *stack_a,t_list *stack_b, int size)
{
	if (size < 1)
		return ;
	if (size == 2)
		ft_sort2(&stack_a);
	if (size == 3)
		ft_sort3(&stack_a);
	if (size == 4)
		ft_sort4(&stack_a, &stack_b);
	if (size == 5)
		ft_sort5(&stack_a, &stack_b);
	if (size > 5)
		ft_sortmore(&stack_a, &stack_b);
}

char	**ft_makeargs(char **argv)
{
	char	*tmp;
	char	*input;
	char	**ret;
	int		i;

	input = ft_strdup(argv[1]);
	i = 1;
	while (argv[++i])
	{
		tmp = input;
		input = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = input;
		input = ft_strjoin(tmp, argv[i]);
		free(tmp);
	}
	ret = ft_split(input, ' ');
	free(input);
	return(ret);
}

void freeav(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**av;

	if(argc == 1)
		return(0);
	stack_a = NULL;
	stack_b = NULL;
	av = ft_makeargs(argv);
	ft_checkisallnum(av);
	ft_checktwins(av);
	ft_loadstack(&stack_a, av);
	argc = ft_lstsize(stack_a);
	ft_index(stack_a, 0, 0);
	if (ft_issorted(&stack_a) == 0)
	{
		cleanall(stack_a);
		freeav(av);
		return(0);
	}
	ft_letsort(stack_a, stack_b, argc);
	cleanall(stack_a);
	freeav(av);
}
