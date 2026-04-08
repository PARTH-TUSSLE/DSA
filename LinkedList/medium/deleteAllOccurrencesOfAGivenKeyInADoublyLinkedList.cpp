/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if ( *head_ref == NULL ) {
            return;
        }
        Node* temp = *head_ref;
        while ( temp ) {
            Node* front = temp->next;
            if ( temp->data == x ) {
                if ( temp == *head_ref ) {
                    *head_ref = (*head_ref)->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if (nextNode) nextNode->prev = prevNode;
                if (prevNode) prevNode->next = nextNode;
                temp = temp->next;
            } else {
                temp = temp->next;
            }
        }
    }
};
