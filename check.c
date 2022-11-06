/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:54:30 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/06 18:54:34 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkisallnum(char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (argv[i][j] == ' ')
				ft_error();
			if (ft_isdigit(argv[i][j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checktwins(char **argv)
{
	int	i;
	int	j;
	int	twin;

	i = 1;
	j = 0;
	twin = 0;
	while (argv[i])
	{
		j = 0;
		twin = 0;
		while (argv[j])
		{
			if ((ft_strcmp(argv[i], argv[j]) == 0))
				twin++;
			if (twin == 2)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_loadstack(t_list **stack_a, char **argv, int argc)
{
	int			i;
	long int	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
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
