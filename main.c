#include "stack.h"
#include <stdio.h>

int main() {
    Stack stack;
    initStack(&stack);

    printf("=== Stack Demo Program ===\\n\\n");

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("After pushing elements:\\n");
    traverseStack(&stack);

    pop(&stack);
    printf("\\nAfter popping an element:\\n");
    traverseStack(&stack);

    Node* searchResult = searchByValue(&stack, 20);
    if (searchResult != NULL) {
        printf("\\nElement with value 20 found.\\n");
    } else {
        printf("\\nElement with value 20 not found.\\n");
    }

    Node* topElement = getTop(&stack);
    if (topElement != NULL) {
        printf("Top element: %d\\n", topElement->data);
    }

    printf("\\nIs stack empty? %s\\n", isEmpty(&stack) ? "Yes" : "No");

    // FIX: Added cleanup
    printf("\\nCleaning up memory...\\n");
    destroyStack(&stack);

    printf("Program completed successfully.\\n");

    return 0;
}
