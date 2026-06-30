#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void pop() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << front->data << endl;
    }

    void isEmpty() {
        cout << (front == nullptr ? "Yes" : "No") << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.peek();      // 10
    q.pop();
    q.peek();      // 20
}
