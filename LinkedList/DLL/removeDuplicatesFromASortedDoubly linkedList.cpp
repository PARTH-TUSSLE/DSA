/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node* temp = head;
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        while ( temp && temp->next ) {
            Node* nextNode = temp->next;
            while ( nextNode && nextNode->data == temp->data ) {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }
            temp->next = nextNode;
            if (nextNode) {
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};
