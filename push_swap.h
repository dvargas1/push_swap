/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:11 by dvargas           #+#    #+#             */
/*   Updated: 2022/10/14 09:28:15 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

//Basic Commands
void sname(t_list **stack_a, char name);
void ss(t_list **stack_a, t_list **stack_b);
void pname(t_list **stack_a, t_list **stack_b, char name);
void rrname(t_list **stack, char name);
void rname(t_list **stack, char name);

//Utilities
void print(t_list *node);
void printindex(t_list *node);
void printarr(int *print, int size);
int ft_issorted(t_list **stack);
void sortargs(int *arg, int size);
void ft_simplesort(t_list **stack_a, t_list **stack_b, int *sorted);

//Index Manipulator
void ft_index(t_list *stack);
int bestpossible(t_list *stack, int index);
int findbestindex(t_list *stack, int argc);
void keepatribution(t_list *stack, int argc);

// Sort3 and Sort5
void ft_sort3(t_list **stack_a);
void ft_sort5(t_list **stack_a, t_list **stack_b);

#endif
