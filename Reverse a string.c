#include <stdio.h>
#include <string.h>
#define MAX 1000
int main() {
    char s[MAX + 1];
    char stack[MAX];
    int top = -1;
    fgets(s, sizeof(s), stdin);
        int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    for (int i = 0; i < len; i++) {
        stack[++top] = s[i];
    }
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");
    return 0;
}
