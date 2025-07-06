#include "push_swap.h"

void	sort3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->index;
	second = stack->top->next->index;
	third = stack->top->next->next->index;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		sa(stack);
		ra(stack);
	}
	else if (second < first && first < third)
		sa(stack);
	else if (second < third && third < first)
		ra(stack);
	else if (third < first && first < second)
		rra(stack);
	else if (third < second && second < first)
	{
		sa(stack);
		rra(stack);
	}
}

int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_i;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_i = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_i)
		{
			min_i = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;
	int	rotation;
	while (a->size > 3)
	{
		pos = find_min_position(a);
		if (pos <= a->size / 2)
			while (pos--)
				ra(a);
		else
		{
			rotation = a->size - pos;
			while (rotation--)
				rra(a);
		}
		pb(a, b);
	}
	sort3(a);
	if (b->size == 2 && b->top->index < b->top->next->index)
		sb(b);
	pa(b, a);
	pa(b, a);
}
