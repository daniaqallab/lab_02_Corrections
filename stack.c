#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    if (stack != NULL) {
        stack->top = NULL;
    }
}

void destroyStack(Stack* stack) {
    if (stack == NULL) {
        return;
    }

    Node* current = stack->top;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
    stack->top = NULL;
}

void push(Stack* stack, int data) {
    if (stack == NULL) {
        fprintf(stderr, "Error: Stack is NULL\\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Error: Stack is NULL\\n");
        return;
    }

    if (stack->top == NULL) {
        fprintf(stderr, "Error: Cannot pop from empty stack\\n");
        return;
    }

    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);  // FIX: Added free() to prevent memory leak
}

Node* searchByValue(Stack* stack, int value) {
    if (stack == NULL) {
        return NULL;
    }

    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;  // FIX: Added missing increment
    }
    return NULL;
}

Node* searchByIndex(Stack* stack, int index) {
    if (stack == NULL || index < 0) {
        return NULL;
    }

    Node* current = stack->top;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

Node* getTop(Stack* stack) {
    if (stack == NULL) {
        return NULL;
    }
    return stack->top;
}

void traverseStack(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Stack is NULL\\n");
        return;
    }

    Node* current = stack->top;
    printf("Stack elements: ");
    if (current == NULL) {
        printf("(empty)");
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\\n");
}

bool isEmpty(Stack* stack) {
    if (stack == NULL) {
        return true;
    }
    // FIX: Removed free(stack->top) - this was destroying the stack!
    return stack->top == NULL;
}
