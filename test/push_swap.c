#include "header.h"

int Is_sorted(stack_p *stack)
{
    stack_p *current = stack;
    while(current != NULL)
    {
        stack_p *runner = current->link;
        while(runner != NULL)
        {
            if(current->data < runner->data)
                return 0;
            runner = runner->link;
        }
        current = current->link;
    }
    return 1;
}
void ft_swap(int*item1, int*item2)
{
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}
void sa(stack_p *tab)
{
        ft_swap(&tab->data, &tab->link->data);
        printf("sa\n");
}
void sb(stack_p *tab)
{
        ft_swap(&tab->data, &tab->link->data);
        printf("sb\n");
}
void ss(stack_p *stack)
{
    sa(stack);
    sb(stack);
}
int pop_and_return(stack_p **top) {
    int temp = 0;
    if (!IsEmpty(*top)) {
        stack_p *top_B = topB(*top);
        temp = (*top)->data;
        *top = pop(*top);
        return temp;
    } else
        return 0;
}
void pa(stack_p **topA, stack_p **topB) {
    if (!IsEmpty(*topB)) {
        int item = pop_and_return(topB);
        *topA = pushA(*topA, item);
        printf("pa\n");
    }
}
void pb(stack_p **topA, stack_p **topB) {
    if (!IsEmpty(*topA)) {
        int item = pop_and_return(topA);
        *topB = pushB(*topB, item);
        printf("pb\n");
    }
}
stack_p *get_stack_bottom(stack_p *stack_a)
{
    while(stack_a && stack_a->link != NULL)
    {
        stack_a = stack_a ->link;
    }
    return stack_a;
}
void rotate(stack_p **stack_a) {
    if (!IsEmpty(*stack_a) && (*stack_a)->link != NULL) {
        stack_p *temp = *stack_a;
       *stack_a  = (*stack_a)->link;
        stack_p *tail = get_stack_bottom(*stack_a);
        temp->link = NULL;
        tail->link = temp;
    } else {
        return;
    }
}

void rb(stack_p **stack_b)
{
   rotate(stack_b);
}

void ra(stack_p **stack_a)
{
   rotate(stack_a);
}
void rr(stack_p **stack_a, stack_p **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
void rra(stack_p **stack_a) {
     ra(stack_a);
     ra(stack_a);
}

void rrb(stack_p **stack_b)
{
    rb(stack_b);
    rb(stack_b);
}

void rrr(stack_p **stack_a, stack_p ** stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
int ft_atoi(char *str)
{
    int sign = 1;
    int result = 0;
    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '-')
        sign = -1;
    if(*str == ' ' || *str == '+')
        str++;
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - 48;
        str++;
    }
    return sign * result;
}
int GetN(stack_p **stack, int item)
{
    stack_p *node = *stack;
    int count = 0;
    if(!IsEmpty(node))
    {
        while(node != NULL)
        {
           // printf("Comparing %d with %d\n", node->data, item);
            if(node->data == item)
                return count;
            count ++;
            node = node->link;
        }
    }
    return 0;
}
int get_min(stack_p **stack)
{
    stack_p *temp_node = *stack;
    int min = temp_node->data;
    while(temp_node->link != NULL)
    {
        if(temp_node->link->data < min)
            min = temp_node->link->data;
        temp_node = temp_node->link;
    }
    return min;
}
int check_duplicate(stack_p *stack)
{
    stack_p * current = stack;
    while(current != NULL)
    {
        stack_p *runner = current->link;
        while(runner != NULL)
        {
            if(current->data == runner->data)
                return 1;
            runner = runner->link;
        }
        current = current->link;
    }
    return 0;
}
void swap_three(stack_p **stack)
{
    if (*stack == NULL || (*stack)->link == NULL || (*stack)->link->link == NULL) 
        return;
    int first = (*stack)->data;
    int middle = (*stack)->link->data;
    int last = (*stack)->link->link->data;
    if(Is_sorted(*stack))
    {
        ra(stack);
        sa(*stack);
        printf("sa\n");
        printf("ra\n");
        return;
    }    
    if (first > middle && middle < last && first < last) {
        sa(*stack);
        printf("sa\n");
    } else if (first > middle && middle > last) {
        sa(*stack);
        ra(stack);
        printf("sa\n");
        printf("ra\n");
    } else if (first < middle && middle > last && first < last) {
        rra(stack);
        sa(*stack);
        printf("rra\n");
        printf("sa\n");
    } else if (first  > middle && middle < last && first  > last) {
        rra(stack);
        sa(*stack);
        ra(stack);
        sa(*stack);
        printf("rra\n");
        printf("sa\n");
        printf("ra\n");
        printf("sa\n");
    } else if (first < middle && middle > last && first > last) {
        rra(stack);
        printf("rra \n");
    }
}
int get_last_element(stack_p *stack)
{
    stack_p *temp = stack;
    int last = 0;
    while(temp != NULL)
    {
        last = temp->data;
        temp = temp->link;
    }
    return last;
}
int count_stack_content(stack_p *stack)
{
    int count = 0;
    stack_p *temp = stack; // Use a temporary pointer

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}
void displayD(stack_p *stack) {
    stack_p *temp = stack;
    int count = count_stack_content(stack);

    // Create an array to store the elements
    int *elements = malloc(count * sizeof(int));
    
    // Copy elements to the array
    int i = 0;
    while (temp != NULL) {
        elements[i] = temp->data;
        temp = temp->link;
        i++;
    }

    // Print elements in ascending order

    int j = -1;
    while(j >= 0)
    {
         printf("%d ", elements[j]);
         j--;
    }

    free(elements);  // Don't forget to free the allocated memory
    printf("\n");
}
void sort_all(stack_p **stack)
{
    int flag = 1; // Initialize flag to 1 to enter the loop
    while (flag)
    {
        flag = 0;
        stack_p *temp = *stack;
        while (temp->link != NULL)
        {
            stack_p *runner = temp;
            while (runner->link != NULL)
            {
                if (runner->data > runner->link->data)
                {
                    ft_swap(&runner->data, &runner->link->data);
                    flag = 1;
                }
                runner = runner->link;
            }
            temp = temp->link;
        }
    }
}
// void InsertNth(stack_p **stack, int index, int item)
// {
    // if (*stack == NULL || index < 0)
        // return;
    // if(index == 0)
    // {
        // pushA(*stack, item);
    // }
    // else
    // {
        // stack_p *current = *stack;
        // int i = 0;
        // while(current != NULL && i < index -1)
        // {
            // current = current->link;
            // i++;
        // }
        // pushA(current, item);
    // }
        // 
