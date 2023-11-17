#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#define STORE stack_t *store = (stack_t *)malloc(sizeof(stack_t));

typedef struct stack_linked
{
    int data;
    struct stack_linked * next;
}                   stack_t;
stack_t *top = 0;

void put_nbr(int n)
{
    char *str = "0123456789";
    if(n > 9)
        put_nbr(n / 10);
    write(1, &str[ n % 10], 1);
    write(1, "\n", 1);
}
int isEmpty()
{
    return top == 0;
}
void push(int item)
{
    stack_t *store = (stack_t *)malloc(sizeof(stack_t));
    store->data  = item;
    store->next  = top;
    top = store;
    
}

void pop()
{
    if(!isEmpty())
    {
        stack_t * temp = top;
        top = top->next;
        free(temp);
    }
    else 
        return;
}

void peek()
{
    if(!isEmpty())
        put_nbr(top->data);
    else
        return;
}
void display()
{
    if(!isEmpty())
    {
        while(1) 
        {
            printf("%d \n", top->data);
            top = top->next;
            if(top ==0)
                break;
        }
    }
    else
        return;
}
int main(void)
{
    
    push(10);
    push(3);
    push(2);
    pop();
    display();
}