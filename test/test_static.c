#include "header.h"

stack_p *topA(stack_p *top_A)
{
   // printf("I am here and the item is %d\n", top_A->data);
    return top_A;
}

stack_p *topB(stack_p *top_B)
{
    return top_B;
}
stack_p *HolderC(stack_p *holderC)
{
    return holderC;
}

int IsEmpty(stack_p *top_reference)
{
    return top_reference == NULL;
}

stack_p * pushA(stack_p *top_A, int item)
{
    
    stack_p *store = (stack_p *)malloc(sizeof(stack_p));
    if(!store)
        return NULL;
    store->data = item;
    store->link = topA(top_A);
    // top_A = store; 
    //printf("I am here and the item is %d\n", topA(top_A)->data);
    return store;

}
void push(stack_p **stack, int data)
{
    stack_p * newNode = (stack_p*)malloc(sizeof(stack_p));
    if(!newNode)
        return;
    newNode->data = data;
    newNode->link = *stack;
    *stack = newNode;
}
stack_p * pushB(stack_p *top_B, int item)
{
    stack_p *store = (stack_p *)malloc(sizeof(stack_p));
    if(!store)
        return NULL;
    store->data = item;
    store->link = topB(top_B);
    return store;

}
stack_p * pushH(stack_p *holderC, int item)
{
    stack_p *store = (stack_p *)malloc(sizeof(stack_p));
    if(!store)
        return NULL;
    store->data = item;
    store->link = HolderC(holderC);
    return store;
}
void peek(stack_p *top)
{
    if(IsEmpty(top))
        return;
    else
        printf("%d\n",top->data);
    
}
void display(stack_p *top)
{
    if(!IsEmpty(top))
    {
        stack_p *current = top;

        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->link;
        }

    }
    else
        return;
}
stack_p * pop(stack_p *top)
{
    if(IsEmpty(top))
        return  0;
    else
    {
        stack_p *item = top;
        top = top->link;
        free(item);
    }
    return top;
}

stack_p *create_stack(stack_p * top)
{
    top = pushA(top,10);
    top = pushA(top,1);
    top = pushA(top,0);
    return top;
}
stack_p *create_stackB(stack_p * top)
{
    top = pushB(top,10);
    return top;
}
// int main(void)
// {
    // stack_p *da = NULL;
    // stack_p *db = NULL;
    // stack_p *ptr1 = create_stack(da);
    // stack_p *ptr2 = create_stackB(db);
    // display(ptr1);
    // printf("\n");
    // display(ptr2);
    // printf("\n");
// }
// 