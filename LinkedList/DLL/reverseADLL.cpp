// brute->using stack
/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        Node* temp = head;
        stack<int>st;
        while ( temp ) {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while ( !st.empty() ) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// optimal

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        Node* curr = head;
        Node* back = NULL;
        while ( curr ) {
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;
            
            curr = curr->prev;
        }
        return back->prev;
    }
};
