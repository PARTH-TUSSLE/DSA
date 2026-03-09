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

Node* deleteHead ( Node* head ) {
    if ( head->next == NULL ) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printLL ( Node* head ) {
    if (head == NULL) {
        cout << "LL empty" << endl;
    };
    Node* temp = head;
    while ( temp ) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node* deleteTail ( Node* head ) {
    if ( head == NULL || head->next == NULL ) {
        return NULL;
    }
    Node* temp = head;
    while ( temp->next->next != nullptr ) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteK ( Node* head, int k ) {
    if ( head == NULL ) return NULL;
    if ( k == 1 ) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while ( temp ) {
        cnt++;
        if ( cnt == k ) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteVal ( Node* head, int val ) {
    if ( head == NULL ) return NULL;
    if ( head->data == val ) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    Node* temp = head;
    Node* prev = NULL;
    while ( temp ) {
        if ( temp->data == val ) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtHead ( Node* head, int data ) {
    Node* temp = new Node( data, head );
    return temp;
}

Node* insertAtTail ( Node* head, int data ) {
    if ( head == NULL ) return new Node(data);
    Node* temp = head;
    while ( temp->next ) {
        temp = temp->next;
    }
    Node* newNode = new Node(data);
    temp->next = newNode;
    return head;
}

Node* insertAtK ( Node* head, int val, int k ) {
    if ( head == NULL ) {
        if ( k == 1 ) {
            return new Node(val);
        } else return NULL;
    }
    if ( k == 1 ) {
        return new Node(val, head);
    }
    int cnt = 0;
    Node* temp = head;
    while ( temp ) {
        cnt++;
        if ( cnt == (k-1) ) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    } 
    return head;
}

Node* insertBeforeVal ( Node* head, int el, int val ) {
    if ( head == NULL ) {
        return NULL;
    }
    if ( head->data == val ) {
        return new Node(el, head);
    }
    
    Node* temp = head;
    while ( temp->next ) {
        
        if ( temp->next->data == val ) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    } 
    return head;
}

int main() {

    vector<int>arr = {4,5,6,7,8};

    Node* head = convertToLL(arr);
    cout << head->data << endl;

    // Node* newHead = deleteHead(head);

    // cout << newHead->data << endl;
    cout << "-------------" << endl;
    // printLL(newHead);

    // head = deleteTail(head);
    // printLL(head);

    // head = deleteK(head, 5);
    // printLL(head);

    // head = deleteVal(head, 6);
    // printLL(head);

    // head = insertAtHead(head, 242);
    // printLL(head);

    // insertAtTail(head, 34);
    // printLL(head);

    // head = insertAtK(head, 23, 7);
    // printLL(head);

    head = insertBeforeVal(head, 323, 8);
    printLL(head);

    return 0;
}
