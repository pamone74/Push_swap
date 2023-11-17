# define N 5
int stack[N];
int top = -1;

#include <stdio.h>
void quick_sort(int *tab, int start, int end);
void push(int n)
{
    if(top == N - 1)
        printf("The stack is full\n");
    else
    {
        top ++;
        stack[top] = n;
    }
}
void pop()
{
    if(top == -1)
        printf("The stack is empty\n");
    else{
        top --;
    }
}
void peek()
{
    if(top == -1)
        printf("The stack is empty\n");
    else{
        printf("You are seeing : %d\n", stack[top]);
    }
}
void display(int *tab)
{

    quick_sort(stack, 0, top - 1);
    printf("These are the Items in your stack: \n");
    for(int i = top; i >= 0; i--)
    {
        printf("[%d]   =>  %d\n", i, tab[i]);
    }
}
void ft_swap(int *item1, int *item2)
{
    int item = *item1;
    *item1 = *item2;
    *item2 = item;
}
int partition(int *tab, int lower, int upper)
{
    int start = lower;
    int end = upper;
    int pivot = tab[start];
    while(start < end)
    {
        while(tab[start] <= pivot)
            start ++;
        while(tab[end] > pivot)
            end --;
        if(start < end)
            ft_swap(&tab[start], &tab[end]);
    }
    ft_swap(&tab[lower], &tab[end]);
    return end;
}
void quick_sort(int *tab, int start, int end)
{
    if(start < end)
    {
        int pos =  partition(tab, start, end);
        quick_sort(tab, start, pos - 1);
        quick_sort(tab, pos + 1, end);
    }
}
void ra(int *tab, int size)
{
    int first = tab[0];
    int last = tab[size];
    ft_swap(&first, &last);
}
int main(void)
{
    int x;
    int y;
    do
    {
        printf("Selecet:\n1: push\n2: pop\n3: peek\n4: Display\n5: 0 Quit\n");
        scanf("%d", &x);
        if(x == 1)
        {
            printf("Insert Your Number in stack:     ");
            scanf("%d", &y);
            printf("You have successfully inserted %d to stack\n", y);
        }
            
       switch (x)
        {
            case 1:
            push(y);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display(stack);
            break;
            case 0:
            printf("bye\n");
            break;
            default:
            printf("Invalid Input");
            break;
        }
    } while (x != 0);
    ra(stack, (sizeof(stack)/sizeof(*(stack))));
    display(stack);
    
}

void buble_sort(int *arr, int size)
{
    int i = 0;
    while(i < size)
    {
        int j  = 0;
        while(j < size - 1 - i)
        {
            if(arr[j] > arr)
        }
    }
}