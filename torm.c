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

void    p_loop(looped_stack *s)
{
    int i;
    int new_i;
    int last_index;

    i = 0;
    new_i = 0;
    last_index = 0;
    while (i < s->size)
    {
        if (s->top + i > s->index_last)
            last_index = 1;
        if (last_index == 1)
            printf("\t|%d|\n", s->index_first[new_i++]);
        else
            printf("\t|%d|\n", s->top[i]);
        i++;
    }
    printf("\n\t\t\tsize\t{%d}\n", s->size);
}
/******************************************************/
