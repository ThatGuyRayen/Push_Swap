#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				ft_error(char *error_text);
t_node				*ft_lstnew_ps(int value);
int					exits_in_stack(t_stack *stack, int value);
void				fill_stack(t_stack *stack, int argc, char **argv);
void				swap_s(t_stack *stack);
void				push_value(t_stack *stack, int value);
void				push(t_stack *src, t_stack *dest);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

#endif
