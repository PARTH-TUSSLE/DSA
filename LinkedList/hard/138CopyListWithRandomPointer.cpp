/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( head == NULL ) {
            return head;
        }
        Node* temp = head;
        map<Node*, Node*>mpp;
        while ( temp ) {
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while ( temp ) {
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};

// optimal

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( head == NULL ) {
            return head;
        }
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* curr = dNode;
        while ( temp ) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        temp = head;
        while ( temp ) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
        temp = head;
        while ( temp ) {
            Node* copyNode = temp->next;
            curr->next = copyNode;
            temp->next = temp->next->next;
            temp = temp->next;
            curr = curr->next;
        }
        return dNode->next;
    }
};
