#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

     Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Convert vector to DLL
Node* convertVectorToDLL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}

// Print DLL
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Delete Head
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}

// Delete Tail
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* prevNode = temp->prev;
    prevNode->next = nullptr;

    delete temp;
    return head;
}

// Delete K-th element (1-based index)
Node* deleteKthElement(Node* head, int k) {
    if (head == nullptr) return nullptr;

    if (k == 1) {
        return deleteHead(head);
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return head; // k out of bounds

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    if (prevNode != nullptr) prevNode->next = nextNode;
    if (nextNode != nullptr) nextNode->prev = prevNode;

    delete temp;
    return head;
}

void deleteNode ( Node* temp ) {
    Node* front = temp->next;
    Node* back = temp->prev;

    if ( temp->next == nullptr ) {
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;

    temp->prev = temp->next = nullptr;
    delete temp;
    return;
}

Node* insertBeforeHead ( Node* head, int data ) {
    Node* newHead = new Node( data, head, nullptr  );
    head->prev = newHead;
    return newHead;
}

Node* insertBeforeTail ( Node* head, int data ) {
    if ( head->next == nullptr ) {
        return insertBeforeHead(head, data);
    }
    Node* tail = head;
    while ( tail->next != nullptr ) {
        tail = tail->next;
    }
    Node* back = tail->prev;
    Node* newNode = new Node( data, tail, back );
    back->next = newNode;
    tail->prev = newNode;
    return head;
}

Node* insertBeforeKthElement ( Node* head ,int k, int data ) {
    Node* temp = head;
    int cnt = 0;
    while ( temp != NULL) {
        cnt++;
        if ( cnt == k ) break;
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* newNode = new Node(data, temp, back);
    back->next = newNode;
    temp->prev = newNode;
    return head;
    
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convertVectorToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);

    // head = deleteHead(head);
    // cout << "After deleting head: ";
    // printDLL(head);

    // head = deleteTail(head);
    // cout << "After deleting tail: ";
    // printDLL(head);

    // head = deleteKthElement(head, 2);
    // cout << "After deleting 2nd element: ";
    // printDLL(head);
    // deleteNode(head->next->next->next->next);
    // Node* newHead = insertBeforeHead(head, 21);
    // Node* newHead = insertBeforeTail(head, 41);
    Node* newHead = insertBeforeKthElement(head, 5, 325);
    printDLL(newHead);
    

    return 0;
}
