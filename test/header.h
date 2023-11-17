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

#endif