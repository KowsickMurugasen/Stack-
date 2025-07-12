#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[1000];
int top = -1;
int capacity;

int isFull() {
    return top == capacity - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
        printf("Pushed: %d\n", x);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:");
        // Print from bottom to top for display (as problem expects)
        for (int i = 0; i <= top; i++) {
            printf(" %d", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("%d", &capacity);
    getchar(); // consume newline after capacity input

    char line[50];
    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);

        // Remove trailing newline
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (strncmp(line, "push ", 5) == 0) {
            int val = atoi(line + 5);
            push(val);
        } else if (strcmp(line, "pop") == 0) {
            pop();
        } else if (strcmp(line, "peek") == 0) {
            peek();
        } else if (strcmp(line, "display") == 0) {
            display();
        }
    }

    return 0;
}
