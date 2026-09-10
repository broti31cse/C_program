#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push character
void push(char x) {
    stack[++top] = x;
}

// Pop character
char pop() {
    return stack[top--];
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        }
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Evaluate Postfix
int evaluatePostfix(char postfix[]) {
    int numStack[MAX];
    int numTop = -1;
    int i, a, b;

    for (i = 0; postfix[i] != '\0'; i++) {

        if (isdigit(postfix[i])) {
            numStack[++numTop] = postfix[i] - '0';
        }
        else {
            b = numStack[numTop--];
            a = numStack[numTop--];

            switch (postfix[i]) {
                case '+':
                    numStack[++numTop] = a + b;
                    break;

                case '-':
                    numStack[++numTop] = a - b;
                    break;

                case '*':
                    numStack[++numTop] = a * b;
                    break;

                case '/':
                    numStack[++numTop] = a / b;
                    break;
            }
        }
    }

    return numStack[numTop];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
