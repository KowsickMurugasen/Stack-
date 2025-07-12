#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;
void push(Stack *s, int val) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (s->top >= 0)
        return s->arr[(s->top)--];
    return -1; 
}

int peek(Stack *s) {
    if (s->top >= 0)
        return s->arr[s->top];
    return -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void insertInSortedOrder(Stack *s, int val) {
    if (isEmpty(s) || peek(s) > val) {
        push(s, val);
        return;
    }

    int temp = pop(s);
    insertInSortedOrder(s, val);
    push(s, temp);
}

void sortStack(Stack *s) {
    if (!isEmpty(s)) {
        int temp = pop(s);
        sortStack(s);
        insertInSortedOrder(s, temp);
    }
}

void printStack(Stack *s, int index) {
    if (index > s->top) return;
    printf("%d ", s->arr[index]);
    printStack(s, index + 1);
}

void readInput(Stack *s, int n) {
    if (n == 0) return;
    int x;
    scanf("%d", &x);
    push(s, x);
    readInput(s, n - 1);
}

// Main function
int main() {
    Stack s;
    s.top = -1;
    int n;
    scanf("%d", &n); 
    readInput(&s, n);
    sortStack(&s);
    printStack(&s, 0); 
    return 0;
}
