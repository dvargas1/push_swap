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

t_list	*ft_letsort(t_list *stack_a, int size)
{
	t_list	*stack_b;

	stack_b = NULL;
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
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	char	**av;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	av = ft_makeargs(argv);
	ft_checkisallnum(av);
	ft_checktwins(av);
	ft_loadstack(&stack_a, av);
	argc = ft_lstsize(stack_a);
	freeav(av);
	ft_index(stack_a, 0, 0);
	if (ft_issorted(&stack_a) == 0)
	{
		cleanall (stack_a);
		return (0);
	}
	stack_a = ft_letsort(stack_a, argc);
	cleanall(stack_a);
	return (0);
}
