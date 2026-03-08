#include <iostream>
#include <vector>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        public:
        Node ( int data1, Node* next1 ) {
            data = data1;
            next = next1;
        }

        public:
        Node ( int data1) {
            data = data1;
            next = nullptr;
        }
    };

Node* convertToLL ( vector<int>arr ) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for ( int i = 1; i < arr.size(); i++ ) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL ( Node* head ) {
    int len = 0;
    Node* temp = head;
    while ( temp ) {
        temp = temp->next;
        len++;
    }
    return len;
}

bool ifPresent ( Node* head, int val ) {
    Node* temp = head;
    bool isPresent = 0;
    while ( temp ) {
        if ( temp->data == val ) {
            isPresent = 1;;
        }
        temp = temp->next;
    }
    return isPresent;
}

int main() {
    Node* y = new Node(23, nullptr);
    cout << y->data << "  " << y->next << endl;
    vector<int>arr = {1,2,3,4,5,6,7,8};

    Node* head = convertToLL(arr);
    cout << head->data << endl;

    //traversal
    Node* temp = head;
    while ( temp ) {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }

    //Length
    cout << "Length : "  << lengthOfLL(head) << endl;

    cout << ifPresent(head,  1) << endl;
    return 0;
}