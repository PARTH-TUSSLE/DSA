// brute 
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        vector<int>zeros;
        vector<int>ones;
        vector<int>twos;
        // it can be better if we just keep count variables
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        Node* temp = head;
        while ( temp ) {
            if ( temp->data == 0 ) {
                zeros.push_back(temp->data);
            } else if ( temp->data == 1 ) {
                ones.push_back(temp->data);
            } else {
                twos.push_back(temp->data);
            }
            temp = temp->next;
        }
        temp = head;
        for ( int i = 0; i < zeros.size(); i++ ) {
            temp->data = zeros[i];
            temp = temp->next;
        }
        for ( int i = 0; i < ones.size(); i++ ) {
            temp->data = ones[i];
            temp = temp->next;
        }
        for ( int i = 0; i < twos.size(); i++ ) {
            temp->data = twos[i];
            temp = temp->next;
        }
        return head;
    }
};

// optimal

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        while ( temp ) {
            if ( temp->data == 0 ) {
                zero->next = temp;
                zero = temp;
            } else if ( temp->data == 1 ) {
                one->next = temp;
                one = temp;
            }
            if ( temp->data == 2 ) {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        if ( oneHead->next ) {
            zero->next = oneHead->next;
        } else {
            zero->next = twoHead->next;
        }
        one->next = twoHead->next;
        two->next = NULL;
        return zeroHead->next;
    }
};
