/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:54:30 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/08 07:50:59 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkisallnum(char **av)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (av[i][j] == '-')
				j++;
			if (av[i][j] == ' ')
				ft_error();
			if (ft_isdigit(av[i][j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checktwins(char **av)
{
	int	i;
	int	j;
	int	twin;

	i = 0;
	j = 0;
	twin = 0;
	while (av[i])
	{
		j = 0;
		twin = 0;
		while (av[j])
		{
			if ((ft_strcmp(av[i], av[j]) == 0))
				twin++;
			if (twin == 2)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_loadstack(t_list **stack_a, char **av)
{
	int			i;
	long int	tmp;

	i = 0;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			ft_error();
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(200);
}

void	cleanall(t_list *stack_a)
{
	t_list	*tobefree;

	tobefree = stack_a;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		free(tobefree);
		tobefree = stack_a;
	}
	exit(200);
}
