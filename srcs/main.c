#include "../include/push_swap.h"

int     main(int argc, char **argv)
{
    t_stack s;

    if (argc < 2)
        error(0);
    if ((check_arg(argv)) == 1)
        error(1);
    s.stack_a = (create_stack(argc));
    if (s.stack_a == NULL)
        error(2);
    s.stack_b = (create_stack(argc));
    if (s.stack_b == NULL)
    {
        free(s.stack_a);
        error(2);
    }
    s.stack_a = (fill_stack(argv, s.stack_a));
    s.nb_a = argc - 1;
    s.nb_b = 0;
    push_swap(&s);
    int i = s.nb_a - 1;
    while (i >= 0)
    {
        printf("%d ", s.stack_a[i]);
        i--;
    }
    printf("\n");
    free(s.stack_b);
    free(s.stack_a);
    return (0);
}

// 0 et -0 = Erreur ?
// j vais dire que oui, a verif