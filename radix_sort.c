/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:01:13 by tpandya           #+#    #+#             */
/*   Updated: 2025/07/06 19:01:14 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while ((max_i >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		size = a->size;
		while (size--)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(b, a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->top->index > a->top->next->index)
		sa(a);
	else if (a->size == 3)
		sort3(a);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
