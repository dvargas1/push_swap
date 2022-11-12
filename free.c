/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:53:48 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/11 17:53:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeav(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	cleanall(t_list *stack_a)
{
	t_list	*tobefree;

	tobefree = stack_a;
	while (stack_a)
	{
		tobefree = stack_a->next;
		free(stack_a);
		stack_a = tobefree;
	}
	free(tobefree);
	exit(200);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(200);
}
