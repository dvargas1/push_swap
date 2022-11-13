/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:54:30 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/09 20:22:18 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkisallnum(char **av)
{
	int		i;
	size_t	j;

	i = 1;
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
				errandfree(av);
			if (ft_isdigit(av[i][j]) == 0)
				errandfree(av);
			j++;
		}
		i++;
	}
	return (0);
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
	return (ret);
}

int	checktwins(t_list **stack, int compare, int twin)
{
	t_list	*comparator;
	t_list	*iterator;

	comparator = *stack;
	iterator = *stack;
	compare = comparator->content;
	while (comparator != NULL)
	{
		while (iterator != NULL)
		{
			if (compare == iterator->content)
				twin++;
			if (twin == 2)
				return (1);
			iterator = iterator->next;
		}
		iterator = *stack;
		comparator = comparator->next;
		if (comparator != NULL)
			compare = comparator->content;
		twin = 0;
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
		{
			freeav(av);
			cleanall(*stack_a);
			ft_error();
		}
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		i++;
	}
	if (checktwins(stack_a, 0, 0) == 1)
	{
		freeav(av);
		cleanall(*stack_a);
		ft_error();
	}
}
