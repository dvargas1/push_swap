/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:23:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 17:44:35 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_letsort(t_list *stack_a, int argc)
{
	if (argc - 1 < 1)
		return ;
	if (argc - 1 == 2)
		ft_sort2(&stack_a);
	if (argc - 1 == 3)
		ft_sort3(&stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_checkisallnum(argv);
	ft_checktwins(argv);
	ft_loadstack(&stack_a, argv, argc);
	ft_index(stack_a, 0, 0);
	if (ft_issorted(&stack_a) == 0)
		cleanall(stack_a);
	ft_letsort(stack_a, argc);
	if (argc - 1 == 4)
		ft_sort4(&stack_a, &stack_b);
	if (argc - 1 == 5)
		ft_sort5(&stack_a, &stack_b);
	if (argc - 1 > 5)
		ft_sortmore(&stack_a, &stack_b);
	cleanall(stack_a);
}
