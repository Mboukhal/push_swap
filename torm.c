#include "push_swap.h"

/************************ TORM:************************/
void p_stack(int *stack, int count)
{
    int i = 0;
    while (i < count)
    {
        printf("%d \t|%d|\n", i, stack[i]);
        i++;
    }
    printf("\n\t\t\tsize \t{%d}\n", count);
    printf("--------------------\n");
}

void    p_loop(t_stack *s)
{
    int i;

    i = s->size - 1;
    while (i >= 0)
    {
        printf("|%d|\n", s->top[i]);
        i--;
    }
    printf("\n\t\tsize\t{%d}\n", s->size);
}
/******************************************************/
