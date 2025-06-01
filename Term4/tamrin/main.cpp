#include <iostream>


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

int peek(stack *s) {
    return s->a[s->top];
}

int pop(stack *s) {
    if (!isEmpty(s))
        return s->a[s->top--];
    return '$';
}

void push(stack *s, int op) {
    s->a[++s->top] = op;
}

int main() {
    string vorodi;
    cin >> vorodi;
    int ivorodi = vorodi.length();
    stack *zarf = create(ivorodi);
    int zakhire[ivorodi][2];
    int zc = 0;

    for (int i = 0; i < ivorodi; ++i) {
        char shomarande = vorodi[i];
        if (shomarande == ')' && isEmpty(zarf)) {
            cout << "-1";
            return -1;
        } else if (shomarande == '(') {
            push(zarf, i + 1);
        } else if (shomarande == ')' && !isEmpty(zarf)) {
            int x = pop(zarf);
            int y = i + 1;
            zakhire[zc][0] = x;
            zakhire[zc][1] = y;
            zc++;
        }
    }
    if (!isEmpty(zarf)){
        cout << "-1";
        exit(0);
    }
    for (int i = 0; i < zc ; ++i) {
        cout<<zakhire[i][0]<<" "<<zakhire[i][1]<<endl;
    }
    return 0;
}
