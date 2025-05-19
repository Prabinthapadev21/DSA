//Program to convert infix expression to postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedency(char ch);

int main() {
    int i, otos = -1, ptos = -1, length;
    char infix[20], poststack[20], opstack[20];

    printf("Enter the valid infix expression: ");
    scanf("%s", infix);

    length = strlen(infix);

    for (i = 0; i < length; i++) {
        if (infix[i] == '(') {
            opstack[++otos] = infix[i]; // Push '(' to operator stack
        } 
        else if (isalpha(infix[i])) {
            poststack[++ptos] = infix[i]; // Operand goes to postfix stack
        } 
        else if (infix[i] == ')') {
            while (otos != -1 && opstack[otos] != '(') {
                poststack[++ptos] = opstack[otos--]; // Pop operators until '('
            }
            otos--; // Pop '('
        } 
        else { // Operator case
            while (otos != -1 && precedency(opstack[otos]) >= precedency(infix[i])) {
                poststack[++ptos] = opstack[otos--]; // Pop higher precedence operators
            }
            opstack[++otos] = infix[i]; // Push the current operator
        }
    }

    // Pop remaining operators
    while (otos != -1) {
        poststack[++ptos] = opstack[otos--];
    }

    poststack[++ptos] = '\0'; // Null terminate the string

    printf("Postfix Expression: %s\n", poststack);

    return 0;
}

int precedency(char ch) {
    switch (ch) {
        case '$': return 4;  // Exponentiation
        case '*':
        case '/': return 3;  // Multiplication and division
        case '+':
        case '-': return 2;  // Addition and subtraction
        default: return 1;
    }
}
