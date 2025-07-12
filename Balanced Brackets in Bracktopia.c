#include <stdio.h>
#include <string.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0'; 
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr) {
    top = -1; 
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
            if (top == -1) 
                return 0;
            char open = pop();
            if (!isMatchingPair(open, c))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar(); 

    for (int i = 0; i < T; i++) {
        char expr[MAX+1];
        fgets(expr, sizeof(expr), stdin);
        int len = strlen(expr);
        if (len > 0 && expr[len-1] == '\n')
            expr[len-1] = '\0';
        if (isBalanced(expr)) {
            printf("Balanced\n");
        } else {
            printf("Not Balanced\n");
        }
    }
    return 0;
}