// }

void InsertNth(stack_p **stack, int index, int item) {
    if (*stack == NULL || index < 0)
        return;
printf("I havvvvvvvvvvvvvvvvvvvveeeeeeeeee\n");
printf("This is the number %d and index %d\n", item, index);
    if (index == 0) {
        pushA(*stack, item);
    } else {
        stack_p *current = *stack;
        int i = 0;

        // Traverse to the node at index - 1
        while (current != NULL && i < index - 1) {
            current = current->link;
            i++;
        }

        if (current != NULL) {
            // Insert after the current node
            stack_p *newNode = (stack_p *)malloc(sizeof(stack_p));
            if (!newNode) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            newNode->link = current->link;
            current->link = newNode;
        } else {
            // Handle the case where the index is beyond the current length
            // You might want to append the item to the end or handle it as appropriate
            // For now, I'm assuming pushA appends to the end
            pushA(*stack, item);
        }
    }
}
void Insert_Nth(stack_p **stack, int index, int item) {
    if (*stack == NULL || index < 0)
        return;

    stack_p *newNode = (stack_p *)malloc(sizeof(stack_p));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = item;

    if (index == 0) {
        newNode->link = *stack;
        *stack = newNode; // Update the stack pointer to point to the new node
    } else {
        stack_p *current = *stack;
        int i = 0;

        // Traverse to the node at index - 1
        while (current != NULL && i < index - 1) {
            current = current->link;
            i++;
        }

        if (current != NULL) {
            // Insert after the current node
            newNode->link = current->link;
            current->link = newNode;
            printf("pa\n");
        } else {
            // Handle the case where the index is beyond the current length
            // You might want to append the item to the end or handle it as appropriate
            // For now, I'm assuming pushA appends to the end
            pushA(*stack, item);
            printf("pa\n");
            free(newNode); // Free the allocated memory since the item is appended
        }
    }
}
stack_p *AppendNode(stack_p **stack, int num)
{
    stack_p *current = *stack;
    if(current == NULL)
    {

    }
       // push()
}

void pushToA(stack_p **A, stack_p *B)
{
    int i;
    stack_p *tempA = *A; 
    stack_p *prev = NULL;
    int index; 
    while(B != NULL)
    {
        i = B->data;
       // printf("%d\n", i);
        tempA = *A; 
        while (tempA != NULL && i > tempA->data) {
            prev = tempA;
            tempA = tempA->link;
        }
            if (tempA != NULL) {
               if (i < tempA->data) {
                   index = GetN(A, tempA->data);
                   Insert_Nth(A, index, i);
               }
           } else {
               index = count_stack_content(*A);
               Insert_Nth(A, index, i);
           }
            B = B->link;
   }
     free(B);
}
 void sort_six(stack_p **stack) {
    if(*stack == NULL)
        return;
    stack_p *A = *stack;
    stack_p *B = NULL;
    int i;
    printf("top = %d ", pop_and_return(&A));
    sa(A);
    printf("top = %d ", pop_and_return(&A));
if(count_stack_content(A) > 3)
{
     i = -1;
    while (++i < 3)
        pb(&A, &B);
    swap_three(&B);
    display(A);
    if (count_stack_content(A) == 3) {
        swap_three(&A);
        pushToA(&A,B);
        display(A);
    }
    else if(count_stack_content(A) == 2)
    {
        if(Is_sorted(A))
            sa(A);
        pushToA(&A, B);
        display(A);
    }
}
}

void push_ten(stack_p **stack)
{
    stack_p *A = *stack;
    stack_p *B = NULL;
    int i = -1;
    //  printf("This A before anthing");
    // display(A);
    while(++i < 5)
    {
        pb(&A, &B);
        //printf("pb\n");
    }
    // sort_five(&A);
    // sort_five(&B);
    //i  = -1;
    // while (++i < 5)
    // {
        // pb(&A, &B);
        // printf("pb\n");
    // }
    // i = 0;
    // while (i < count_stack_content(B))
    // {
    //    while()
    // }
    
    //sort_all(&A);
    printf("This A after \n");
    display(A);
    printf("This B before \n");
    display(B);
}

int main(int av, char *argv[])
{
    int i = 1;
     stack_p * stack_A = NULL;
    if(av > 1)
    {
       
        stack_p * stack_B = NULL;
        while(i < av)
        {
            stack_A = pushA(stack_A, atoi(argv[i]));
            i++;
        }
        if(av == 3)
        {
            if(Is_sorted(stack_A))
            {
                sa(stack_A);
                printf("sa\n");
            }
         //display(stack_A);
            
        }
        // else if(av = 4)
        // {
            // swap_three(&stack_A);
        //   display(stack_A);
        // }
        else if(av > 3)
        {
            //printf("I am here");
            sort_six(&stack_A);
            //display(stack_A);
        }

    }

}
