/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:59:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/08 07:49:28 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_vars
{
	int	n;
	int	middle;
	int	offset;
	int	start;
	int	end;
}	t_chunk;

//Basic Commands
void	sname(t_list **stack_a, char name);
void	pname(t_list **stack_a, t_list **stack_b, char name);
void	rrname(t_list **stack, char name);
void	rname(t_list **stack, char name);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ft_printcmd(char name, int flag);

//Utilities
void	ft_loadstack(t_list **stack_a, char **argv);
void	ft_index(t_list *stack, int i, long int j);
int		ft_issorted(t_list **stack);
int		inrange(t_list *stack, int start, int end);
int		bestn(int size);
int		findindexposition(t_list *stack, int nb);
void	sidecontrol(t_chunk *i, int sizeoflist);
void	createchunk(t_chunk *i, int sizeoflist);

// Sort Functions
void	ft_sort2(t_list **stack_a);
void	ft_sort3(t_list **stack_a);
void	ft_sort4(t_list **stack_a, t_list **stack_b);
void	ft_sort5(t_list **stack_a, t_list **stack_b);
void	ft_sortmore(t_list **stack_a, t_list **stack_b);

// Checkers && FREE
int		ft_checkisallnum(char **argv);
int		checktwins(t_list **stack, int compare, int twin);
char	**ft_makeargs(char **argv);

// FREE & Errors
void	cleanall(t_list *stack_a);
void	ft_error(void);
void	freeav(char **av);
void	errandfree(char **av);

#endif
