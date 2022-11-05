/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:11 by dvargas           #+#    #+#             */
/*   Updated: 2022/11/05 16:05:06 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

//Basic Commands
void	sname(t_list **stack_a, char name);
void	pname(t_list **stack_a, t_list **stack_b, char name);
void	rrname(t_list **stack, char name);
void	rname(t_list **stack, char name);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//Utilities
void	print(t_list *node);
void	printindex(t_list *node);
void	printarr(int *print, int size);
int		ft_issorted(t_list **stack);
void	ft_index(t_list *stack, int i, int j);

// Sort3 and Sort5
void	ft_sort2(t_list **stack_a);
void	ft_sort3(t_list **stack_a);
void	ft_sort4(t_list **stack_a, t_list **stack_b);
void	ft_sort5(t_list **stack_a, t_list **stack_b);

#endif
