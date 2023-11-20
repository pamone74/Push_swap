#include "header.h"

// Function to swap the first 2 elements at the top of a stack
void sa(stack_p **stack, bool print)
{
    if (stack_len(*stack) > 1)
    {
        stack_p *temp = (*stack)->link;
        (*stack)->link = temp->link;
        temp->link = *stack;
        *stack = temp;

        if (print)
            printf("sa\n");
    }
}

// Function to swap the first 2 elements at the top of stack b
void sb(stack_p **stack, bool print)
{
    sa(stack, print); // sb is the same as sa in this implementation
}

// Function to swap the first 2 elements at the top of both stacks
void ss(stack_p **stackA, stack_p **stackB, bool print)
{
    sa(stackA, false);
    sa(stackB, false);

    if (print)
        printf("ss\n");
}

// Function to push the first element from stack B to stack A
void pa(stack_p **stackA, stack_p **stackB, bool print)
{
    if (*stackB != NULL)
    {
        stack_p *temp = pop(stackB);
        push(stackA, temp);

        if (print)
            printf("pa\n");
    }
}

// Function to push the first element from stack A to stack B
void pb(stack_p **stackA, stack_p **stackB, bool print)
{
    pa(stackB, stackA, print); // pb is the same as pa in this implementation
}

// Function to shift up all elements of a stack by 1 (rotate)
void ra(stack_p **stack, bool print)
{
    if (stack_len(*stack) > 1)
    {
        stack_p *temp = *stack;
        *stack = (*stack)->link;
        temp->link = NULL;
        get_last_element(*stack)->link = temp;

        if (print)
            printf("ra\n");
    }
}

// Function to shift up all elements of stack B by 1 (rotate)
void rb(stack_p **stack, bool print)
{
    ra(stack, print); // rb is the same as ra in this implementation
}

// Function to perform ra and rb simultaneously
void rr(stack_p **stackA, stack_p **stackB, bool print)
{
    ra(stackA, false);
    rb(stackB, false);

    if (print)
        printf("rr\n");
}

// Function to shift down all elements of a stack by 1 (reverse rotate)
void rra(stack_p **stack, bool print)
{
    if (stack_len(*stack) > 1)
    {
        stack_p *last = get_last_element(*stack);
        stack_p *temp = *stack;
        *stack = (*stack)->link;
        last->link = temp;
        temp->link = NULL;

        if (print)
            printf("rra\n");
    }
}

// Function to shift down all elements of stack B by 1 (reverse rotate)
void rrb(stack_p **stack, bool print)
{
    rra(stack, print); // rrb is the same as rra in this implementation
}

// Function to perform rra and rrb simultaneously
void rrr(stack_p **stackA, stack_p **stackB, bool print)
{
    rra(stackA, false);
    rrb(stackB, false);

    if (print)
        printf("rrr\n");
}

// Your existing functions
stack_p *getTail(stack_p *cur) { /* ... */ }
stack_p *partition(stack_p *head, stack_p *end, stack_p **newHead, stack_p **newEnd) { /* ... */ }
stack_p *quickSortRecur(stack_p *head, stack_p *end) { /* ... */ }
void quickSort(stack_p **headRef) { /* ... */ }

// Your main function
int main(int argc, char **argv)
{
    // ...

    // Your existing main function
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Your existing code
    a = quickSortRecur(a, getTail(a));
    // ...

    return (0);
}
