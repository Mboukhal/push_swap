#include "push_swap.h"

/************************ TORM: ************************/
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
    int i = 0;
    if (s->size != 0)
    {
        while (i < s->size)
        {
            printf("|%d|\n", s->data[i]);
            i++;
        }
    }
    
    printf("\n\t\tsize\t{%d}\n", i);
}
/******************************************************/
