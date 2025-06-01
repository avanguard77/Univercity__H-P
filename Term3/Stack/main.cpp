#include <iostream>
#include <cstring>

using namespace std;

struct stack {
    int *a;
    int top;
    unsigned c;
};

stack *create(unsigned c) {
    stack *s = new stack;
    s->top = -1;
    s->c = c;
    s->a = new int[c];
    return s;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

char peek(stack *s) {
    return s->a[s->top];
}

char pop(stack *s) {
    if (!isEmpty(s))
        return s->a[s->top--];
    return '$';
}

void push(stack *s, int op) {
    s->a[++s->top] = op;
}

bool isOperand(char a) {
    return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}

int prec(char a) {
    switch (a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void inToPost(char *a) {
    int i, k;
    stack *s = create(strlen(a));
    if (!a) {
        return;
    }
    for (i = 0, k = -1; a[i]; i++) {
        if (isOperand(a[i])) {
            a[++k] = a[i];
        } else if (a[i] == '(') {
            push(s, a[i]);
        } else if (a[i] == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                a[++k] = pop(s);
            }
            if (!isEmpty(s) && peek(s) != '(') {
                cout << "Invalid expression" << endl;
                return;
            } else {
                pop(s);
            }
        } else {
            while (!isEmpty(s) && prec(a[i]) <= prec(peek(s))) {
                a[++k] = pop(s);
            }
            push(s, a[i]);
        }
    }
    while (!isEmpty(s)) {
        a[++k] = pop(s);
    }
    a[++k] = '\0';
    cout << a << endl;
}

int main() {
    char a[] = "a*b(a*c)";
    inToPost(a);
    return 0;
}

