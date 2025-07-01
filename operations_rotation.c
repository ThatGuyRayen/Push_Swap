#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*node;

	if (!stack || !stack->top || !stack->top->next)
		ft_error("ERRRORRR");
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;

	node = stack->top;
	while(node->next)
		node = node->next;
	node->next = temp;	
}

/* finding last node and node before last one, detaching last node, making last node 
  to the old top
  upding the top to last node*/
void	reverse_rotate(t_stack *stack)
{
	t_node	*previous;
	t_node	*current;

	if (!stack || !stack->top || !stack->top->next)
		ft_error("ERRRRORR");
	previous = NULL;
	current = stack->top;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = stack->top;
	stack->top = current;
}
