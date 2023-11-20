#include "header.h"
stack_p *getTail(stack_p *cur)
{
    while (cur != NULL && cur->link != NULL)
        cur = cur->link;
    return cur;
}
stack_p *partition(stack_p *head, stack_p *end, stack_p **newHead, stack_p **newEnd)
{
    stack_p *pivot = end;
    stack_p *prev = NULL, *cur = head, *tail = pivot;
    while(cur != pivot) {
        if(cur->data < pivot->data) {
            if((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->link;
        }
        else {
            if(prev)
                prev->link = cur->link;
            stack_p *tmp = cur->link;
            cur->link = NULL;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

//  here the sorting happens exclusive of the end node
stack_p *quickSortRecur(stack_p *head, stack_p *end)
{
    if (!head || head == end)
        return head;
    stack_p *newHead = NULL, *newEnd = NULL;
    stack_p *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        stack_p *tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;
        tmp->link = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->link = pivot;
    }
    pivot->link = quickSortRecur(pivot->link, newEnd);
    return newHead;
}
void quickSort(stack_p **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

// Driver program to test above functions















