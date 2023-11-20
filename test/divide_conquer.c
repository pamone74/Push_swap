#include "header.h"
void sort_hundreds(stack_p *stack)
{
    int half = count_stack_content(stack)/2;
    stack_p * stack_b = NULL;
    while(--half)
    {
        pb(&stack, &stack_b);
    }
    half = count_stack_content(stack_b);
    while(--half)
    {
        pushToA(&stack, stack_b);
    }
}