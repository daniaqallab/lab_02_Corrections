#include "stack.h"
#include <stdio.h>

int main() {
    int passed = 0, failed = 0;
    
    // Test 1: Init
    Stack s;
    initStack(&s);
    if (s.top == NULL) {
        printf("Test 1 (Init): PASS\n");
        passed++;
    } else {
        printf("Test 1 (Init): FAIL\n");
        failed++;
    }
    
    // Test 2: Push
    push(&s, 10);
    if (s.top != NULL && s.top->data == 10) {
        printf("Test 2 (Push): PASS\n");
        passed++;
    } else {
        printf("Test 2 (Push): FAIL\n");
        failed++;
    }
    
    // Test 3: Pop
    pop(&s);
    if (s.top == NULL) {
        printf("Test 3 (Pop): PASS\n");
        passed++;
    } else {
        printf("Test 3 (Pop): FAIL\n");
        failed++;
    }
    
    // Test 4: Search
    push(&s, 20);
    push(&s, 30);
    Node* found = searchByValue(&s, 20);
    if (found != NULL && found->data == 20) {
        printf("Test 4 (Search): PASS\n");
        passed++;
    } else {
        printf("Test 4 (Search): FAIL\n");
        failed++;
    }
    
    // Test 5: isEmpty
    destroyStack(&s);
    if (isEmpty(&s)) {
        printf("Test 5 (isEmpty): PASS\n");
        passed++;
    } else {
        printf("Test 5 (isEmpty): FAIL\n");
        failed++;
    }
    
    printf("\nTotal: %d | Passed: %d | Failed: %d\n", passed + failed, passed, failed);
    
    return failed;
}
