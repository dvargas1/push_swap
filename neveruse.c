
#include "push_swap.h"

void rr(t_list **stack_a, t_list **stack_b)
{
	if(!stack_a || !stack_b)
		return;
	char r = 'r';
	rname(stack_a,r);
	rname(stack_b,r);
	ft_putstr_fd("rrr\n", 1);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	if(!stack_a || !stack_b)
		return;
	char r = 'r';
	rrname(stack_a,r);
	rrname(stack_b,r);
	ft_putstr_fd("rrr\n", 1);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	if(!stack_a || !stack_b)
		return;
	char s = 's';
	sname(stack_a,s);
	sname(stack_b,s);
	ft_putstr_fd("ss\n", 1);
}