#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stack_t
{
    int                 data;
    struct stack_t*     link;
}                   stack_p;
typedef void (*RotateFunction)(stack_p *);

/* Stack A operations */
stack_p *topA(stack_p *da);
stack_p *topB(stack_p *top_B);
stack_p * pop(stack_p *da);
stack_p * pushA(stack_p *top_A, int item);
stack_p * pushB(stack_p *top_B, int item);
void peek(stack_p *da);
void display(stack_p *da);
stack_p *create_stack(stack_p * da);
int IsEmpty(stack_p *da);
void ft_swap(int*item1, int*item2);
stack_p *parti_tion(stack_p *stack, stack_p *lo, stack_p *up);
void quick_sort(stack_p *stack, stack_p *start, stack_p *end);
int Get_data_nth(stack_p *stack, int index);
stack_p *partition(stack_p *head, stack_p *end, stack_p **newHead,
stack_p **newEnd);
void quickSort(stack_p **headRef);
int count_stack_content(stack_p *stack);
void swap_three(stack_p **stack);
void pb(stack_p **topA, stack_p **topB);
void pushToA(stack_p **A, stack_p *B);
stack_p *Get_nth_node(stack_p *stack, int i);
#endif