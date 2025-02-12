#include "push_swap.h"

void	free_stack(t_stack_node *stack)
{

	while(stack)
	{
		free(stack);
		stack = stack->next;
	}
}