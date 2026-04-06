/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
    Node* addOne(Node* head) {
        head = reverse(head);
        int carry = 1;
        Node* temp = head;
        while ( temp ) {
            temp->data+=carry;
            if (temp->data < 10) {
                carry = 0;
                break;
            } else {
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if ( carry == 1 ) {
            Node* newNode = new Node(carry);
            head = reverse(head);
            newNode->next = head;
            return newNode;
        } else {
            head = reverse(head);
            return head;
        }
    }
};
