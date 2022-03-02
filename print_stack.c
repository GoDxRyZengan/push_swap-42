#include "./include/push_swap.h"

void	print_stack(t_stack *s)
{
	int i = 0;
    while (i < (s->nb_a))
    {
        printf("%d ", s->stack_a[i]);
        i++;
    }
    i = 0;
    printf("\n");
    while (i < (s->nb_b))
    {
        printf("%d ", s->stack_b[i]);
        i++;
    }
	printf("\nnb_a :%d --- nb_b :%d\nNEXT\n", s->nb_a, s->nb_b);
}