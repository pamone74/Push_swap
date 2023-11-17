
#include <stdio.h>
#include <stdlib.h>

// Define a stack node structure
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Function to create a new stack node
StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(StackNode** top, int data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
int pop(StackNode** top) {
    if (*top == NULL) {
        return -1; // Stack is empty
    }

    StackNode* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to insert a node into the sorted stack
void insertSorted(StackNode** sortedStack, int data) {
    StackNode* newNode = createNode(data);

    if (*sortedStack == NULL || data < (*sortedStack)->data) {
        newNode->next = *sortedStack;
        *sortedStack = newNode;
        return;
    }

    StackNode* current = *sortedStack;
    while (current->next != NULL && data > current->next->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to perform insertion sort on two stacks and store in one
void sortAndStore(StackNode** stack_A, StackNode** stack_B, StackNode** sortedStack) {
    while (*stack_A != NULL) {
        int data = pop(stack_A);
        insertSorted(sortedStack, data);
    }

    while (*stack_B != NULL) {
        int data = pop(stack_B);
        insertSorted(sortedStack, data);
    }
}

// Function to print the stack
void printStack(StackNode* top) {
    StackNode* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void freeStack(StackNode* top) {
    StackNode* current = top;
    while (current != NULL) {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    StackNode* stack_A = NULL;
    StackNode* stack_B = NULL;
    StackNode* sortedStack = NULL;

    // Push some data onto the stacks (for example)
    push(&stack_A, 12);
    push(&stack_A, 5);
    push(&stack_A, 8);

    push(&stack_B, 15);
    push(&stack_B, 3);
    push(&stack_B, 7);

    printf("Stack A before sorting: ");
    printStack(stack_A);

    printf("Stack B before sorting: ");
    printStack(stack_B);

    // Sort data from two stacks and store in one
    sortAndStore(&stack_A, &stack_B, &sortedStack);

    printf("Sorted Stack: ");
    printStack(sortedStack);

    // Free the memory allocated for the stacks
    freeStack(stack_A);
    freeStack(stack_B);
    freeStack(sortedStack);

    return 0;
}
