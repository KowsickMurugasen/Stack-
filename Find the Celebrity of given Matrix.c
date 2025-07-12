#include <stdio.h>
#define MAX 1000

int M[MAX][MAX]; 
int knows(int a, int b) {
    return M[a][b];
}

int findCelebrity(int n) {
    int stack[MAX];
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }
    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];
        if (knows(a, b)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }

    if (top == -1) return -1;
    int candidate = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
    }
    return candidate;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    int result = findCelebrity(n);
    printf("%d\n", result);
    return 0;
}
