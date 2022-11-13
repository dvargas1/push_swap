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
			{
				freeav(av);
				ft_error();
			}
			if (ft_isdigit(av[i][j]) == 0)
			{
				freeav(av);
				ft_error();
			}
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
			{
				freeav(av);
				ft_error();
			}
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
}
