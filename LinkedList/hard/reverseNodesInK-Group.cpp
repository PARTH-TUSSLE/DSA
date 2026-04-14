/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* getTheKthNode ( ListNode* temp, int k ) {
        k--;
        while ( temp && k > 0 ) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseLL ( ListNode* head ) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while ( temp ) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while( temp ) {
            ListNode* kThNode = getTheKthNode(temp, k);
            if ( kThNode == NULL ) {
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLL(temp);
            if ( temp == head ) {
                head = kThNode;
            } else {
                prevNode->next = kThNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
