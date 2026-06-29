#include <iostream>
using namespace std;

class Stack {
    int st[10];
    int top = -1;

    public:
    void push( int x ) {
        if ( top == sizeof(st) / sizeof(st[0]) - 1 ) {
            cout << "Stack is full !" << endl;
            return;
        }
        top++;
        st[top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack already empty" << endl;
            return;
        }
        top--;
    }
    void returnTop() {
        if ( top == -1 ) {
            cout << "Stack empty" << endl;
            return;
        }
        cout << st[top] << endl;
    }
    void size() {
        cout << top + 1 << endl;
    }
};

int main() {

    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.returnTop();
    s.pop();
    s.pop();
    s.returnTop();
    s.pop();
    s.returnTop();
    s.pop();
    
    return 0;
}
