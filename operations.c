#include "push_swap.h"

void	swap_s(t_stack *stack)
{
	t_node *first;
	t_node *second;
	
	if (!stack->top || !stack->top->next)
		return;
	first = stack->top;
	second = first->next;

	stack->top = second;
	first->next = second->next;
	second->next = first;	
}
