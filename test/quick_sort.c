#include "header.h"
stack_p *parti_tion(stack_p *stack, stack_p *lo, stack_p *up)
{
     
    stack_p * start =  lo;
    stack_p * end =  up;
    stack_p * pivot = start;
 
    while(start->data < end->data)
    {
         printf("Here i am in partition\n");
         printf("the start->data = %d\npivot = %d\nend = %d\n", start->data, pivot->data, end->data);
        while(start->data <= pivot->data)
        {
            printf("comparing : start %d and pivot %d\n", start->data, pivot->data);
            start = start->link;
        }
            
        while(end->data > pivot->data)
         {
            printf("comparing : end %d and pivot %d\n", end->data, pivot->data);
            end = end->link;
        }
        if(start->data < end->data)
            ft_swap(&start->data, &end->data);
    }
      
    ft_swap(&lo->data, &end->data);
    return end;
}
void quick_sort(stack_p *stack, stack_p *start, stack_p *end)
{
   
    if(start->data < end->data)
    {
         printf("Here i am\n");
         
        stack_p *position = parti_tion(stack, start, end);
        quick_sort(stack, start, position);
        quick_sort(stack, position->link, end);
    }
}