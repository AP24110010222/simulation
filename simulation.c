#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline if exists
    str[strcspn(str, "\n")] = '\0';

    // Push all characters to stack
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    // Pop characters to print reversed string
    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
