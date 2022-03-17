#include "./include/push_swap.h"

void	print_stack(t_stack *s)
{
	int k = 0;
    printf("A :");
    while (k < (s->nb_a))
    {
        printf("%d ", s->stack_a[k]);
        k++;
    }
    printf("\n");
    k = 0;
    printf("B :");
    while (k < (s->nb_b))
    {
        printf("%d ", s->stack_b[k]);
        k++;
    }
   printf("\n");
}