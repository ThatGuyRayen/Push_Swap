#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_i;
	int	max_bits;
	int	i;
	int	size;

	i = -1;
	max_i = a->size - 1;
	max_bits = 0;
	while((max_i >> max_bits) != 0)
		max_bits++;
	while(++i < max_bits)
	{
		size = a->size;
		while(size--)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while(b->size > 0)
			pa(b,a);
	}
}
